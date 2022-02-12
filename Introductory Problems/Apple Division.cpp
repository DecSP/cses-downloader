# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll re=INFINITY;
	ll su=0;
	cin>>n;
	vector <ll> p (n);
	for(int i=0;i<n;i++){cin>>p[i];su+=p[i];}
	for (int i =1;i<1<<n;i++){
		ll t=0;
		for (int j=1;1<<j<=i;j++)if((1<<j)&i) t+=p[j];
		re=min(re,abs(2*t-su));
	}
	cout<<re<<endl;
	return 0;
}