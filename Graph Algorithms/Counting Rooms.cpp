# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
vector<string> mp;
vector <vector<bool>> vst;

int n,m;
int dirx[]={-1,1,0,0};
int diry[]={0,0,-1,1};
void dfs(int u,int v){
	if (u<0||u>=n||v<0||v>=m) return;
	if (vst[u][v]||mp[u][v]=='#')return;
	vst[u][v]=true;
	for (int i=0;i<4;i++){
		dfs(u+dirx[i],v+diry[i]);
	}
}
int main(){
	fastio;
	cin>>n>>m;
	mp.assign(n,"");
	vst.assign(n,vector<bool>(m,false));
	int re=0;
	for (int i=0;i<n;i++)cin>>mp[i];
	for (int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if (mp[i][j]=='.'&&!vst[i][j]){
				dfs(i,j);
				re++;
			}
	}
	cout<<re<<endl;
	return 0;
}