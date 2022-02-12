def C(s,i=0):
	r,c,n=0,int(s[i]),len(s)-1
	if i:c-=s[i-1]<s[i]
	else:r+=(9**n-1)//8
	r+=c*9**(n-i)
	if i<n and (i==0 or s[i]!=s[i-1]):r+=C(s,i+1)
	return r
n,m=input().split()
print(C(str(int(m)+1))-C(n))