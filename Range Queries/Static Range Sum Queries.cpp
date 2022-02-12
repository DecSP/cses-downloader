# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
int main(){
	fastio;
	int n,q;
	cin>>n>>q;
	vector <ll> a(n+1);
	for (int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	int x,y;
	for (int i=0;i<q;i++){
		cin>>x>>y;
		cout<<a[y]-a[x-1]<<'\n';
	}
	return 0;
}