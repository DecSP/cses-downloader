#include <bits/stdc++.h>
#define ll long long

using namespace std;

char solve(ll k) {
	ll curr=0;
	ll ten=9;
	ll i =1;
	while (true){
		if (k<=curr+ten*i) break;
		curr+=ten*i;
		++i;
		ten*=10LL;
	}
	curr = k-curr-1;
	return to_string(curr/i+ten/9)[curr%i];
}

int main(){
	int q;cin>>q;
	ll k;
	for (int i=0; i<q; ++i) {
		cin>>k;
		cout<<solve(k)<<'\n';
	}
	return 0;
}