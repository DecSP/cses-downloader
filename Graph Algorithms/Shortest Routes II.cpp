#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll MOD = 1000000007;

vector <vector<ll>> d;
int n,m,q;

int main() {
	fastio;
	MOD*=MOD;
	cin>>n>>m>>q;
	d.assign(n,vector<ll>(n,MOD));
	for (int i=0;i<n;++i) d[i][i]=0;
	for (int i=0; i<m; ++i) {
		int a,b;
		ll c;
		cin>>a>>b>>c;
		--a;--b;
		d[a][b]=d[b][a]=min(d[a][b],c);
	}
	
	for (int i=0; i<n; ++i) {
		for (int j=0;j<n; ++j){
			for (int k=j+1; k<n; ++k) {
				if (d[j][i]==MOD || d[i][k]==MOD) continue;
				d[k][j] = d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
			}
		}
	}

	for (int i=0;i<q;++i){
		int a,b;
		cin>>a>>b;
		--a;--b;
		if (d[a][b]!=MOD)
		cout<<d[a][b]<<'\n';
		else cout<<-1<<'\n';
	}
	cout<<'\n';
	return 0;
}