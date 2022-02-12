#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList;
int up[(int)(2e5+1.5)][20] {};
int n,q;

void dfs(int curr,int pre){
	up[curr][0]=pre;
	for (int i=1;i<20;++i){
		if (up[curr][i-1]==-1) up[curr][i]=-1;
		else up[curr][i]=up[up[curr][i-1]][i-1];
	}
	for (int &v:adjList[curr]){
		dfs(v,curr);
	}
}

int get(int node,int pos){
	for (int i=19;i>=0;--i){
		if (node==-1) return node;
		if ((1<<i)&pos) 
			{
				node=up[node][i];
			}
	}
	return node;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	adjList.assign(n,vector<int>());
	for (int i=1;i<n;++i){
		int a;cin>>a;
		adjList[a-1].push_back(i);
	}
	dfs(0,-1);
	for (int i=0;i<q;++i){
		int a,b;
		cin>>a>>b;--a;
		int x=get(a,b);
		cout<<(x==-1?-1:x+1)<<'\n';
	}
	return 0;
}