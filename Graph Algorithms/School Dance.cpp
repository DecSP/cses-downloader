#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
vector<vector<ll>> cap;
vector<vector<int>> adj;
vector<int> scut;
vector<int> par;
int n,m,k;

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
				if (v==n+m+1) return true;
				q.push(v);
			}
		}
	}
	return false;
}

int main(){
	cin>>n>>m>>k;
	cap.assign(n+m+2,vector<ll>(n+m+2,0));
	adj.assign(n+m+2,vector<int>());
	par.assign(n+m+2,-1);
	vector<array<int,2>> kar;
	for (int i=0;i<k;++i){
		int a,b;cin>>a>>b;b+=n;
		if (cap[a][b]) continue;
		cap[a][b]+=1;
		adj[a].push_back(b);
		adj[b].push_back(a);
		kar.push_back({a,b});
	}
	for (int i=1;i<=n;++i) {
		cap[0][i]+=1;
		adj[0].push_back(i);
		adj[i].push_back(0);
	}
	for (int i=n+1;i<=n+m;++i) {
		cap[i][n+m+1]+=1;
		adj[n+m+1].push_back(i);
		adj[i].push_back(n+m+1);
	}
	int re=0;
	while (bfs()){
		re+=1;
		int cur=n+m+1;
		while (cur!=0){
			cap[par[cur]][cur]-=1;
			cap[cur][par[cur]]+=1;
			cur=par[cur];
		}
	}
	cout<<re<<'\n';
	for (auto &p:kar){
		if (!cap[p[0]][p[1]]) {
			cout<<p[0]<<' '<<p[1]-n<<'\n';
		}
	}
	return 0;
}