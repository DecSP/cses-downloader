#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll INF = 1000000007;
struct edge{
	int from;
	int to;
	ll w;
};

vector <ll> d;
vector <edge> eL;
vector<vector<int>>adjList;
int n,m;

ll solve() {
	for (int i=0;i<n-1;++i){
		for (int j=0;j<m;++j){
			if (d[eL[j].from]!=INF && d[eL[j].from]+eL[j].w<d[eL[j].to]){
				d[eL[j].to]=d[eL[j].from]+eL[j].w;
			} 
		}
	}
	vector<int> check(n);
	for (int j=0;j<m;++j){
		if (d[eL[j].from]!=INF && d[eL[j].from]+eL[j].w<d[eL[j].to]){
			check[eL[j].to]=1;
			d[eL[j].to]=d[eL[j].from]+eL[j].w;
		} 
	}
	queue<int>q,q1;
	q.push(0);
	while(!q.empty()){
		int s=q.front();
		q.pop();
		if (check[s]==2) continue;
		if (check[s]==1) q1.push(s);
		check[s]=2;
		for (int &v:adjList[s]) q.push(v);
	}
	while(!q1.empty()){
		int s=q1.front();
		if (s==n-1) return -1;
		q1.pop();
		if (check[s]==3) continue;
		check[s]=3;
		for (int &v:adjList[s]) q1.push(v);
	}
	return -d[n-1];
}

int main() {
	fastio;
	INF*=INF;
	cin>>n>>m;
	d.assign(n,INF);
	d[0]=0;
	adjList.assign(n,vector<int>());
	for (int i=0; i<m; ++i) {
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a;--b;c=-c;
		eL.push_back(edge({a,b,c}));
		adjList[a].push_back(b);
	}
	cout<<solve()<<'\n';
	return 0;
}