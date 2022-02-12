#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adjList;
vector<int> p;
vector<int> d;
int dfs(int curr){
	d[curr]=-2;
	int re=-1;
	for (int &v:adjList[curr]){
		if (d[v]==-2) continue; // can't reach
		int nxt;
		if (d[v]==-1){			// not tried
			nxt = dfs(v);
			if (nxt==-2) continue;	// can't reach
		}
		else nxt=d[v];				// has tried already
		if (re<nxt) {
			re=nxt;
			p[curr]=v;
		}
	}
	if (re!=-1) d[curr]=re+1;
	return d[curr];
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	adjList.assign(n,vector<int>());
	d.assign(n,-1);
	p.assign(n,-1);
	for (int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;--a;--b;
		adjList[a].push_back(b);
	}
	d[n-1]=0;
	dfs(0);
	vector<int> path;
	int y=0;
	while (y!=n-1&&y!=-1){
		path.push_back(y);
		y=p[y];
	}
	if (y==n-1){
		cout<<1+path.size()<<'\n';
		for (int &v:path) cout<<v+1<<' ';
		cout<<n;
	}
	else cout<<"IMPOSSIBLE";
	return 0;
}