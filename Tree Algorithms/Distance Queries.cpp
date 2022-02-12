#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
int up[(int)(2e5+1.5)][20] {};
vector<int>tin,tout,d;
int n,q,timer;

void dfs(int curr,int pre){
	tin[curr]=timer++;
	up[curr][0]=pre;
	for (int i=1;i<20;++i){
		up[curr][i]=up[up[curr][i-1]][i-1];
	}
	for (int &v:adjList[curr]){
		if (v==pre) continue;
		d[v]=d[curr]+1;
		dfs(v,curr);
	}
	tout[curr]=timer++;
}

bool is_ancestor(int par,int child){
	return tin[par]<=tin[child]&&tout[par]>=tout[child];
}

int lca(int n1,int n2){
	if (is_ancestor(n1,n2)) return n1;
	if (is_ancestor(n2,n1)) return n2;
	for (int i=19;i>=0;--i){
		if (!is_ancestor(up[n1][i],n2)) n1=up[n1][i];
	}
	return up[n1][0];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	adjList.assign(n,vector<int>());
	tin.assign(n,-1);
	tout.assign(n,-1);
	d.assign(n,-1);
	d[0]=0;
	timer=0;
	for (int i=1;i<n;++i){
		int a,b;cin>>a>>b;--a;--b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	dfs(0,0);
	for (int i=0;i<q;++i){
		int a,b;
		cin>>a>>b;--a;--b;
		cout<<d[a]+d[b]-2*d[lca(a,b)]<<'\n';
	}
	return 0;
}