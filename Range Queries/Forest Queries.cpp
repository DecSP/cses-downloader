#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,q;
vector<vector<int>> F;

int sum(int r,int c){
	if (r<0||c<0) return 0;
	int re=0;
	for (int i=r;i>=0;i=(i&(i+1))-1){
		for (int j=c;j>=0;j=(j&(j+1))-1){
			re+=F[i][j];
		}
	}
	return re;
}

void increase(int r,int c,int num){
	for (int i=r;i<n;i=i|(i+1)){
		for (int j=c;j<n;j=j|(j+1)){
			F[i][j]+=num;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	F.assign(n,vector<int>(n,0));
	string s;
	for (int i=0;i<n;++i) {
		cin>>s;
		for (int j=0;j<n;++j){
			if (s[j]=='*') increase(i,j,1);
		}
	}
	for (int i=0;i<q;++i){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;--r1;--c1;--r2;--c2;
		cout<<sum(r2,c2)-sum(r2,c1-1)-sum(r1-1,c2)+sum(r1-1,c1-1)<<'\n';
	}
	return 0;
}
