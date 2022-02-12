# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002

using namespace std;
vector <int> dp;
int n;
int lsCoins[101];
int main()
{
    // auto start=chrono::high_resolution_clock::now();
    fastio;
    int x;
    cin>>n>>x;
    dp.assign(x+1,0);
    for (int i=0;i<n;i++)  cin>>lsCoins[i];
    dp[0]=1;
    sort(lsCoins,lsCoins+n);
    for (int pos =0;pos<n;pos++)
    for (int target=lsCoins[pos];target<=x;target++){
        dp[target]=(dp[target]+dp[target-lsCoins[pos]])%MOD;
    }
    cout<<dp[x]<<'\n';
    // auto stop=chrono::high_resolution_clock::now();
    // cout<<"Took: "<<chrono::duration_cast<chrono::milliseconds>(stop-start).count()<<" ms\n";
    return 0;
}