# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
 
int n;
int maxnode[3];
vector <vector<int>> mp;
vector <bool> vst;
vector<int> dep;
vector<int> depReal[2];
	
int bfs(int k,int start,int mxnum){
    vector<int>*depAddr;
    if (k<0)depAddr=&dep;
    else depAddr=&depReal[k];
    vector<int>&dep=*depAddr;
    dep.assign(n,0);
    vst.assign(n,false);
    queue <int> q;
    q.push(start);
    dep[start]=0;
    vst[start]=true;

    int re=0;
	while (!q.empty()){
		int v=q.front();
		q.pop();
		for (int & u:mp[v]){
			if (vst[u])continue;
			vst[u]=true;
			dep[u]=dep[v]+1;
			if(re<dep[u]) {
                re=dep[u];
                maxnode[mxnum]=u;
            }
			q.push(u);
		}
	}
    return re;
}
 
int main(){
	fastio;
	cin>>n;
	mp.assign(n,vector<int>());
	int x,y;
	for (int i=0;i<n-1;i++){
		cin>>x>>y;x--;y--;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
    bfs(-1,0,0);
    bfs(0,maxnode[0],1);
    bfs(1,maxnode[1],2);
    for (int i=0;i<n;++i) {
        if (i!=0) cout<<' ';
        cout<<max(depReal[0][i],depReal[1][i]);
    }
    cout<<'\n';
	return 0;
}

