#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<pair<int,int>> a;
vector<int> arr;
int n,q;

int change(int pos, int num){
	int re=0;
	if (pos>0){
		if (a[pos-1].second < a[pos].second && a[pos-1].second >= num) ++re;
		if (a[pos-1].second > a[pos].second && a[pos-1].second <= num) --re;
	}
	if (pos<n-1) {
		if (a[pos+1].second < a[pos].second && a[pos+1].second >= num) --re;
		if (a[pos+1].second > a[pos].second && a[pos+1].second <= num) ++re;
	}
	a[pos].second=num;
	return re;
}

int main(){
	fastio;
	cin>>n>>q;
	arr.assign(n,0);
	a.assign(n,{0,0});
	for (int i=0;i<n;++i){
		cin>>arr[i];
		a[i].first=arr[i];
		a[i].second=i;
	}
	sort(a.begin(),a.end());
	ll re=1;

	for (int i=1;i<n;++i){
		if (a[i].second < a[i-1].second) ++re;
	}

	for (int i=0;i<q;++i){
		int x,y;
		cin>>x>>y;--x;--y;
		auto it1 = lower_bound(a.begin(),a.end(),make_pair(arr[x],-1));
		auto it2 = lower_bound(a.begin(),a.end(),make_pair(arr[y],-1));
		int ox=(*it1).second,oy=(*it2).second;
		re+=change(it1-a.begin(),oy);
		re+=change(it2-a.begin(),ox);
		swap(arr[x],arr[y]);
		cout<<re<<'\n';
	}
    return 0;
}	