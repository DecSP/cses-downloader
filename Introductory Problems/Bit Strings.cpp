# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
using namespace std;
ll md=1000000007;
ll expo (ll m, int e){
	if(!e) return 1;
	m%=md;
	if (e&1) return (m*expo(m*m,e>>1))%md;
	return (expo(m*m,e>>1))%md;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e;
	cin>>e;
	cout<<expo(2,e)<<endl;
	return 0;
}