#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{
	ll pre;
	ll addend;
};

vector<Node> st;
vector<ll> a;
int n,q;

void buildTree(int v,int tl, int tr){
	if (tl==tr){
		st[v].pre=a[tl];
		return;
	}
	int mid = (tl+tr)>>1;
	buildTree(v*2,tl,mid);
	buildTree(v*2+1,mid+1,tr);
	st[v].pre=max(st[v*2].pre,st[v*2+1].pre);
}

void push(int v) {
	st[v*2].pre+=st[v].addend;
	st[v*2+1].pre+=st[v].addend;
	st[v*2].addend+=st[v].addend;
	st[v*2+1].addend+=st[v].addend;
	st[v].addend=0;	
}

ll get(int v, int l, int r, int tl, int tr){
	if(tl==l&&tr==r){
		return st[v].pre;
	}
	if (l>r) return -1e18;
	push(v);
	int mid = (tl+tr)>>1;
	return max(get(v*2,l,min(r,mid),tl,mid),get(v*2+1,max(mid+1,l),r,mid+1,tr));
}

void update(int v, int l, int r, int tl, int tr, int add){
	if (l>r) return;
	if (l==tl&&r==tr) {
		st[v].pre+=add;
		st[v].addend+=add;
	}
	else {
		push(v);
		int mid =(tl+tr)>>1;
		update(v*2,l,min(r,mid),tl,mid,add);
		update(v*2+1,max(l,mid+1),r,mid+1,tr,add);
		st[v].pre=max(st[v*2].pre,st[v*2+1].pre);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	a.assign(n,0);
	vector<int>v(n);
	for (int i=0;i<n;++i){
		cin>>v[i];
		a[i]=v[i];
		if (i) a[i]+=a[i-1];
	}
	st.assign(4*n,Node({0,0}));
	buildTree(1,0,n-1);
	for (int i=0;i<q;++i){
		int t;cin>>t;
		if (t==2){
			int x,y;cin>>x>>y;--x;--y;
			ll re=get(1,x,y,0,n-1);
			if (x) re-=get(1,x-1,x-1,0,n-1);
			cout<<max(re,0LL)<<'\n';
		}
		else{
			assert(t==1);
			int k,u;
			cin>>k>>u;--k;
			update(1,k,n-1,0,n-1,u-v[k]);
			v[k]=u;
		}
	}
	return 0;
}