#include <bits/stdc++.h>
using namespace std;
const int maxn=1000000;
bool dp[maxn+1]={0};
int main(){
	int n,k;cin>>n>>k;
	vector<int> mv(k);
	for (int &v:mv)cin>>v;
	dp[0]=true;
	for(int i=1;i<=n;++i){
		for (int&v:mv) {
			if (v<=i&&dp[i-v]) {
				dp[i]=true;
				break;
			}
		}
		dp[i]=!dp[i];
		cout<<((dp[i])?'L':'W');
	}
	cout<<'\n';
	return 0;
}