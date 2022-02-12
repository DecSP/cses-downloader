#include <bits/stdc++.h>
using namespace std;
int n,k;
void solve(){
	vector<vector<double>> dp(n+1,vector<double>(k+1,0));
	dp[0][0]=1;
	for (int i=1;i<=n;++i){
		double acu=dp[i-1][0];
		for (int j=1;j<=k;++j){
			dp[i][j]+=acu/k+j*dp[i-1][j]/k;
			acu+=dp[i-1][j];
		}
	}
	double re=0;
	for (int i=1;i<=k;++i) {
		re+=i*dp[n][i];
	}
	printf("%.6f\n",re);
}

int main(){
	scanf("%d %d",&n,&k);
	solve();
	return 0;
}