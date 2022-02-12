#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
int n,m;
vector<array<int,3>> eL;
vector<int> p;
vector<int> sz;
ll re;

int find(int x){
	return p[x]=(x==p[x])?x:find(p[x]);
}

void uni(int a, int b){
	int x=find(a),y=find(b);
	if (x==y) return;
	if (sz[x]>sz[y]) {
		p[y]=x;
		sz[x]+=sz[y];
	}
	else {
		p[x]=y;
		sz[y]+=sz[x];
	}
}

bool solve(){
	p.assign(n,0);
	iota(p.begin(),p.end(),0);
	sz.assign(n,1);
	re=0;
	for (auto &arr:eL) {
		int a=find(arr[1]),b=find(arr[2]);
		if (a==b) continue;
		else uni(a,b);
		re+=arr[0];
	}
	return sz[find(0)]==n;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	for (int i=0;i<m;++i){
		int a,b,c;
		cin>>a>>b>>c;--a;--b;
		eL.push_back({c,a,b});
	}
	sort(eL.begin(),eL.end());
	if (solve()) cout<<re;
	else cout<<"IMPOSSIBLE";
	return 0;
}