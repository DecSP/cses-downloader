#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
vector<int> a;
vector<int> v;
vector<int> st;
void buildTree(int v,int tl, int tr){
	if (tl==tr){
		st[v]=a[tl];
	}
	else{
		int mid = (tl+tr)>>1;
		buildTree(v*2,tl,mid);
		buildTree(v*2+1,mid+1,tr);
		st[v]=st[v*2]+st[v*2+1];
	}
}
int get(int v,int l, int r, int tl, int tr){
	if (l==tl&&r==tr){
		return st[v];
	}
	if (l>r) return 0;
	int mid=(tl+tr)>>1;
	return get(v*2,l,min(mid,r),tl,mid)+get(v*2+1,max(l,mid+1),r,mid+1,tr);
}
void update(int v,int tl, int tr, int val,int pos){
	if (tl==tr){
		st[v]=val;
		return;
	}
	int mid=(tl+tr)>>1;
	if (pos<=mid) update(v*2,tl,mid,val,pos);
	else update(v*2+1,mid+1,tr,val,pos);
	st[v]=st[v*2]+st[v*2+1];
}

int getVal(int tg){
	int l=0,r=n-1;
	while (l<=r){
		int mid = (l+r)>>1;
		int mx=get(1,0,mid,0,n-1);
		if (mx>=tg) {
			r=mid-1;
		}
		else {
			l=mid+1;
		}
	}
	update(1,0,n-1,0,l);
	return v[l];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n;
	a.assign(n,1);
	v.assign(n,0);
	st.assign(4*n,0);
	for (int i=0;i<n;++i) {
		cin>>v[i];
	}
	buildTree(1,0,n-1);
	for (int i=0;i<n;++i){
		int r;cin>>r;
		cout<<getVal(r)<<' ';
	}
	return 0;
}
