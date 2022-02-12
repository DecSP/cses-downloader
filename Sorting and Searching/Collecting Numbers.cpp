#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	fastio;
	int n;
	cin>>n;
	vector<pair<int,int>> a(n);
	for (int i=0;i<n;++i){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a.begin(),a.end());
	ll re=1;
	for (int i=1;i<n;++i){
		if (a[i].second < a[i-1].second) ++re;
	}
	cout<<re<<'\n';
    return 0;
}