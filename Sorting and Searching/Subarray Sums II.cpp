# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
int main(){
	fastio;
	int n,tmp;
	ll x;
	cin>>n>>x;
	vector <ll> s(n+1);
	for (int i=1;i<=n;i++){
		cin>>tmp;
		s[i]=tmp+s[i-1];
	}
	ll re=0;
	map <ll,int> m;
	for (int i=n;i>=0;i--){
		re+=m[s[i]+x];
		m[s[i]]++;
	}
	cout<<re<<'\n';
	return 0;
}