#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define MOD 1000000007;
using namespace std;



void solve(){
    int n;
    cin>>n;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1));
    vector<string>s(n);
    for (int i=0;i<n;++i) cin>>s[i];
    dp[1][1]=1;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%MOD;
            if (s[i-1][j-1]=='*') dp[i][j]=0;
        }
    }
    cout<<dp[n][n]<<'\n';
}

int main()
{
    fastio;
    solve();
	return 0;
}

