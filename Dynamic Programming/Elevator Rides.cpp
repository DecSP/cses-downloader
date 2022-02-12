#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int,ll>> dp;
vector<ll> arr;
int n;
ll x,mx;

pair<int,ll> get(ll currW, ll state) {
	if (dp[state].first==-1) {
        pair<int,ll> re = {n+1,0LL};
        for (ll i=0;i<n;++i) {
            if (state & (1LL<<i)) continue;
            re=min(re,get(arr[i],state|(1LL<<i)));
        }
        dp[state] = re;
    }
    ll w = dp[state].second+currW;
    if (w<=x) return {dp[state].first,w};
    return {dp[state].first+1,min(dp[state].second,currW)};
}
 
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>x;
	mx=(1LL<<n);
	arr.assign(n,0LL);
	dp.assign(mx,{-1,0LL});
	for (ll &v:arr) cin>>v;
	dp[mx-1]={0,0LL};
	cout<<get(0LL,0LL).first+1<<'\n';
	return 0;
}