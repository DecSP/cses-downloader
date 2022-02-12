#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<array<int,3>>seg;
int n,timer;
vector<int> col;
vector<int> ncol;
vector<int> ans;
vector<int> F;
map<int,int> m;

void dfs(int cur,int par){
	seg[cur][1]=timer++;
	ncol[timer-1]=col[cur];
	for(int &v:adj[cur]){
		if (v==par)continue;
		dfs(v,cur);
	}
	seg[cur][0]=timer-1;
}
void increase(int pos, int val){
	for (int i=pos;i<n;i=i|(i+1)){
		F[i]+=val;
	}
}
int sum1(int pos){
	int re=0;
	for (int i=pos;i>=0;i=(i&(i+1))-1){
		re+=F[i];
	}
	return re;
}
int sum(int l,int r){
	return sum1(r)-sum1(l-1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n;
	col.assign(n,0);
	ans.assign(n,0);
	adj.assign(n,vector<int>());
	for (int&v:col)cin>>v;
	for (int i=0;i<n-1;++i){
		int a,b;cin>>a>>b;--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	timer=0;
	seg.assign(n,array<int,3>());
	ncol.assign(n,0);
	for (int i=0;i<n;++i){
		seg[i][2]=i;
	}
	dfs(0,0);
	sort(seg.begin(), seg.end());

	F.assign(n,0);
	int currend=-1;
	for (auto &ar:seg){
		while (currend<ar[0]){
			++currend;
			increase(currend,1);
			int x=m[ncol[currend]];
			if (x!=0) increase(x-1,-1);
			m[ncol[currend]]=currend+1;
		}
		ans[ar[2]]=sum(ar[1],ar[0]);
	}
	for (int &v:ans)cout<<v<<' ';
	cout<<'\n';
	return 0;
}