#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> adj;
vector<array<int,2>> seg,seg1,seg2;
int timer,n,q;
vector<int> a;
ll sA=0;

void dfs(int curr,int p){
	seg[curr][0]=timer++;
	for (int &v:adj[curr]){
		if (v==p) continue;
		dfs(v,curr);
	}

	seg[curr][1]=timer-1;
}

void buildTree(int v,int tl, int tr, vector<int>&a,vector<ll>&st){
	if (tl==tr){
		st[v]=a[tl];
	}
	else {
		int mid=(tl+tr)>>1;
		buildTree(v*2,tl,mid,a,st);
		buildTree(v*2+1,mid+1,tr,a,st);
		st[v]=st[v*2]+st[v*2+1];
	}
}

ll sum(int v, int l,int r, int tl, int tr,vector<ll>&st){
	if (l==tl&&r==tr){
		return st[v];
	}
	if (l>r) return 0;
	int mid=(tl+tr)>>1;
	return sum(v*2,l,min(r,mid),tl,mid,st)+sum(v*2+1,max(l,mid+1),r,mid+1,tr,st);
}

void update(int v, int tl, int tr, int pos, int val,vector<ll>&st){
	if (tl==tr){
		st[v]=val;
		return;
	}
	int mid=(tl+tr)>>1;
	if (pos<=mid) update(v*2,tl,mid,pos,val,st);
	else update(v*2+1,mid+1,tr,pos,val,st);
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
	seg1.assign(n,array<int,2>());
	seg2.assign(n,array<int,2>());
	timer=0;
	dfs(0,0);
	a.assign(n,0);
	
	for (int i=0;i<n;++i){
		a[seg[i][0]]=a1[i];
		sA+=a1[i];

		seg1[i]=seg[i];
		seg2[i]={seg[i][1],seg[i][0]};
	}

	sort(seg1.begin(),seg1.end());sort(seg2.begin(),seg2.end());
	vector<int> pref(n);
	for (int i=0;i<n;++i) pref[i]=a[seg2[i][1]];

	vector<ll> st1(4*n),st2(4*n);
	buildTree(1,0,n-1,a,st1);
	buildTree(1,0,n-1,pref,st2);

	for (int i=0;i<q;++i){
		int t,s;cin>>t>>s;
		--s;
		int pos=seg[s][0];
		if (t==1){
			int x;
			cin>>x;
			int prepos=lower_bound(seg2.begin(),seg2.end(),array<int,2>({seg[s][1],seg[s][0]}))-seg2.begin();
			update(1,0,n-1,pos,x,st1);
			update(1,0,n-1,prepos,x,st2);
			sA=sA-a[pos]+x;
			a[pos]=x;
		}
		else{
			int prepos=lower_bound(seg2.begin(),seg2.end(),array<int,2>({seg[s][0],0}))-seg2.begin();
			cout<<sA-sum(1,pos+1,n-1,0,n-1,st1)-sum(1,0,prepos-1,0,n-1,st2)
			<<'\n';
		}
	}
	return 0;
}