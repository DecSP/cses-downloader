#include <bits/stdc++.h>
using namespace std;
int n;
void solve(){
	vector<int> r(n);
	for (int&v:r)cin>>v;
	double re=0;
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			for (int a=r[i];a>1;--a){
				re+=1.0*min(a-1,r[j])/r[j]/r[i];
			}
		}
	}
	printf("%.6f\n",re);
}
int main(){
	scanf("%d",&n);
	solve();
	return 0;
}