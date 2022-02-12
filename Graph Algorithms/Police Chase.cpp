#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
vector<vector<ll>> cap;
vector<vector<int>> adj;
vector<int> scut;
vector<int> par;
int n,m;

bool bfs(){
	fill(par.begin(), par.end(),-1);
	queue<int> q;
	q.push(0);
	par[0]=0;
	while (!q.empty()){
		int p=q.front();
		q.pop();
		for (int &v:adj[p]){
			if(par[v]!=-1) continue;
			if (cap[p][v]){
				par[v]=p;
				if (v==n-1) return true;
				q.push(v);
			}
		}
	}
	return false;
}
void dfs(int cur){
	par[cur]=1;
	scut.push_back(cur);
	for (int&v:adj[cur]){
		if (par[v]==1) continue;
		if (cap[cur][v]) dfs(v);
	}
}
int main(){
	cin>>n>>m;
	cap.assign(n,vector<ll>(n,0));
	adj.assign(n,vector<int>());
	par.assign(n,-1);
	for (int i=0;i<m;++i){
		int a,b;cin>>a>>b;--a;--b;
		cap[a][b]+=1;
		cap[b][a]+=1;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int re=0;
	while (bfs()){
		re+=1;
		int cur=n-1;
		while (cur!=0){
			cap[par[cur]][cur]-=1;
			cap[cur][par[cur]]+=1;
			cur=par[cur];
		}
	}
	fill(par.begin(), par.end(),-1);
	dfs(0);
	cout<<re<<'\n';
	for (int &x:scut){
		for (int &v:adj[x]){
			if (par[v]==1) continue;
			if (!cap[x][v]) {
				cout<<x+1<<' '<<v+1<<'\n';
			}
		}
	}
	return 0;
}