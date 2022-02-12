#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll MOD = 1000000007;

struct edge {
	int to;
	ll w;
};

vector<vector<edge>> adjList;
int n,m;

int main() {
	MOD*=MOD;
	cin>>n>>m;
	adjList.assign(n,vector<edge>());
	for (int i=0; i<m; ++i) {
		int a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		adjList[a].push_back(edge({b,(ll)c}));
	}
	
	// map<ll,int> m;
	set<pair<ll,int>> m;
	vector<ll> d (n,MOD);	
	d[0]=0;

	m.insert(pair<ll,int>(0LL,0));

	while (!m.empty()) {
		int curr = m.begin()->second;
		m.erase(m.begin());

		for (edge &e: adjList[curr]) {
			if (d[e.to]>d[curr]+e.w){
				m.erase({d[e.to],e.to});
				d[e.to]=d[curr]+e.w;
				m.insert(pair<ll,int>(d[e.to],e.to));
			}
		}

	}

	for (int i=0;i<n;++i){
		if (i!=0) cout<<' ';
		cout<<d[i];
	}
	cout<<'\n';
	return 0;
}