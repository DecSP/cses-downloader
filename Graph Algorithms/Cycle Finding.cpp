#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const ll INF = 1e18;
struct edge{
	int a,b;
	ll w;
};

vector<edge> eL;
vector<int> p;
vector<ll> d;
vector<bool> check;
int n,m,x;

bool solve(int root){
	d.assign(n,INF);
	d[root]=0;
	for (int i=0;i<n;++i)
	{	
		x=-1;
		for (edge &e:eL){
			if (d[e.a]==INF) continue;
			if (d[e.b]>d[e.a]+e.w){
				x=e.b;
				::check[x]=true;
				d[e.b]=d[e.a]+e.w;
				p[e.b]=e.a;
			}
		}
		if (x==-1) return false;
	}
	return true;
}

int main(){
	// fastio;
	cin>>n>>m;
	p.assign(n,-1);
	::check.assign(n,false);
	for (int i=0;i<m;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		--a;--b;
		eL.push_back({a,b,c});
	}
	for (int i=0;i<n;++i){
		if (::check[i]) continue;
		if (solve(i)){
			cout<<"YES\n";
			vector<bool> check(n);
			vector<int> path;
			while(true){
				if (check[x]) break;
				check[x]=true;
				x=p[x];
			}
			int y=p[x];
			while(y!=x){
				path.push_back(y);
				y=p[y];
			}
			reverse(path.begin(),path.end());
			cout<<x+1;
			for (int &v:path) cout<<' '<<v+1;
			cout<<' '<<x+1;
			cout<<'\n';
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
