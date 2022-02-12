#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n,k;
	cin>>n>>k;
	
	vector<int>arr(n);
	map<int,int> m;
	ll re = 0;

	int beg=0;
	for (int i=0; i<n; ++i) {
		cin>>arr[i];
		if (m.find(arr[i])==m.end() && m.size()==k) {
			while (beg<=i) {
				auto it = m.find(arr[beg]);
				--(*it).second;
				++beg;
				if ((*it).second==0) {
					m.erase(it);
					break;
				}
			}
		}
		++m[arr[i]];
		ll n1=i-beg+1;
		re+= n1;
	}

	cout<<re<<'\n';
	return 0;
}