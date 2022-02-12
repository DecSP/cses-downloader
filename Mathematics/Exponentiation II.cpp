# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<=b;i++)
using namespace std;

const ll MOD=1000000007;
ll expo(ll p, ll q,ll mod){
	ll re=1;
	while (q){
		if (q&1)re=re*p%mod;
		q>>=1;
		p=p*p%mod;
	}
	return re%mod;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	ll a,b,c;
	cin>>a>>b>>c;
	b=expo(b,c,MOD-1);
	cout<<expo(a,b,MOD)<<'\n';
	}
	return 0;
}