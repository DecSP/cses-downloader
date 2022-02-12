#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;

vector<string> s;
int n,m;
int dirx[]={-1,1,0,0};
int diry[]={0,0,-1,1};
char dir[]={'U','D','L','R'};

bool bfs(pair<int,int> curr,vector<pair<int,char>> & path){
    queue<pair<int,int>> q;
    q.push(curr);
    s[curr.first][curr.second]='#';
    while (!q.empty()){
        curr=q.front();
        q.pop();
        for (int i=0;i<4;++i){
            pair<int,int>nxt={curr.first+dirx[i],curr.second+diry[i]};
            if (nxt.first>=n||nxt.first<0||nxt.second>=m||nxt.second<0) continue;
            if (s[nxt.first][nxt.second]=='#') continue;
            path[nxt.first*m+nxt.second]={curr.first*m+curr.second,dir[i]};
            if (s[nxt.first][nxt.second]=='B') return true;
            q.push(nxt);
            s[nxt.first][nxt.second]='#';
        }
    }
    return false;
}

void solve(){
    cin>>n>>m;
    s.assign(n,"");
    pair<int,int>A,B;
    for (int i=0;i<n;++i) {
        cin>>s[i];
        for (int j=0;j<m;++j){
            if (s[i][j]=='A') A={i,j};
            if (s[i][j]=='B') B={i,j};
        }
    }
    vector<pair<int,char>> path(n*m);

    if (bfs(A,path)) {
        cout<<"YES\n";
        string pathTo;
        while (B!=A) {
            auto p = path[B.first*m+B.second];
            pathTo.push_back(p.second);
            B={p.first/m,p.first%m};
        }
        reverse(pathTo.begin(),pathTo.end());
        cout<<pathTo.size()<<'\n';
        cout<<pathTo<<'\n';
    }
    else{
        cout<<"NO\n";
    }
}


int main()
{
    // fastio;
    solve();
	return 0;
}

