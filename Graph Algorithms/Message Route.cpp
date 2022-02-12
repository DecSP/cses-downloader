# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
 
int n,m;
vector <vector<int>> adList;
vector <bool> visit;
vector<int> p;
queue <int> q;
	
bool bfs(int start,vector<int>&path){
    p.assign(n,0);
    visit.assign(n,0);
    q.push(start);
    visit[start]=true;
    bool connect=false;
	while (!q.empty()){
		int v=q.front();
        if (v==n-1) {
            connect=true;
            break;
        }
		q.pop();
		for (int &u:adList[v]){
			if (visit[u]) continue;
			visit[u]=true;
			p[u]=v;
			q.push(u);
		}
	}
    if (!connect) return false;
    int tmp=n-1;
    while (tmp!=0){
        path.push_back(tmp);
        tmp=p[tmp];
    }
    reverse(path.begin(),path.end());
    return true;
}
int main(){
	fastio;
	cin>>n>>m;
	adList.assign(n,vector<int>());
    int x,y;
	for (int i=0;i<m;++i){
		cin>>x>>y;x--;y--;
		adList[x].push_back(y);
		adList[y].push_back(x);
	}
    vector<int> path;
    if (bfs(0,path)){
        cout<<path.size()+1<<'\n';
        cout<<1;
        for (int &v:path){
            cout<<' '<<v+1;
        }
        cout<<'\n';
    }
    else cout<<"IMPOSSIBLE\n";
	return 0;
}

