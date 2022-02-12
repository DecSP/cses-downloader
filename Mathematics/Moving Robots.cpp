#include <bits/stdc++.h>
using namespace std;
int k;
struct br{
	array<double,64> board;
	public: br(){
		board.fill(0);
	}
};
array<int,2>dir[]={{-1,0},{1,0},{0,-1},{0,1}};
void solve(){
	vector<vector<br>> dp(64,vector<br>(k+1,br()));
	for (int i=0;i<64;++i) dp[i][0].board[i]=1;
	for (int i=1;i<=k;++i){
		for (int r=0;r<8;++r){
			for (int c=0;c<8;++c){
				int cnt=0;
				for (int j=0;j<4;++j){
					int nr=r+dir[j][0],nc=c+dir[j][1];
					if (nr<0||nr>=8||nc<0||nc>=8) continue;
					++cnt;
				}
				for (int j=0;j<4;++j){
					int nr=r+dir[j][0],nc=c+dir[j][1];
					if (nr<0||nr>=8||nc<0||nc>=8) continue;
					for (int pos=0;pos<64;++pos){
						dp[r*8+c][i].board[pos]+=dp[nr*8+nc][i-1].board[pos]/cnt;
					}
				}
			}
		}
	}
	double re=0;
	for (int i=0;i<64;++i){
		double tmp=1;
		for (int j=0;j<64;++j)
			tmp*=(1-dp[j][k].board[i]);
		re+=tmp;
	}
	printf("%.6f\n",re);
}

int main(){
	scanf("%d",&k);
	solve();
	return 0;
}