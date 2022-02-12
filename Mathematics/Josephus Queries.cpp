#include <bits/stdc++.h>
using namespace std;

int solve(int n,int k){
	int curr=n,cnt=0,f=2,step=1,s=1;
	while (k>cnt+(curr+2-f)/2){
		int tmp=(curr+2-f)/2;
		cnt+=tmp;
		if (f==1) s+=(1<<(step-1));
		if (curr%2) f=3-f;
		curr-=tmp;
		++step;
	}
	if (f==2) s+=(1<<(step-1));	
	return s+(1<<step)*(k-cnt-1);
}

int main(){
	// ios::sync_with_stdio(false);cin.tie(NULL);
	int q;
	cin>>q;
	for (int i=0;i<q;++i){
		int n,k;
		cin>>n>>k;
		cout<<solve(n,k)<<'\n';
	}
	return 0;
}