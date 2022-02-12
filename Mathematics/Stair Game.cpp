#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n;cin>>n;
	int re=0;
	for (int i=0;i<n;++i){
		int tmp;cin>>tmp;
		if (i%2) re^=tmp;
	}
	cout<<((re==0)?"second":"first")<<'\n';
}
int main(){
	int t;cin>>t;
	while(t--)solve();
	return 0;
}