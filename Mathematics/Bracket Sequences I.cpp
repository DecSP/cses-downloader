#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll M=1000000007;
vector<ll> invFac;
vector<ll> fac;

ll binpow(ll x,ll y,ll m){
	ll re=1;
	while(y){
		if (y&1) re=(re*x)%m;
		y>>=1;
		x=(x*x)%m;
	}
	return re;
}
ll C(int n, int k){
	return fac[n]*invFac[k]%M*invFac[n-k]%M;
}
int main(){
	int n;
	cin>>n;
	if (n%2){
		cout<<0<<'\n';
		return 0;
	}
	fac.assign(n+1,1);
	invFac.assign(n+1,1);
	for (int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%M;
		invFac[i]=binpow(fac[i],M-2,M);
	}
	n/=2;
	ll re=C(2*n,n)-C(2*n,n-1)+M;
	re%=M;
	cout<<re<<'\n';
	return 0;
}