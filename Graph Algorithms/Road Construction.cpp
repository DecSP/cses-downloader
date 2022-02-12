#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
int n,m;
vector<array<int,2>> eL;
vector<int> p;
vector<int> sz;
int re,cc;

int find(int x){
	return p[x]=(x==p[x])?x:find(p[x]);
}

int uni(int a, int b){
	int x=find(a),y=find(b);
	if (x==y) return sz[x];
	if (sz[x]>sz[y]) {
		p[y]=x;
		return sz[x]+=sz[y];
	}
	else {
		p[x]=y;
		return sz[y]+=sz[x];
	}
}

void solve(){
	p.assign(n,0);
	iota(p.begin(),p.end(),0);
	sz.assign(n,1);
	re=1;cc=n;
	for (auto &arr:eL) {
		int a=find(arr[0]),b=find(arr[1]);
		if (a!=b) {
			re=max(re,uni(a,b));
			--cc;
		}
		cout<<cc<<' '<<re<<'\n';
	}
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;--a;--b;
		eL.push_back({a,b});
	}
	solve();
	return 0;
}