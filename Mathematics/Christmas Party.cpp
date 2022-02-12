#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1000000007LL;
const int maxn = 1000000;

ll dp[maxn+1];
ll K[maxn+1];
ll invFac[maxn+1];
ll Fac[maxn+1];
int n;

ll binpow(ll x, ll y){
	ll re=1;
	while (y){
		if (y&1) re = (re*x)%MOD;
		x=(x*x)%MOD;
		y>>=1;
	}
	return re;
}

void preCalc(){
	invFac[0]=Fac[0]=1;
	for (ll i=1;i<n;++i){
		invFac[i]= (binpow(i,MOD-2)*invFac[i-1])%MOD;
		Fac[i]=Fac[i-1]*i%MOD;
	}
}

int main(){
	cin>>n;
	preCalc();
	dp[1]=0;dp[2]=1;dp[3]=2;
	K[1]=K[2]=K[3]=0;
	for (ll i=4;i<=n;++i){
		K[i] = ((K[i-1] * (i-1))%MOD +(dp[i-2]*invFac[i-2])%MOD * Fac[i-1]%MOD)%MOD;
		dp[i]= (K[i]+Fac[i-1])%MOD;
	}
	// for (int i=1;i<=n;++i){
	// 	cout<<"K: "<<K[i]<<", dp: "<<dp[i]<<endl;
	// }
	cout<<dp[n]<<'\n';
	return 0;
}