#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF=2e9;

void buildTree(int v, int tl, int tr,vector<int>&st,vector<int>&a){
	if (tl==tr){
		st[v]=a[tl];
		return;
	}
	int mid = (tl+tr)>>1;
	buildTree(v*2,tl,mid,st,a);
	buildTree(v*2+1,mid+1,tr,st,a);
	st[v]=min(st[v*2],st[v*2+1]);
}

int get(int v, int l, int r, int tl, int tr,vector<int>&st){
	if (l>r) return INF;
	if (tl==l&&tr==r)return st[v];
	int mid=(tl+tr)>>1;
	return min(get(v*2,l,min(mid,r),tl,mid,st),get(v*2+1,max(l,mid+1),r,mid+1,tr,st));
}

void update(int v, int tl, int tr, int pos,vector<int>&st,vector<int>&a){
	if (tl==tr){
		st[v]=a[pos];
		return;
	}
	int mid=(tl+tr)>>1;
	if (pos<=mid) update(v*2,tl,mid,pos,st,a);
	else update(v*2+1,mid+1,tr,pos,st,a);
	st[v]=min(st[v*2],st[v*2+1]);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n,q;
	cin>>n>>q;
	vector<int> a1(n),a2(n),a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
		a1[i]=a[i]-i-1;
		a2[i]=a[i]-n+i;
	}
	vector<int>st1(n*4),st2(n*4);
	buildTree(1,0,n-1,st1,a1);
	buildTree(1,0,n-1,st2,a2);
	for (int i=0;i<q;++i){
		int t,pos;cin>>t>>pos;--pos;
		if (t==2){
			int re1=get(1,0,pos,0,n-1,st1)-a1[pos];
			int re2=get(1,pos,n-1,0,n-1,st2)-a2[pos];
			cout<<min(re1,re2)+a[pos]<<'\n';
		}
		else {
			int val;cin>>val;
			a1[pos]+=val-a[pos];
			a2[pos]+=val-a[pos];
			a[pos]=val;
			update(1,0,n-1,pos,st1,a1);
			update(1,0,n-1,pos,st2,a2);
		}
	}
	return 0;
}