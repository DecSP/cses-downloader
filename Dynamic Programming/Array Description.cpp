# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002
using namespace std;
vector<vector<ll>> dp;
vector<vector<ll>> coeff;
int n,m;

void setCoeff(){
    coeff[0][0]=1;
    for(int i=1;i<=m;++i){
        // coeff[i] = coeff[i-1]<<1 - coeff[i-1] - coeff[i-2]
        coeff[i][0]=-coeff[i-1][0];
        for (int k=1;k<=i;++k) {
            coeff[i][k]=(coeff[i-1][k-1]-coeff[i-1][k])%MOD;
        }
        if (i>1) {
            for (int k=0;k<=i-2;++k) {
                coeff[i][k]=(coeff[i][k]-coeff[i-2][k])%MOD;
            }   
        }
    }
}

void setDP(){
    // dp[dis][0->m]
    dp[0][0]=1;
    for(int i=1;i<=n+m;++i){
        // dp[i][k] = dp[i-1][k] + dp[i-1][k-1] +dp[i-1][k+1]
        for (int k=0;k<=m;++k) {
            ll ans=dp[i-1][k];
            if (k<m) ans+=dp[i-1][k+1];
            if (k>0) ans+=dp[i-1][k-1];
            ans%=MOD;
            dp[i][k]=ans;
        }
    }
}

ll getShit(int from, int to, int dis) {
    if (dis==1) return from==-1 || abs(to-from)<=1;
    ll ans=0;
    for (int i=0;i<=m;++i) {
        ans=(ans+dp[dis+i][to]*coeff[from][i]%MOD)%MOD;
    }
    return ans;
}
int main()
{
    // freopen("test_input.txt","r",stdin);
    fastio; 
    cin>>n>>m;
    --m;
    dp.assign(n+m+1,vector<ll>(m+1,0));
    coeff.assign(m+1,vector<ll>(m+1,0));
    setCoeff();
    setDP();
    vector<int> arr(n);
    for (int i=0;i<n;++i) cin>>arr[i];
    ll re=1;
    int from=-1,to=0;
    while (from<n) {
        while(to<n&&arr[to]==0) ++to;
        if (from==-1 && to==n) {
            ll tmp=0;
            for (int i=0; i<=m; ++i) {
                for (int k=0; k<=m; ++k) {
                    tmp=(tmp+getShit(i,k,n-1))%MOD;
                }
            }
            re=(re*tmp)%MOD;
            break;
        }
        if (from==-1) {
            if (to!=0) {
                ll tmp=0;
                for (int i=0; i<=m; ++i) {
                    tmp=(tmp+getShit(i,arr[to]-1,to))%MOD;
                }
                re=(re*tmp)%MOD;
            }
        }
        else if (to==n) {
            if (to-from!=1){
                ll tmp=0;
                for (int i=0; i<=m; ++i) {
                    tmp=(tmp+getShit(arr[from]-1,i,to-from-1))%MOD;
                }
                re=(re*tmp)%MOD;
            }
        }
        else re=(re*getShit(arr[from]-1,arr[to]-1,to-from))%MOD;
        from=to;
        ++to;
    }
    if (re<0) re+=MOD;
    cout<<re<<'\n';
    return 0;
}