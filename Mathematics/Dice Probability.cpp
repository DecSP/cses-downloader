#include <bits/stdc++.h>
using namespace std;
int n,a,b;
void solve(){
	int mxn=6*n;
	vector<vector<double>> dp(n+1,vector<double>(mxn+1));
	for (int i=0;i<=mxn;++i) dp[0][i]=1;
	for (int i=1;i<=n;++i){
		for (int k=1;k<=mxn;++k){
			for (int j=1;j<=6;++j){
				if (j<=k) dp[i][k]+=dp[i-1][k-j]/6.0;
				else break;
			}
		}
	}
	printf("%.6f\n",dp[n][b]-dp[n][a-1]);
}

int main(){
	scanf("%d %d %d",&n,&a,&b);
	solve();
	return 0;
}