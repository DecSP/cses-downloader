# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;

int n;
int re=0;
int maxnode=0;
vector <vector<int>> mp;
vector <bool> vst;
vector<int> dep;
queue <int> q;
	
void bfs(){
	while (!q.empty()){
		int v=q.front();
		q.pop();
		for (auto u:mp[v]){
			if (vst[u])continue;
			vst[u]=true;
			dep[u]=dep[v]+1;
			if(re<dep[u]) {re=dep[u];maxnode=u;}
			q.push(u);
		}
	}
}

int main(){
	fastio;
	cin>>n;
	mp.assign(n,vector<int>());
	vst.assign(n,false);
	dep.assign(n,0);
	int x,y;
	for (int i=0;i<n-1;i++){
		cin>>x>>y;x--;y--;
		mp[x].push_back(y);
		mp[y].push_back(x);
	}
	q.push(0);
	vst[0]=true;
	bfs();
	vst.assign(n,false);
	dep[maxnode]=0;vst[maxnode]=true;
	q.push(maxnode);
	bfs();
	cout<<re<<'\n';
	return 0;
}