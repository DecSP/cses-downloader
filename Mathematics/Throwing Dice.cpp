#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=1000000007;

vector<vector<ll>> mult(vector<vector<ll>>& x, vector<vector<ll>> &y){
	int n1=x.size(),m1=x[0].size(),n2=y.size(),m2=y[0].size();
	vector<vector<ll>> re (n1,vector<ll>(m2,0));
	for (int i=0;i<n1;++i){
		for (int j=0;j<m2;++j){
			for (int k=0;k<m1;++k){
				re[i][j]=(re[i][j]+x[i][k]*y[k][j])%MOD;
			}
		}
	}
	return re;
}

vector<vector<ll>> binpow(vector<vector<ll>> x , ll y){
	vector<vector<ll>> re(6,vector<ll>(6,0));
	for (int i=0;i<6;++i) re[i][i]=1;
	while (y){
		if (y&1) re=mult(re,x);
		y>>=1;
		x=mult(x,x);
	}
	return re;
}

int main(){
	vector<vector<ll>> mat(6,vector<ll>(6,0));
	for (int i=0;i<6;++i) mat[i][0]=1;
	for (int i=0;i<5;++i) mat[i][i+1]=1;
	ll n;cin>>n;
	mat=binpow(mat,n);
	vector<vector<ll>> init(1,vector<ll>(6,0));
	init[0][4]=init[0][5]=1;
	for (int i=3;i>=0;--i)init[0][i]=2*init[0][i+1];
	cout<<mult(init,mat)[0][5]<<'\n';
}