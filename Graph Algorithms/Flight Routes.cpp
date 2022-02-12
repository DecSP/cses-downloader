#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const ll INF = 1e18;
struct edge{
	int to;
	ll w;
};

vector<vector<edge>>adjList;
int n,m,k;

void solve() {
	multiset <array<ll,2>> s;
	vector<multiset<ll>> D(n);
	s.insert({0,0});
	D[0].insert(0);
	for (int i=0;i<n;++i) D[i].insert(INF);
	while (!s.empty()){
		array<ll,2> p=(*(s.begin()));
		int cur=p[1];
		ll dfrom=p[0];
		s.erase(s.begin());
		for (edge &e:adjList[cur]){
			if (*(prev(D[e.to].end()))>dfrom+e.w){
				if (D[e.to].size()==k) {
					ll toDel=*prev(D[e.to].end());
					D[e.to].erase(prev(D[e.to].end()));
					if (toDel!=INF) s.erase(s.find({toDel,e.to}));
				}
				D[e.to].insert(dfrom+e.w);
				s.insert({dfrom+e.w,e.to});
			}
		}
	}
	for(ll v:D[n-1]) cout<<v<<' ';
}

int main() {
	fastio;
	cin>>n>>m>>k;
	adjList.assign(n,vector<edge>());
	for (int i=0; i<m; ++i) {
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a;--b;
		adjList[a].push_back(edge({b,c}));
	}
	solve();
	return 0;
}