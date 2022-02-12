#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<int> st;
int n,k;

void update(int tl, int tr, int idx,int val, int curr){
	if (tl>idx || tr <idx) return;
	if (tl==tr) {
		st[curr]=val;
		return;
	}
	int mid = (tl+tr)/2;
	update(tl,mid,idx,val,curr*2);
	update(mid+1,tr,idx,val,curr*2+1);
	st[curr]=st[curr*2]+st[curr*2+1];
}

int get(int tl, int tr, int l, int r, int curr){
	if (l>r) return 0;
	if (tl==l && tr==r) return st[curr];
	int mid = (tl+tr)/2;
	return get(tl,mid,l,min(r,mid),curr*2)+get(mid+1,tr,max(l,mid+1),r,curr*2+1);
}

int getIdx(int vtidx){
	int l=0,r=n-1;
	while (l<r){
		int mid = (l+r)/2;
		int x=get(0,n-1,0,mid,1);
		if (x>=vtidx+1) r=mid;
		else l=mid+1;
	}
	return l;
}

int main(){
	fastio;
	cin>>n>>k;
	st.assign(4*n,0);
	for (int i=0;i<n;++i){
		update(0,n-1,i,1,1);
	}
	int prev=0;
	while (st[1]) {
		int i;
		for (i=(k-prev)%st[1];i<st[1];i+=k%st[1]) {
			int x=getIdx(i);
			update(0,n-1,x,0,1);
			cout<<x+1;
			if (st[1]==0) break;
			cout<<' ';
			prev=st[1]-i;
		}
	}
	cout<<'\n';
    return 0;
}