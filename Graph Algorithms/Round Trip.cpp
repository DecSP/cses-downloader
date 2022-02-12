# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
 
int n,m;
vector <vector<int>> adList;
vector <bool> visit;
vector <bool> marked;
vector<int> path;
	
bool dfs(int curr, vector<int>&eulerPath,int p){
    marked[curr]=true;
    eulerPath.push_back(curr);
    for (int &v:adList[curr]) {
        if (visit[v]) {
            if (p!=v&&marked[v]) {
                path.push_back(v);
                int eusz=eulerPath.size();
                int tmp=eusz-1;
                while (eulerPath[tmp]!=v){
                    path.push_back(eulerPath[tmp]);
                    --tmp;
                }
                path.push_back(v);
                return true;
            }
            continue;
        }
        visit[v]=true;
        if (dfs(v,eulerPath,curr)) return true;
    }
    marked[curr]=false;
    eulerPath.pop_back();
    return false;
}
int main(){
	fastio;
	cin>>n>>m;
	adList.assign(n,vector<int>());
    visit.assign(n,0);
    marked.assign(n,0);
    int x,y;
	for (int i=0;i<m;++i){
		cin>>x>>y;x--;y--;
		adList[x].push_back(y);
		adList[y].push_back(x);
	}
    vector<int>eulerPath;
    for (int start=0;start<n;++start){
        if (visit[start]) continue;
        visit[start]=true;
        if (dfs(start,eulerPath,-1)) {
                cout<<path.size()<<'\n';
                for (int i=0;i<path.size();++i) {
                    if (i!=0) cout<<' ';
                    cout<<path[i]+1;
                }
                cout<<'\n';
                return 0;
        }
    }
    cout<<"IMPOSSIBLE\n";

	return 0;
}

