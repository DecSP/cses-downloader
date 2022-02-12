#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll INF = 1000000007;
struct edge{
	int to;
	ll w;
};

vector <pair<ll,ll>> d;
vector<vector<edge>>adjList;
int n,m;

ll solve() {
	set <array<ll,3>> s;
	s.insert({0,0,0});
	while (!s.empty()){
		int from=(*(s.begin()))[2];
		s.erase(s.begin());
		for (edge &e:adjList[from]){
			bool flag=false;
			array<ll,3> toDel={d[e.to].first,d[e.to].second,e.to};
			if (d[e.to].first>d[from].first+e.w){
				flag=true;
				d[e.to].first=d[from].first+e.w;
			}
			if(d[e.to].second>min(d[from].first+e.w/2,d[from].second+e.w)){
				flag=true;
				d[e.to].second=min(d[from].first+e.w/2,d[from].second+e.w);
			}
			if (flag){
				s.erase(toDel);
				s.insert({d[e.to].first,d[e.to].second,e.to});
			}
		}
	}
	return d[n-1].second;
}

int main() {
	fastio;
	INF*=INF;
	cin>>n>>m;
	d.assign(n,{INF,INF});
	d[0]={0,0};
	adjList.assign(n,vector<edge>());
	for (int i=0; i<m; ++i) {
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a;--b;
		adjList[a].push_back(edge({b,c}));
	}
	cout<<solve()<<'\n';
	return 0;
}