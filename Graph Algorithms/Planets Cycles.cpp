#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,timer,timer1;
vector<int> p,tin,tout;
vector<array<int,3>> idx;
vector<vector<int>> l,up,adjList;

void genLine(int x){
	vector<int> v;
	while (idx[x][0]>0){
		v.push_back(x);
		idx[x][0]=-2;
		x=p[x];
	}
	if (idx[x][0]!=0) x=-1;
 	reverse(v.begin(),v.end());
 	for (int& c:v){
 		if (p[c]!=x) adjList[p[c]].push_back(c);
 		else adjList[l[idx[x][1]][0]].push_back(c);
 	}

}

void genCycle(int x){
	int pos=l.size();
	int turtle=p[x], rabbit=p[p[x]];
	while (turtle!=rabbit){
		turtle=p[turtle];
		rabbit=p[p[rabbit]];
	}
	int y=x;
	
	while (y!=turtle){
		y=p[y];
		turtle=p[turtle];
	}

	l.push_back({y});
	vector<int> &cycle=l[pos];
	idx[y]={0,pos,0};
	int y1=p[y];
	int tmp=1;
	while (y1!=y) {
		idx[y1]={0,pos,tmp++};
		cycle.push_back(y1);
		y1=p[y1];
	}

 	genLine(x);
}

void merge(int x){
	idx[x][0]=timer;
	int tmp=p[x];
	while (idx[tmp][0]==-1){
		idx[tmp][0]=timer;
		tmp=p[tmp];
	}
	int a=idx[tmp][0];
	if (a==timer) genCycle(x);
	else genLine(x);
	++timer;
}

void dfs(int x,int pre){
	tin[x]=timer1++;
	up[x][0]=pre;
	for (int i=1;i<20;++i)
		up[x][i]=up[up[x][i-1]][i-1];

	for (int &c:adjList[x])	dfs(c,x);
	tout[x]=timer1++;
}

bool is_ancestor(int x,int y){
	return tin[x]<=tin[y]&&tout[x]>=tout[y];
}

int get(int x){
	int &a=idx[x][0],&b=idx[x][1];
	if (a==0)
		return l[b].size();
			
	int re=0;
	for (int i=19;i>=0;--i){
		if (idx[up[x][i]][0]==0)continue;
		x=up[x][i];
		re+=(1<<i);
	}
	x=p[x];
	++re;
	return re+get(x);
}

void solve(){
	idx.assign(n,{-1,-1,-1});
	up.assign(n,vector<int>(20,-1));
	adjList.assign(n,vector<int>());
	tin.assign(n,-1);
	tout.assign(n,-1);
	timer=timer1=1;
	for (int i=0;i<n;++i){
		if (idx[i][0]==-1) merge(i);
	}
	for (int i=0;i<n;++i){
		if (idx[i][0]==0&&idx[i][2]==0) dfs(i,i);
	}
	for (int i=0;i<n;++i){
		cout<<get(i)<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n;
	p.assign(n,-1);
	for (int i=0;i<n;++i){
		cin>>p[i];
		--p[i];
	}
	solve();
	return 0;
}