#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2000;
ll g[maxn+1];

void setG(){
	g[0]=0;
	for (int i=1;i<=maxn;++i){
		set<int>tmp;
		for (int j=1;j*2<i;++j){
			tmp.insert(g[j]^g[i-j]);
		}
		for ( g[i]=0;!tmp.empty();++g[i]){
			if (g[i]!=*(tmp.begin())) break;
			tmp.erase(tmp.begin());
		}
	}
}

void solve(int n){
	cout<<((n<=2000&&g[n]==0)?"second":"first")<<'\n';
}

int main(){
	setG();
	int t;cin>>t;
	while (t--){
		int n;cin>>n;
		solve(n);
	}
	return 0;
}