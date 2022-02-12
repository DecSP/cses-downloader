# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
using namespace std;
ll md=1000000007;
ll num5(int n){
	ll re=0;
	while (n){
		n/=5;
		re+=n;
	}
	return re;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e;
	cin>>e;
	cout<<num5(e)<<endl;
	return 0;
}