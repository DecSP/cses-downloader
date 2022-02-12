#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1e18;
const ll MOD=1000000007;

struct edge{
	int to;
	ll w;
};
int n,m;
vector<vector<edge>> adjList;
vector<pair<ll,int>> d;
int mn,mx;

void solve(){
	d[0]={0,1};
	set <pair<ll,int>> s;
	vector<pair<int,int>> dis(n,{-1,-1});
	dis[0]={0,0};
	s.insert({0,0});
	while (!s.empty()) {
		auto p = *(s.begin());
		s.erase(s.begin());
		for (edge &e:adjList[p.second]){
			ll nw=p.first+e.w;
			if (d[e.to].first>nw) {
				s.erase({d[e.to].first,e.to});
				d[e.to]={nw,d[p.second].second};
				s.insert({d[e.to].first,e.to});
				
				auto disFrom=dis[p.second];				
				dis[e.to]={disFrom.first+1,disFrom.second+1};
			}
			else if (d[e.to].first==nw) {
				d[e.to].second=(d[e.to].second+d[p.second].second)%MOD;
				auto disFrom=dis[p.second];				
				dis[e.to]={min(disFrom.first+1,dis[e.to].first),max(disFrom.second+1,dis[e.to].second)};
			}
		}
	}
	mn=dis[n-1].first;mx=dis[n-1].second;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	adjList.assign(n,vector<edge>());
	d.assign(n,{INF,1});
	for (int i=0;i<m;++i){
		int a,b;ll c;
		cin>>a>>b>>c;--a;--b;
		adjList[a].push_back(edge({b,c}));
	}
	solve();
	cout<<d[n-1].first<<' '<<d[n-1].second<<' '<<mn<<' '<<mx<<'\n';
	return 0;
}