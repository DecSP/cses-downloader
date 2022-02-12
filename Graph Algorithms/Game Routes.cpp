#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
int n,m;
vector<vector<int>> adjList;
vector<ll> p;

ll dfs(int curr){
	p[curr]=0;
	ll &re=p[curr];
	for (int &v:adjList[curr]){
		if (p[v]!=-1) {
			re=(re+p[v])%MOD;
			continue;
		}
		re=(re+dfs(v))%MOD;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	adjList.assign(n,vector<int>());
	p.assign(n,-1);
	p[n-1]=1;
	for (int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;--a;--b;
		adjList[a].push_back(b);
	}
	cout<<dfs(0);
	return 0;
}