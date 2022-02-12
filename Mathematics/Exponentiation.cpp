# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<=b;i++)
using namespace std;

const ll MOD=1000000007;
ll expo(ll p, ll q){
	ll re=1;
	while (q){
		if (q&1)re=re*p%MOD;
		q>>=1;
		p=p*p%MOD;
	}
	return re%MOD;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	ll a,b;
	cin>>a>>b;
	cout<<expo(a,b)<<'\n';
	}
	return 0;
}