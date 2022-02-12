#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<array<int,2>> seg;
vector<ll> st;
vector<int> a;
int timer,n,q;
void dfs(int curr,int p){
	seg[curr][0]=timer++;
	for (int &v:adj[curr]){
		if (v==p) continue;
		dfs(v,curr);
	}
	seg[curr][1]=timer++;
}

void buildTree(int v,int tl, int tr){
	if (tl==tr){
		st[v]=a[tl];
	}
	else {
		int mid=(tl+tr)>>1;
		buildTree(v*2,tl,mid);
		buildTree(v*2+1,mid+1,tr);
		st[v]=st[v*2]+st[v*2+1];
	}
}

ll sum(int v, int l,int r, int tl, int tr){
	if (l==tl&&r==tr){
		return st[v];
	}
	if (l>r) return 0;
	int mid=(tl+tr)>>1;
	return sum(v*2,l,min(r,mid),tl,mid)+sum(v*2+1,max(l,mid+1),r,mid+1,tr);
}

void update(int v, int tl, int tr, int pos, int val){
	if (tl==tr){
		st[v]=val;
		return;
	}
	int mid=(tl+tr)>>1;
	if (pos<=mid) update(v*2,tl,mid,pos,val);
	else update(v*2+1,mid+1,tr,pos,val);
	st[v]=st[v*2]+st[v*2+1];
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	vector<int> a1(n);
	for (int&v:a1) cin>>v;
	adj.assign(n,vector<int>());
	for (int i=0;i<n-1;++i){
		int x,y;cin>>x>>y;--x;--y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	seg.assign(n,array<int,2>());
	timer=0;
	dfs(0,0);
	a.assign(timer,0);
	for (int i=0;i<n;++i) a[seg[i][0]]=a1[i];
	st.assign(4*timer,0);
	buildTree(1,0,timer-1);
	for (int i=0;i<q;++i){
		int t;cin>>t;
		if (t==1){
			int s,x;
			cin>>s>>x;--s;
			update(1,0,timer-1,seg[s][0],x);
		}
		else{
			int s;
			cin>>s;--s;
			cout<<sum(1,seg[s][0],seg[s][1],0,timer-1)<<'\n';
		}
	}
	return 0;
}