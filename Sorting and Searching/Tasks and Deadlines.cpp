# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main(){
	fastio;
	ll re=0;
	int n,tmp;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++){
		cin>>a[i]>>tmp;
		re+=tmp;
	}
	sort(all(a));
	for(ll i=0;i<n;i++)re-=(n-i)*a[i];
	cout<<re<<'\n';
	return 0;
}