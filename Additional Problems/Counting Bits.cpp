#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n;
	cin>>n;
	ll cur=1,re=0;
	while (cur<=n){
		ll x=n-(cur-1);
		re+=x/(cur<<1)*cur+min(x%(cur<<1),cur);
		cur<<=1;
	}
	cout<<re<<'\n';
	return 0;
}

// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111
