#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;
vector <vector<int>> adjList;
vector <int> visited;
int re;

bool cntEdges(int curr){
    visited[curr]=1;
    bool check=false;
    for (int &v:adjList[curr]){
        if (visited[v])continue;
        check|=cntEdges(v);
    }
    re+=check;
    return !check;
}

void solve() {
    int n;
    cin>>n;
    adjList.assign(n,vector<int>());
    visited.assign(n,0);
    int x,y;
    while (cin>>x>>y) {
        --x;--y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    re=0;
    cntEdges(0);
    cout<<re<<'\n';
}
int main()
{
    fastio;
    solve();
	return 0;
}