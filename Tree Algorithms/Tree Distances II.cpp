# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
 
int n;
vector <vector<int>> adList;
vector <bool> visit;
vector<pair<ll,ll>> d;

pair<ll,ll> dfs(int curr){
    ll numnode=1,val=0;
    for (int &v:adList[curr]){
        if (visit[v]) continue;
        visit[v]=true;
        pair<ll,ll>tmp=dfs(v);
        numnode+=tmp.first;
        val+=tmp.first+tmp.second;
    }
    return d[curr]={numnode,val};
}

void dfs2(int curr) {
    for (int &v:adList[curr]) {
        if (visit[v]) continue;
        visit[v]=true;
        d[v].second=d[curr].second-2*d[v].first+n;
        dfs2(v);
    }
} 

int main(){
	fastio;
	cin>>n;
	adList.assign(n,vector<int>());
    d.assign(n,{0,0});
    visit.assign(n,0);
	int x,y;
	for (int i=0;i<n-1;i++){
		cin>>x>>y;x--;y--;
		adList[x].push_back(y);
		adList[y].push_back(x);
	}
    visit[0]=true;
    dfs(0);
    visit.assign(n,false);
    visit[0]=true;
    dfs2(0);
    for (int i=0;i<n;++i){
        if (i!=0) cout<<' ';
        cout<<d[i].second;
    }
    cout<<'\n';
	return 0;
}

