#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const ll INF = 1e18;

vector<vector<int>>adjList;
vector<int>color;
vector<int>p;
int n,m;
int dfs(int curr){
	color[curr]=1;
	for (int &v:adjList[curr]){
		if (color[v]==2) continue;
		p[v]=curr;
		if (color[v]==1) return v;
		int tmp=dfs(v);
		if (tmp!=-1) return tmp;
	}
	color[curr]=2;
	return -1;
}

void solve() {
	color.assign(n,0);
	p.assign(n,-1);
	int x=-1;
	for (int i=0;i<n;++i){
		if (color[i]) continue;
		x=dfs(i);
		if (x!=-1) break;
	}
	if (x==-1){
		cout<<"IMPOSSIBLE";
		return;
	}
	vector<int>path;
	int y=p[x];
	while (y!=x) {
		path.push_back(y);
		y=p[y];
	}
	reverse(path.begin(),path.end());
	cout<<path.size()+2<<'\n';
	cout<<x+1;
	for (int&v:path)cout<<' '<<v+1;
	cout<<' '<<x+1;
}

int main() {
	fastio;
	cin>>n>>m;
	adjList.assign(n,vector<int>());
	for (int i=0; i<m; ++i) {
		int a,b;
		cin>>a>>b;
		--a;--b;
		adjList[a].push_back(b);
	}
	solve();
	return 0;
}