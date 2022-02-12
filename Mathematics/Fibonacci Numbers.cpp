#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
ll n;
ll pow2(ll x, ll y){
	return ((x*(y+MOD-x)%MOD)+(x*y%MOD))%MOD;	
}
pair<ll,ll> fib(ll y){
	if (y==0) return {0,1};
	pair<ll,ll> x = fib(y>>1);
	ll fs = pow2(x.first,x.second);
	ll sc = (pow2(x.second, x.first+x.second)+MOD-fs)%MOD;
	if (y&1) return {sc,(fs+sc)%MOD};
	return {fs,sc};
}
int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n;
	cout<<fib(n).first<<'\n';
	return 0;
}