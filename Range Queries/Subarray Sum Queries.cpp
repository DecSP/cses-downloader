#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
	ll s;
	ll pre;
	ll suf;
	ll re;
};

vector<Node> st;
vector<ll> a;
int n,q;

void buildTree(int v,int tl, int tr){
	if (tl==tr){
		st[v].s=st[v].pre=st[v].suf=st[v].re=a[tl];
		return;
	}
	int mid = (tl+tr)>>1;
	buildTree(v*2,tl,mid);
	buildTree(v*2+1,mid+1,tr);
	st[v].s=st[v*2].s+st[v*2+1].s;
	st[v].pre=max(st[v*2].pre,st[v*2].s+st[v*2+1].pre);
	st[v].suf=max(st[v*2+1].suf,st[v*2+1].s+st[v*2].suf);
	st[v].re=max(max(st[v*2].re,st[v*2+1].re),st[v*2].suf+st[v*2+1].pre);
}

void update(int v,int tl, int tr,int pos,ll val){
	if (tl==tr){
		st[v].s=st[v].pre=st[v].suf=st[v].re=val;
	}
	else {
		int mid =(tl+tr)>>1;
		if (pos<=mid) update(v*2,tl,mid,pos,val);
		else update(v*2+1,mid+1,tr,pos,val);
		st[v].s=st[v*2].s+st[v*2+1].s;
		st[v].pre=max(st[v*2].pre,st[v*2].s+st[v*2+1].pre);
		st[v].suf=max(st[v*2+1].suf,st[v*2+1].s+st[v*2].suf);
		st[v].re=max(max(st[v*2].re,st[v*2+1].re),st[v*2].suf+st[v*2+1].pre);	
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	a.assign(n,0);
	for (int i=0;i<n;++i){
		cin>>a[i];
	}
	st.assign(4*n,Node({0,0,0,0}));
	buildTree(1,0,n-1);
	for (int i=0;i<q;++i){
		ll x,y;cin>>x>>y;--x;
		update(1,0,n-1,x,y);
		cout<<max(st[1].re,0LL)<<'\n';
	}
	return 0;
}