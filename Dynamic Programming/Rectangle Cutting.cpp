#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1000000007;

int main(){
	int a,b;
	cin>>a>>b;
	int mx=max(a,b);
	vector <vector<int>> dp (mx+1,vector<int>(mx+1,MOD));
	for (int i=1;i<=mx;++i) dp[i][i]=0;
	for (int i=1;i<=mx;++i) {
		for (int j=i;j<=mx;++j) {
			for (int k=1;k<=mx;++k) {
				if (k+j<=mx) dp[k+j][i]=dp[i][k+j]=min(dp[i][k+j],dp[i][j]+dp[i][k]+1);
				if (k+i<=mx) dp[k+i][j]=dp[j][k+i]=min(dp[j][k+i],dp[i][j]+dp[j][k]+1);
			}
		}
	}
	cout<<dp[a][b]<<endl;
    return 0;
}