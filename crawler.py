from urllib.parse import urljoin
import requests
from bs4 import BeautifulSoup as bs
import os
from htmlgen import *
from collections import defaultdict
import sys

url='https://cses.fi/problemset'
cookies={}

def download_url(s,url):
    return requests.get(url,cookies=cookies).text

def login(s):
    print('Username: ',end='')
    username=input()
    print('Password: ',end='')
    password=input()
    url='https://cses.fi/login'
    payload={'nick':username,
            'pass':password,
            }
    p=s.get(url)
    cookies['PHPSESSID']=p.cookies['PHPSESSID']
    html=p.text
    soup=bs(html,'html.parser')
    payload['csrf_token']=soup.find('input',{'name':'csrf_token'})['value']
    p=s.post(url,data=payload)
    soup=bs(p.text,'html.parser')
    if soup.find('a',{"class":"account"})["href"]=="/login":
        print('Log in failed!')
        exit(0)
    print('Logged in successfully')

class Problem:
    def __init__(self,s,probUrl):
        html=download_url(s,probUrl) 
        self.url=probUrl
        self.soup = bs(html, 'html.parser')
        self.aclink = None
        self.actime = None
        self.accode= None
        self.accodehtml = None
        self.accodelang = None
        self.title = self.soup.h1.getText()
        self.cate = self.soup.h4.getText()
        print('- Fetching: %s > %s'%(self.cate,self.title))
        for link in self.soup.find_all('a'):
            path = link.get('href')
            if path and path.startswith('/problemset/result'):
                path = urljoin(url, path)
                if not link.span: continue
                if 'full' in link.span.get('class'):
                    self.aclink=path
                    self.getSubmission(s,path)
                    print(' -> Status: Solved / %s / %s'%(self.accodelang,self.actime))
                    return
        print(' -> Status: Not Solved')
        
    def getSubmission(self,s,resultUrl):
        html=download_url(s,resultUrl)
        self.soupac=bs(html,'html.parser')
        self.actime=self.soupac.table.find_all('tr')[2].find_all('td')[1].getText()
        lang=self.soupac.table.find_all('tr')[3].find_all('td')[1].getText()
        if 'C++' in lang:
            self.accodelang='cpp'
        elif 'Py' in lang:
            self.accodelang='python'

        # Code section
        tmp=self.soupac.find('pre',{'class':'linenums'})
        self.accodehtml=tmp.string.wrap(self.soupac.new_tag('code'))
        self.accodehtml['class']="language-%s"%self.accodelang
        self.accode=tmp.getText()

def getProblems(s,urls):
    for url in urls:
        yield(Problem(s,url))

def writeToFile(filename,content):
    os.makedirs(os.path.dirname(filename), exist_ok=True)
    with open(filename,'w') as f:
        f.write(content)

def writeCodeToDirectory(problem):
    if problem.accodelang==None: return
    ext='unknown'
    if problem.accodelang=='cpp':
        ext='cpp'
    elif problem.accodelang=='python':
        ext='py'
    filename='%s/%s.%s'%(problem.cate,problem.title,ext)
    writeToFile(filename,problem.accode)

def main(argv):
    with requests.Session() as s:
        html=download_url(s,url)
        soup=bs(html,'html.parser')
        problemUrls=[]
        for link in soup.find_all('a'):
            path = link.get('href')
            if path and path.startswith('/problemset/task'):
                problemUrls.append(urljoin(url, path))

        def asking():
            # ask if want to download solution
            solFlag=False
            print("Do you want to download solution code (y/N)? ",end="")
            if input().strip().lower()=='y': solFlag=True

            # ask if want to package the solutions to an web interface (open index.html to view)
            packageFlag=False
            print("Do you want to package solution code to web interface (y/N)? ",end="")
            if input().strip().lower()=='y': packageFlag=True
            print("-------------------------------------------------------------")
            return (solFlag,packageFlag)


        # no args
        if len(argv)==1:
            login(s)
            solFlag,packageFlag=asking()
            sidebar=defaultdict(list)
            cnt=0
            for problem in getProblems(s,problemUrls):
                if not problem.accodelang: 
                    continue
                sidebar[problem.cate].append(problem.title)
                
                filename='%s/%s.html'%(problem.cate,problem.title)
                if solFlag:
                    writeCodeToDirectory(problem)
                if packageFlag:
                    writeToFile(filename,genHtmlProblem((problem.title,problem.url,str(problem.accodehtml))))
                cnt+=1
            if solFlag:
                print('-> Save code successfully')
            if packageFlag:
                writeToFile("./index.html",genHtmlIndex(sidebar))
                print('-> Generated index.html successfully')
            print("You solved %d problems"%cnt)

        # args = [problemID]
        elif len(argv)==2:
            login(s)
            probUrl='https://cses.fi/problemset/task/%s'%argv[1]
            if not probUrl in problemUrls:
                print("ProblemID not found")
                return
            solFlag,packageFlag=asking()
            problem=Problem(s,probUrl)
            if solFlag:
                writeCodeToDirectory(problem)
                print('-> Save code successfully')
            if packageFlag:
                writeToFile(filename,genHtmlProblem((problem.title,problem.url,str(problem.accodehtml))))
                print('-> Save html code successfully')
        else: printUsage()

def printUsage():
    print("""Usage:
    `python crawler.py` to download all problems
    `python crawler.py <problemID>` to download a specific problem
""")


if __name__ == "__main__":
    main(sys.argv)
