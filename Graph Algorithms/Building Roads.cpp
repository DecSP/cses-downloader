# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002
using namespace std;
int n, m;
vector<vector<int>> adList; 
vector<bool> visited;
int cnt;
void dfs(int x) {
    visited[x]=true;
    for (int v:adList[x]) {
        if (visited[v]) continue;
        dfs(v);
    }
}
int main()
{
    fastio;
    cin>>n>>m;
    adList.assign(n,vector<int>());
    visited.assign(n,false);
    for (int i=0;i<m;++i){
        int x,y;
        cin>>x>>y;--x;--y;
        adList[x].push_back(y);
        adList[y].push_back(x);
    }
    vector<pair<int,int>> ls;
    for (int i=0;i<n;++i) {
        if (visited[i]) continue;
        if (i>0) ls.push_back({i-1,i}); 
        dfs(i);
    }
    cout<<ls.size()<<'\n';
    for (auto p:ls) cout<<p.first+1<<' '<<p.second+1<<'\n';
    return 0;
}