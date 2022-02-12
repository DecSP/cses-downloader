#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;
vector<vector<ll>> dp;
ll suplement(vector<ll>& row,ll state,ll i) {
	ll re=0;
	while (i<state){
		if (i&state) {
			i<<=1;
			while (i&state){
				ll nstate=state^(i+(i>>1));
				i<<=1;
				re= (re+row[nstate]+suplement(row,nstate,i))%MOD;
			}
		}
		i<<=1;
	}
	return re;
}
int main(){
	ll n,m;
	cin>>n>>m;
	ll mxn=1LL<<n;
	dp.assign(m+1,vector<ll>(mxn,0));
	dp[0][(mxn)-1]=1;
	for (int r=1;r<=m;++r) {
		for (ll state=0;state<mxn;++state) 
			dp[r][state]=(dp[r][state]+dp[r-1][state^(mxn-1)])%MOD;
		for (ll state=mxn-1;state>=0;--state) 
			dp[r][state]=(dp[r][state]+suplement(dp[r],state,1))%MOD;
		
	}
	cout<<dp[m][mxn-1]<<'\n';
    return 0;
}