#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
using namespace std;

const ll M=1000000007LL;
int main(){
	fastio;
	int n,k;cin>>n>>k;
	if (k==0) {
		cout<<"1\n";
		return 0;
	}
	vector<vector<ll>> dp(n+1,vector<ll>(k+1,-1));
	for (int i=1;i<=n;++i) dp[i][0]=1;
	for (int j=1;j<=k;++j) dp[1][j]=1;
	for (int i=2;i<=n;++i){
		for (int j=1;j<=k;++j){
			dp[i][j]=(dp[i-1][j]-((j>=i)?dp[i-1][j-i]:0)+M)%M;
			if (i==n&&j==k) {
				cout<<dp[n][k]<<'\n';
				return 0;
			}
			dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
		}
	}
}