#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> adjList;
vector<int> color;
vector<int> path;

bool dfs(int curr){
	color[curr]=1;
	for(int &v:adjList[curr]){
		if (color[v]==2) continue;
		if (color[v]==1 || dfs(v)) return true;
	}
	color[curr]=2;
	path.push_back(curr);
	return false;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	adjList.assign(n,vector<int>());
	color.assign(n,0);
	for (int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;--a;--b;
		adjList[a].push_back(b);
	}
	for (int i=0;i<n;++i){
		if (color[i]) continue;
		if (dfs(i)) {
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	for (int i=n-1;i>=0;--i) cout<<path[i]+1<<' ';
	return 0;
}