# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
int main(){
	fastio;
	int n,tmp;
	cin>>n;
	vector <ll> s(n+1);
	for (int i=1;i<=n;i++){
		cin>>tmp;
		s[i]=tmp+s[i-1];
	}
	ll re=0;
	unordered_map <ll,int> m;
	m.reserve(n+1);
	for (int i=n;i>=0;i--){
		tmp=s[i]%n;
		if (tmp<0)tmp+=n;
		if (m.find(tmp)!=m.end()) re+=m[tmp];
		m[tmp]++;
	}
	cout<<re<<'\n';
	return 0;
}