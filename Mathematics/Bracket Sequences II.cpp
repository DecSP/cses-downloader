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
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin>>n;
	if (n%2){
		cout<<0<<'\n';
		return 0;
	}
	string s;
	cin>>s;
	int k=0;
	for (char &c:s){
		if (c=='(') k+=1;
		else{
			k-=1;
			if (k<0){
				cout<<0<<'\n';
				return 0;
			}
		}
		--n;
	}
	if (n<k){
		cout<<0<<'\n';
		return 0;
	}
	fac.assign(n+1,1);
	invFac.assign(n+1,1);
	for (int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%M;
		invFac[i]=binpow(fac[i],M-2,M);
	}
	n=(n-k)/2;
	if (n==0){
		cout<<1<<'\n';
		return 0;
	}
	ll re=C(2*n+k,n)-C(2*n+k,n-1)+M;
	re%=M;
	cout<<re<<'\n';
	return 0;
}