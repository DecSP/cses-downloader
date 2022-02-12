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
	sort(s.begin()+1,s.end());
	int l=0,r=0;
	ll re=0;
	while(l<=n&&r<=n){
		ll tg=s[r]-s[l];
		if (tg<x) r++;
		else if (tg>x) l++;
		else {
			ll a=1,b=1;
			while (l<n&&s[l+1]==s[l]){l++;a++;}
			l++;
			while (r<n&&s[r+1]==s[r]){r++;b++;}
			r++;
			re+=a*b;
		}
	}
	cout<<re<<'\n';
	return 0;
}