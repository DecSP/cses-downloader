#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll binpow(ll x,ll y,ll m){
	ll re=1;
	while(y){
		if (y&1) re=(re*x)%m;
		y>>=1;
		x=(x*x)%m;
	}
	return re;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin>>s;
	int n=s.size();
	ll m=1000000007;
	int x[26]={0};
	for (char &c: s)
		x[c-'a']+=1;

	vector<ll> invFac(n+1,1);
	vector<ll> fac(n+1,1);
	for (int i=2;i<=n;++i){
		fac[i]=fac[i-1]*i%m;
		invFac[i]=binpow(fac[i],m-2,m);
	}
	ll re=fac[n];
	for (int i=0;i<26;++i)
	re=(re*invFac[x[i]])%m;
	cout<<re<<'\n';
}