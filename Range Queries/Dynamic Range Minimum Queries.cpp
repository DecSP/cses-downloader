# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
vector<ll> st;
vector<int> arr;
void build(int v,int tl,int tr){
	if (tl==tr){
		st[v]=arr[tl];
	}
	else{
		int mid=(tl+tr)>>1;
		build(v*2,tl,mid);
		build(v*2+1,mid+1,tr);
		st[v]=min(st[v*2],st[v*2+1]);
	}
}
ll get(int v,int tl,int tr,int l , int r){
	if (tl==l&&tr==r) return st[v];
	if (tl>r||tr<l) return -1;
	int mid=(tl+tr)>>1;
	ll x=get(v*2,tl,mid,l,min(mid,r)),y=get(v*2+1,mid+1,tr,max(l,mid+1),r);
	if (x==-1)return y;
	if (y==-1) return x;
	return min(x,y);

}
void update(int v,int tl,int tr,int & pos,int & val){
	if(tl==tr){
		st[v]=val;
	}
	else {
		int mid = (tl+tr)>>1;
		if (pos<=mid) update(v*2,tl,mid,pos,val);
		else update(v*2+1,mid+1,tr,pos,val);
		st[v]=min(st[v*2],st[v*2+1]);
	}
}
int main(){
	fastio;
	int n,q;
	cin>>n>>q;
	st.assign(4*n,0);
	arr.assign(n,0);
	for (auto & v:arr)cin>>v;
	build(1,0,n-1);
	int k,x,y;
	for (int i=0;i<q;i++){
		cin>>k>>x>>y;
		if (k==2)
		cout<<get(1,0,n-1,x-1,y-1)<<'\n';
		else {
			x--;
			update(1,0,n-1,x,y);
		}
	}
	return 0;
}