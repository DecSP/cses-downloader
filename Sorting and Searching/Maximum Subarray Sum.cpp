# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<b;i++)
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	ll Min=0;
	ll re=-1e18;
	int temp;
	ll sum=0;
	for (int i=0;i<n;i++){
		cin>>temp;
		sum+=temp;
		re=max(re,sum-Min);
		Min=min(sum,Min);
	}
	cout<<re<<endl;
	return 0;
}