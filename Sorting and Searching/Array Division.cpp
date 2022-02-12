# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
vector <ll> arr;
int n,k;
bool check(ll s){
	int cnt=1;
	ll acc=0;
	for(int i = 0;i<n;i++){
		ll tmp=acc+arr[i];
		if (tmp>s) {
			cnt++;
			acc=arr[i];
		}
		else acc=tmp;
		if (acc>s||cnt>k) return false;
	}
	return true;
}
int main(){
	fastio;
	cin>>n>>k; arr.assign(n,0);
	ll r=0,l=1;
	for (auto &v:arr){
		cin>>v;
		r+=v;
	}
	while (l<r){
		ll mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
	return 0;
}