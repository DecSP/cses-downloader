#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll l[20];
ll gett(int idx,int ck,int cnt,ll curr){
	if (cnt==ck)
		return n/curr;
	if (idx==k)
		return 0;
	if (n/l[idx]+1<curr) return gett(idx+1,ck,cnt,curr);
	return gett(idx+1,ck,cnt,curr)+ gett(idx+1,ck,cnt+1,curr*l[idx]);
}
int main(){
	cin>>n>>k;
	for (int i=0;i<k;++i)cin>>l[i];
	ll re=0;
	ll tmp=1;
	for (int i=1;i<=k;++i){
		re+=tmp*gett(0,i,0,1);
		tmp*=-1;
	}
	cout<<re<<'\n';
	return 0;
}