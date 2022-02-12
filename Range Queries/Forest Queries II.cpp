#include <bits/stdc++.h>
using namespace std;
int n,q;
vector<vector<int>> F;
void increase(int r,int c,int add){
	for (int i=r;i<n;i=i|(i+1)){
		for (int j=c;j<n;j=j|(j+1)){
			F[i][j]+=add;
		}
	}
}
int sum(int r,int c){
	int re=0;
	for (int i=r;i>=0;i=(i&(i+1))-1){
		for (int j=c;j>=0;j=(j&(j+1))-1){
			re+=F[i][j];
		}
	}
	return re;
}
int get(int r1,int c1,int r2,int c2){
	return sum(r2,c2)-sum(r2,c1-1)-sum(r1-1,c2)+sum(r1-1,c1-1);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	F.assign(n,vector<int>(n,0));
	vector<string> br(n);
	for (int i=0;i<n;++i){
		cin>>br[i];
		for (int j=0;j<n;++j){
			if (br[i][j]=='*') increase(i,j,1);
		}
	}
	for (int i=0;i<q;++i){
		int t;cin>>t;
		if (t==2){
			int r1,c1,r2,c2;cin>>r1>>c1>>r2>>c2;--r1;--r2;--c1;--c2;
			cout<<get(r1,c1,r2,c2)<<'\n';
		}
		else{
			int r,c;cin>>r>>c;--r;--c;
			int x=1;
			if (br[r][c]=='*'){
				x=-1;
				br[r][c]='.';
			}
			else br[r][c]='*';
			increase(r,c,x);
		}
	}
	return 0;
}