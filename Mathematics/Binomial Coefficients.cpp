#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+1.5;
const ll MOD=1000000007;
ll fac[maxn];
ll invFac[maxn];
ll binpow(ll x, ll y){
	ll re=1;
	while (y){
		if (y&1){
			re=re*x%MOD;
		}
		x=(x*x)%MOD;
		y>>=1;
	}
	return re;
}
void setArr(){
	fac[0]=invFac[0]=1;
	for (ll i=1;i<maxn;++i){
		fac[i]=(fac[i-1]*i)%MOD;
		invFac[i]=binpow(fac[i],MOD-2);
	}
}
int main(){
	setArr();
	int n;
	cin>>n;
	while (n--){
		ll x,y;
		cin>>x>>y;
		cout<<fac[x]*invFac[x-y]%MOD*invFac[y]%MOD<<'\n';
	}
	return 0;
}