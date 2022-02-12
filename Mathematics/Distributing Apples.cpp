#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll binpow(ll x,ll y,ll m){
	ll re=1;
	while(y){
		if (y&1) re=(re*x)%m;
		y>>=1;
		x=(x*x)%m;
	}
	return re;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n,m;
	cin>>m>>n;
	m-=1;
	n+=m;
	ll M=1000000007;
	vector<ll> invFac(n+1,1);
	vector<ll> fac(n+1,1);
	for (int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%M;
		invFac[i]=binpow(fac[i],M-2,M);
	}
	ll re=fac[n]*invFac[m]%M*invFac[n-m]%M;
	cout<<re<<'\n';
}