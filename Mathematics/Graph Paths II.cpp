#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=1e18+1000;
int n,m,k;
vector<vector<ll>> mult(vector<vector<ll>>& x, vector<vector<ll>> &y){
	int n1=x.size(),m1=x[0].size(),n2=y.size(),m2=y[0].size();
	vector<vector<ll>> re (n1,vector<ll>(m2,MOD));
	for (int i=0;i<n1;++i){
		for (int j=0;j<m2;++j){
			for (int k=0;k<m1;++k){
				re[i][j]=min(re[i][j],x[i][k]+y[k][j]);
			}
		}
	}
	return re;
}

vector<vector<ll>> binpow(vector<vector<ll>> x , ll y){
	vector<vector<ll>> re(n,vector<ll>(n,MOD));
	for (int i=0;i<n;++i) re[i][i]=0;
	while (y){
		if (y&1) re=mult(re,x);
		y>>=1;
		x=mult(x,x);
	}
	return re;
}

void print(ll x){
	cout<<((x==MOD)?-1LL:x)<<'\n';	
}

int main(){
	cin>>n>>m>>k;
	vector<vector<ll>> mat(n,vector<ll>(n,MOD));
	for (int i=0;i<m;++i) {
		int a,b;ll c;cin>>a>>b>>c;--a;--b;
		mat[a][b]=min(c,mat[a][b]);
	}
	mat=binpow(mat,k);
	print(mat[0][n-1]);
}