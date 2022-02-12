# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;

int n;
vector <vector<int>> adj;
vector <bool> visit;
vector <ll> ans;
ll dfs(int v){
	ll re=0;
	for (auto u:adj[v]){
		if (visit[u]) continue;
		visit[u]=true;
		re+=dfs(u);
	}
	return ans[v]=re+1;
}

int main(){
	fastio;
	cin>>n;
	adj.assign(n,vector<int>());
	visit.assign(n,false);
	ans.assign(n,0);
	int tmp;
	for (int i=1;i<n;i++){
		cin>>tmp;
		tmp--;
		adj[tmp].push_back(i);
	}
	dfs(0);
	cout<<ans[0]-1;
	for (int i=1;i<n;i++){
		cout<<' '<<ans[i]-1;
	}
	cout<<'\n';
	return 0;
}