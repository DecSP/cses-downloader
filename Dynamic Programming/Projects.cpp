#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
const ll MOD = 1000000007;
const int maxn = 200001;
int n;

int main(){
	fastio;
	cin>>n;
	vector<tuple<int, int ,ll>> arr(n);
	for (int i=0; i<n; ++i) {
		cin>>get<1>(arr[i])>>get<0>(arr[i])>>get<2>(arr[i]);
	}
	sort(arr.begin(),arr.end());

	vector <pair<int, ll>> sav;
	sav.push_back({0,0LL});
	for (int i=0; i<n; ++i) {
		auto it = lower_bound(sav.begin(),sav.end(),make_pair(get<1>(arr[i]),-1LL));
		pair<int,ll> nxt = {get<0>(arr[i]),get<2>(arr[i])};
		if (it!=sav.begin()) nxt.second+=prev(it)->second;
		nxt.second=max(nxt.second,sav.back().second);
		sav.push_back(nxt);
	}
	cout<<sav.back().second<<'\n';
	return 0;
}