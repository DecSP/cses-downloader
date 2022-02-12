#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

int main(){
	ll n;
	cin>>n;
	vector<ll> arr(n);
	for (int i=0;i<n;++i) cin>>arr[i];
	vector<vector<pair<ll,ll>>> dp(n+1,vector<pair<ll,ll>>(n+1,{-1,-1}));
	for (int i=0;i<n;++i) dp[i][i]={arr[i],0};
	for (int i=1;i<n;++i) {
		for (int j=0;j<n;++j) {
			if (i+j>=n) break;
			auto p1=dp[j][i+j-1].second+arr[i+j];
			auto p2=dp[j+1][i+j].second+arr[j];
			if (p1>p2) dp[j][i+j]= {p1,dp[j][i+j-1].first};
			else dp[j][i+j]= {p2,dp[j+1][i+j].first};
		}
	}
	cout<<dp[0][n-1].first<<'\n';
    return 0;
}