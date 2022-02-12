#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int n;
	ll x;
	cin>>n>>x;
	vector<int>a(n);
	for (int&v:a)cin>>v;
	vector<ll>s1,s2;
	int sz1=n/2,sz2=n-sz1;
	for (int i=(1<<sz1)-1;i>=0;--i){
		ll s=0;
		for (int j=0;i>=(1<<j);++j){
			if (i&(1<<j)) s+=a[j];
		}
		// cout<<"s1: "<<s<<endl;
		s1.push_back(s);
	}
	for (int i=(1<<sz2)-1;i>=0;--i){
		ll s=0;
		for (int j=0;i>=(1<<j);++j){
			if (i&(1<<j)) s+=a[sz1+j];
		}
		// cout<<"s2: "<<s<<endl;
		s2.push_back(s);
	}
	sort(s2.begin(),s2.end());
	ll re=0;
	for (ll &v:s1){
		ll tg = x-v;
		re+=upper_bound(s2.begin(),s2.end(),tg)-lower_bound(s2.begin(),s2.end(),tg);
	}
	cout<<re<<'\n';
	return 0;
}