#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1000000;

vector<int> p(maxn+1,1);
int m[maxn+1]={0};

void sieve(){
	for (int i=2;i<=maxn;++i) {
		ll j=i*i;
		if (j>maxn) break;
		if (p[i]!=1) continue;
		while (j<=maxn){
			if (p[j]==1) p[j]=i;
			j+=i;
		}
	}
}

vector<int> primeFac(int x){
	vector<int> re;
	while (p[x]!=1){
		re.push_back(p[x]);
		int tmp=p[x];
		while (x%tmp==0){
			x/=tmp;
		}
	}
	if (x!=1) re.push_back(x);
	return re;
}

ll Set(const vector<int>&a, int curr, int idx, int cnt){
	ll re=0;
	if (idx==a.size()){
		if (curr>1){
			re= ((cnt%2)?1:-1) * m[curr];
			++m[curr];
		}
	}
	else{
		re=Set(a,curr*a[idx],idx+1,cnt+1)+Set(a,curr,idx+1,cnt);
	}
	return re;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	sieve();
	ll n;cin>>n;
	ll re = (n-1)*n/2;
	for (int i=0;i<n;++i){
		int a;cin>>a;
		re-=Set(primeFac(a),1,0,0);
	}
	cout<<re<<'\n';
	return 0;
}