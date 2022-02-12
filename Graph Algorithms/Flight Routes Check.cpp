#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
int n,m;
vector<vector<int>> g1,g2;
vector<int> p;
vector<int> order;
int cnt;

void dfs1(int curr){
	p[curr]=1;
	for (int &v:g1[curr]){
		if (p[v]) continue;
		dfs1(v);
	}
	order.push_back(curr);
}


void dfs2(int curr){
	p[curr]=2;
	for (int &v:g2[curr]){
		if (p[v]==2) continue;
		dfs2(v);
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	g1.assign(n,vector<int>());
	g2.assign(n,vector<int>());
	for (int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;--a;--b;
		g1[a].push_back(b);
		g2[b].push_back(a);
	}
	p.assign(n,0);
	for (int i=0;i<n;++i){
		if (p[i]) continue;
		dfs1(i);
	}
	cnt=0;
	for (int i=n-1;i>=0;--i){
		if (p[order[i]]==2) continue;
		dfs2(order[i]);
		++cnt;
		if (cnt>1) {
			cout<<"NO\n";
			cout<<order[i]+1<<' '<<order[i+1]+1<<'\n';
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}