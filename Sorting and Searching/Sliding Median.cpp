#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
const int MOD = 1000000007;

int main(){
	fastio;
	int n,k;
	cin>>n>>k;
	multiset<ll> lessPt,greatPt;
	vector<ll> arr(n);
	for (int i=0; i<n; ++i) {
		ll tmp;
		cin>>tmp;
		arr[i]=tmp;
		lessPt.insert(tmp);

		if (lessPt.size()>(k-1)/2) {
			ll tmp2 = *(prev(lessPt.end()));
			lessPt.erase(prev(lessPt.end()));
			greatPt.insert(tmp2);
		}
		if (i>=k) {
			if (*greatPt.begin() <= arr[i-k]) {
				greatPt.erase(greatPt.find(arr[i-k]));
			}
			else {
				lessPt.erase(lessPt.find(arr[i-k]));
				ll tmp2 = *(greatPt.begin());
				greatPt.erase(greatPt.begin());
				lessPt.insert(tmp2);
			}
		}

		if (i>=k-1) {
			if (i!=k-1) cout<<' ';
			cout<<*greatPt.begin();
		}
	}
	cout<<'\n';
    return 0;
}