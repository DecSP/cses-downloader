# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<b;i++)
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	vector <int> a(n);
	
	for (auto &x:a){
		cin>>x;
	}
	sort(all(a));
	int m=a[n/2];
	ll re=0;
	for (auto &x:a){
		re+=abs(x-m);
	}
	cout<<re<<endl;
	return 0;
}