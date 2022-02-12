# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002
using namespace std;
vector<vector<int>> dp;
int l1,l2;
string s1,s2;

int main()
{
    // freopen("test_input.txt","r",stdin);
    fastio; 
    cin>>s1>>s2;
    if (s1.size()>s2.size()) swap(s1,s2);
    l1=s1.size();l2=s2.size();
    dp.assign(l1,vector<int>(l2,0));
    for (int i=0;i<l1;++i)
        for (int k=0;k<l2;++k)
            dp[i][k]=max(i+1,k+1);
    for (int i=0; i<l1; ++i) {
        for (int k=0; k<l2; ++k) {
            if (i>0&&k>0) dp[i][k]=min(dp[i][k],dp[i-1][k-1]+1);
            if (s1[i]==s2[k]) --dp[i][k];
            if (k>0)dp[i][k]=min(dp[i][k],dp[i][k-1]+1);
            if (i>0)dp[i][k]=min(dp[i][k],dp[i-1][k]+1);
        }
    }
    cout<<dp[l1-1][l2-1]<<'\n';
    return 0;
}