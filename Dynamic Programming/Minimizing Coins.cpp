# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define ten6 (1e6+1.5)
using namespace std;

ll dp [(int)ten6]{0};
vector <int> c;
ll solve (int x){
    if (x==0) return 0;
    if (dp[x]) return dp[x];
    ll re=ten6;
    for (auto v:c) {
        if (v>x) continue;
        re=min(re,1+solve(x-v));
    }
    return dp[x]=re;
}

int main()
{
    fastio;
    int n,x;
    cin>>n>>x;
    c.assign(n,0);
    for (auto &v:c){
        cin>>v;
        dp[v]=1;
    }
    ll re=solve(x);
    if (re<(ll)(ten6))
    cout<<solve(x)<<'\n';
    else cout<<-1<<'\n';
    return 0;    
}