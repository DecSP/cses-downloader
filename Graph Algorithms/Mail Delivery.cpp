#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
using namespace std;
vector<vector<array<int,2>>> adj;
vector<vector<bool>> vis;
int m,n;
int pre=-1;
vector<int> re;
// euler circuit	
void dfs(int cur){
    while (sz(adj[cur])){
        int u=adj[cur].back()[0],nxtj=adj[cur].back()[1],i=sz(adj[cur])-1;
        adj[cur].pop_back();
        if (vis[cur][i]) continue;
        vis[u][nxtj]=true;
        dfs(u);
    }
	re.push_back(cur);
}
int main(){
	fastio;
	cin>>n>>m;
    adj.assign(n,vector<array<int,2>>());
	for (int i=0;i<m;++i){
		int x,y;cin>>x>>y;--x;--y;
        adj[y].push_back({x,sz(adj[x])});
        adj[x].push_back({y,sz(adj[y])-1});
	}
	for (int i=0;i<n;++i){
        if (sz(adj[i])%2){
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
    }
    for (int i=0;i<n;++i){
        vis.push_back(vector<bool>(sz(adj[i]),false));
    }
    dfs(0);
    if (sz(re)!=m+1){
        cout<<"IMPOSSIBLE\n";
        exit(0);
    }
    for (auto&s:re) cout<<s+1<<' ';

}