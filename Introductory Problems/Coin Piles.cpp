# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
using namespace std;
ll md=1000000007;
bool solve(int a,int b){
	if (a>b) swap(a,b);
	a=a*2-b;
	return !(a%3)&&a>=0;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--){
		int a,b;
		cin>>a>>b;
		if (solve(a,b)) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}