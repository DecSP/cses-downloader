#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll MOD = 1000000007;
const int maxn = 1e6+0.5;
ll dp[maxn+1];
int main() {
	dp[0]=1;dp[1]=2;
	ll acu1=3, acu2=1;
	for (int i=2;i<=maxn; ++i) {
		acu2=(acu2*3+dp[i-1])%MOD;
		dp[i]=(acu1+acu2)%MOD;
		acu1=(acu1+dp[i])%MOD;
	}
	int t;
	cin>>t;
	for (int i=0;i<t;++i) {
		int x;cin>>x;
		cout<<dp[x]<<'\n';
	}
	return 0;
}