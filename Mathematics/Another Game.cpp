#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	bool o=false;
	while (n--){
		int x;cin>>x;
		if (x%2)o=true;
	}
	cout<<(o?"first":"second")<<'\n';
}

int main(){
	int t;cin>>t;
	while (t--){
		int n;cin>>n;
		solve(n);
	}
	return 0;
}