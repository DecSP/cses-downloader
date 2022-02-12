# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
int n;
ll dp [(int)(1e6+1.5)]{0};
int main(){
	fastio;
	cin>>n;
	for (int i=0;i<=6;i++)dp[i]=1;
	for (int i=2;i<=n;i++){
		for (int j=min(6,i-1);j>=1;--j){
				dp[i]=(dp[i]+dp[i-j])%MOD;
		}
	}
	cout<<dp[n]<<'\n';
	return 0;
}