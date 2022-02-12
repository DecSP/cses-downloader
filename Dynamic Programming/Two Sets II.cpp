#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD = 1000000007;

ll binPow(ll x, ll y) {
	ll re=1;
	while(y){
		if (y&1){
			re=(re*x)%MOD;
		}
		x=(x*x)%MOD;
		y>>=1;
	}
	return re;
}

int main(){
	ll n;
	cin>>n;
	ll tg = n*(n+1)/2;
	if (tg%2) {
		cout<<0<<'\n';
		return 0;
	}
	tg/=2;
	vector<ll> dp(tg+1,0);
	dp[0]=1;
	for (ll i=1;i<=n;++i) {
		for (ll j =tg;j>=i;--j) {
			dp[j]=(dp[j]+dp[j-i])%MOD;
		}
	}
	cout<<(dp[tg]*binPow(2LL,MOD-2))%MOD<<'\n';
    return 0;
}