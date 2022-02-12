#include <bits/stdc++.h>
using namespace std;
string t;
int n;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>t;
	n=t.size();
	vector<int>z(n,0);
	for (int i=1,l=0,r=0;i<n;++i){
		if (i<=r) z[i]=min(r-i+1,z[i-l]);
		while (i+z[i]<n && t[z[i]]==t[z[i]+i]) ++z[i];
		if (z[i]+i-1>r){
			r=z[i]+i-1;
			l=i;
		}
		if (z[i]+i==n) cout<<i<<' ';
	}
	cout<<n<<'\n';
	return 0;
}