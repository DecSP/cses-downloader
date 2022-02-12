#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,cnt;
vector<int> coins;
vector<vector<int>> adj1,adj2;
vector<ll> coins2;
vector<bool> vis;
vector<int> ord,par;

void dfs1(int x){
	vis[x]=1;
	for (int &v:adj1[x]){
		if (!vis[v]) dfs1(v);
	}
	ord.push_back(x);
}

void dfs2(int x,const int &r){
	vis[x]=1;
	par[x]=cnt;
	for (int &v:adj2[x]){
		if (!vis[v]) dfs2(v,r);
	}
}

ll dfs(int i){
	ll re=0;
	vis[i]=true;
	for (int &v:adj2[i]){
		if (vis[v]) re=max(re,coins2[v]);
		else re=max(re,dfs(v));
	}
	return coins2[i]=re+coins2[i];
}
int main(){
	cin>>n>>m;
	coins.assign(n,0);
	adj1.assign(n,vector<int>());
	adj2.assign(n,vector<int>());
	for (int &v:coins)cin>>v;
	for (int i=0;i<m;++i){
		int a,b;cin>>a>>b;--a;--b;
		adj1[a].push_back(b);
		adj2[b].push_back(a);
	}
	vis.assign(n,false);
	for (int i=0;i<n;++i) {
		if (!vis[i]) dfs1(i);
	}
	vis.clear();vis.assign(n,false);
	par.assign(n,0);
	cnt=0;
	for (int i=n-1;i>=0;--i){
		if (!vis[ord[i]]) {
			dfs2(ord[i],ord[i]);
			++cnt;
		}
	}
	vis.clear();vis.assign(cnt,false);
	adj2.clear();adj2.assign(cnt,vector<int>());
	coins2.assign(cnt,0);
	for (int i=0;i<n;++i){
		coins2[par[i]]+=coins[i];
		for (int &v:adj1[i]) 
			if (par[i]!=par[v]) adj2[par[i]].push_back(par[v]);
	}
	ll re=0;
	for (int i=0;i<cnt;++i){
		if (vis[i]) continue;
		re=max(re,dfs(i));
	}
	cout<<re<<'\n';
	return 0;
}