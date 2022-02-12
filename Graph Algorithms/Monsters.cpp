#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
ll MOD = 1000000007;

vector <string> mat;
queue <pair<int,int>> mons;
queue <pair<int,int>> you;
vector<vector<int>> dMons;
vector<vector<int>> dYou;
vector<vector<int>> path;
int n,m;

int dirx[] = {-1,1,0,0};
int diry[] = {0,0,-1,1};
char dirName[] = {'U','D','L','R'};
bool isExit(int x, int y) {
	return x==0||y==0||x==n-1||y==m-1;
}

void printPath(int x,int y){
	string p;
	while (dYou[x][y]!=0){
		int i=path[x][y];
		p.push_back(dirName[i]);
		x-=dirx[i];y-=diry[i];
	}
	reverse(p.begin(),p.end());
	cout<<p<<'\n';
}

void solve(){
	while (!mons.empty()) {
		auto v=mons.front();
		mons.pop();
		
		for (int i=0;i<4;++i){
			int newx=v.first+dirx[i], newy=v.second+diry[i];
			if (newx>=n||newx<0||newy>=m||newy<0) continue;
			if (mat[newx][newy]=='#') continue;
			if (dMons[newx][newy]!=MOD) continue;
			dMons[newx][newy] = dMons[v.first][v.second]+1;
			mons.push(make_pair(newx,newy));
		}
	}

	path=dYou;
	while (!you.empty()){
		auto v = you.front();
		you.pop();
		
		if (isExit(v.first,v.second)&&dYou[v.first][v.second] < dMons[v.first][v.second]) {
			cout<<"YES\n";
			cout<<dYou[v.first][v.second]<<'\n';
			printPath(v.first,v.second);
			return;
		}

		for (int i=0; i<4; ++i) {
			int newx=v.first+dirx[i], newy=v.second+diry[i];
			if (newx>=n||newx<0||newy>=m||newy<0) continue;
			if (mat[newx][newy]=='#') continue;
			if (dYou[newx][newy]!=MOD) continue;
			dYou[newx][newy] = dYou[v.first][v.second]+1;
			path[newx][newy] = i;
			you.push(make_pair(newx,newy));
		}
	}
	cout<<"NO\n";
}

int main() {
	fastio;
	cin>>n>>m;
	mat.assign(n,"");
	dMons.assign(n,vector<int>(m,MOD));
	dYou.assign(n,vector<int>(m,MOD));
	for (int i=0; i<n; ++i) {
		cin>>mat[i];	
		for (int j=0; j<m; ++j) {
			if (mat[i][j]=='M') {
				mons.push(make_pair(i,j));
				dMons[i][j]=0;
			}
			else if (mat[i][j]=='A') {
				you.push(make_pair(i,j));
				dYou[i][j]=0;
			}
		}
	}


	solve();
	return 0;
}