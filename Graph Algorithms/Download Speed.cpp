#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
vector<vector<ll>> cap;
vector<vector<int>> adj;
vector<int> par;
int n,m;

ll bfs(){
	fill(par.begin(), par.end(),-1);
	queue<array<ll,2>> q;
	q.push({0,INF});
	while (!q.empty()){
		auto p=q.front();
		q.pop();
		for (int &v:adj[p[0]]){
			if(par[v]!=-1) continue;
			if (cap[p[0]][v]){
				par[v]=p[0];
				ll nxt=min(p[1],cap[p[0]][v]);
				if (v==n-1) return nxt;
				q.push({(ll)v,nxt});
			}
		}
	}
	return 0;
}

int main(){
	cin>>n>>m;
	cap.assign(n,vector<ll>(n,0));
	adj.assign(n,vector<int>());
	par.assign(n,-1);
	for (int i=0;i<m;++i){
		int a,b;ll c;cin>>a>>b>>c;--a;--b;
		cap[a][b]+=c;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll x,re=0;
	while (x=bfs()){
		int cur=n-1;
		while (cur!=0){
			cap[par[cur]][cur]-=x;
			cap[cur][par[cur]]+=x;
			cur=par[cur];
		}
		re+=x;
	}
	cout<<re<<'\n';
	return 0;
}