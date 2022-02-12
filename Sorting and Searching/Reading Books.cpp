# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
int main(){
	fastio;
	ll re=0;
	int n,tmp,m=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>tmp;
		m=max(m,tmp);
		re+=tmp;
	}
	m<<=1;
	if (n==1 || re<m) re=m;
	cout<<re<<'\n';
	return 0;
}