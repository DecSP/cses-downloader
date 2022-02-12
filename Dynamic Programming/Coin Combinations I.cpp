# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002
using namespace std;
 
ll dp[ten6]={0};
int main()
{
    fastio;
    int n, k;
    cin>>n>>k;
    vector<int>lsCoins(n);
    for (int i=0;i<n;i++) cin>>lsCoins[i];
    dp[0]=1;
    for (int target=1;target<=k;target++){
        for (int v:lsCoins){
            if (target>=v)
            dp[target]=(dp[target]+dp[target-v])%MOD;
        }
    }
    cout<<dp[k]<<'\n';
      return 0;
}