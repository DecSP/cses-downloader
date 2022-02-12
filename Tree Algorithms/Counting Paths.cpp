#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> tin,tout;
int n,q,timer;

void dfs(int curr, int p){
	tin[curr]=timer++;
	up[curr][0]=p;

	for (int i=1;i<20;++i){
		up[curr][i]=up[up[curr][i-1]][i-1];
	}

	for (int&v:adj[curr]){
		if (v==p) continue;
		dfs(v,curr);
	}
	tout[curr]=timer++;
}

bool is_ancestor(int x, int y) {
	return tin[x]<=tin[y] && tout[x]>=tout[y];
}

int lca(int x,int y){
	if (is_ancestor(x,y)) return x;
	if (is_ancestor(y,x)) return y;

	for (int i=19;i>=0;--i){
		int tmp=up[x][i];
		if (is_ancestor(tmp,y)) continue;
		x=tmp;
	}

	return up[x][0];
}

void dfs1(vector<int>&treeVal,int curr, int p){
	for (int&v:adj[curr]){
		if (v==p) continue;
		dfs1(treeVal,v,curr);
		treeVal[curr]+=treeVal[v];
	}
}


int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	adj.assign(n,vector<int>());
	for (int i=0;i<n-1;++i){
		int x,y;cin>>x>>y;--x;--y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	timer=0;
	tin.assign(n,0);
	tout.assign(n,0);
	up.assign(n,vector<int>(20,0));
	dfs(0,0);
	vector<int> treeVal(n);
	for (int i=0;i<q;++i){
		int a,b;cin>>a>>b;--a;--b;
		int l=lca(a,b);
		if (l!=0) treeVal[up[l][0]]-=1;
		treeVal[l]-=1;
		treeVal[a]+=1;
		treeVal[b]+=1;
	}
	dfs1(treeVal,0,0);
	for (int i=0;i<n;++i){
		if (i!=0) cout<<' ';
		cout<<treeVal[i];
	}
	cout<<'\n';
	return 0;
}