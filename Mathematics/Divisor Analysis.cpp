#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll M=1000000007;
ll binpow(ll x,ll y,ll m){
	ll re=1;
	while(y){
		if (y&1) re=(re*x)%m;
		y>>=1;
		x=(x*x)%m;
	}
	return re;
}
ll sumTo(ll n,ll m){
	return (n*(n+1)/2)%m;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin>>n;
	vector<ll> invFac(n+1,1);
	vector<ll> fac(n+1,1);
	vector<array<int,2>> p(n);
	for (int i=0;i<n;++i){
		cin>>p[i][0]>>p[i][1];
	}
	
	bool hasDiv2=false;
	ll numOfDivisor=1;
	ll numOfDivisor_1=1;
	for (int i=0;i<n;++i){
		numOfDivisor=(numOfDivisor*(p[i][1]+1))%M;
		if (p[i][1]%2&&!hasDiv2){
			numOfDivisor_1=(numOfDivisor_1*((p[i][1]+1)/2))%(M-1);
			hasDiv2=true;
		}
		else
			numOfDivisor_1=(numOfDivisor_1*(p[i][1]+1))%(M-1);
	}
	cout<<numOfDivisor<<'\n';

	ll sumOfDivisor=1;
	for (int i=0;i<n;++i){
		sumOfDivisor=(sumOfDivisor*(binpow(p[i][0],p[i][1]+1,M)-1)%M*binpow(p[i][0]-1,M-2,M)%M+M)%M;
	}
	cout<<sumOfDivisor<<'\n';

	ll productOfDivisor=1;
	for (int i=0;i<n;++i){
		if (!hasDiv2) p[i][1]/=2;
		productOfDivisor=(productOfDivisor*binpow(p[i][0],p[i][1]*numOfDivisor_1%(M-1),M)%M);
	}

	cout<<productOfDivisor<<'\n';
	return 0;
}