#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m;
vector<int> a;
vector<int> st;
void buildTree(int v,int tl, int tr){
	if (tl==tr){
		st[v]=a[tl];
	}
	else{
		int mid = (tl+tr)>>1;
		buildTree(v*2,tl,mid);
		buildTree(v*2+1,mid+1,tr);
		st[v]=max(st[v*2],st[v*2+1]);
	}
}
int get(int v,int l, int r, int tl, int tr){
	if (l==tl&&r==tr){
		return st[v];
	}
	if (l>r) return -1;
	int mid=(tl+tr)>>1;
	return max(get(v*2,l,min(mid,r),tl,mid),get(v*2+1,max(l,mid+1),r,mid+1,tr));
}
void update(int v,int tl, int tr, int val,int pos){
	if (tl==tr){
		st[v]=val;
		return;
	}
	int mid=(tl+tr)>>1;
	if (pos<=mid) update(v*2,tl,mid,val,pos);
	else update(v*2+1,mid+1,tr,val,pos);
	st[v]=max(st[v*2],st[v*2+1]);
}

int getPos(int tg){
	if (st[1]<tg) return 0;
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
	int nval=get(1,0,l,0,n-1)-tg;
	assert(nval>=0);
	update(1,0,n-1,nval,l);
	return l+1;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>m;
	a.assign(n,0);
	st.assign(4*n,0);
	for (int i=0;i<n;++i) {
		cin>>a[i];
	}
	buildTree(1,0,n-1);
	for (int i=0;i<m;++i){
		int r;cin>>r;
		cout<<getPos(r)<<' ';
	}
	return 0;
}
//  2 3 4 2 1 8