# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
vector<int> st;
vector<int> arr;
void build(int v,int tl,int tr){
	if (tl==tr){
		st[v]=arr[tl];
	}
	else{
		int mid=tl+tr>>1;
		build(v*2,tl,mid);
		build(v*2+1,mid+1,tr);
		st[v]=min(st[v*2],st[v*2+1]);
	}
}
int get(int v,int tl,int tr,int l , int r){
	if (tl==l&&tr==r) return st[v];
	if (tl>r||tr<l) return -1;
	int mid=tl+tr>>1;
	int x=get(v*2,tl,mid,l,min(mid,r)),y=get(v*2+1,mid+1,tr,max(l,mid+1),r);
	if (x==-1)return y;
	if (y==-1) return x;
	return min(x,y);

}
int main(){
	fastio;
	int n,q;
	cin>>n>>q;
	st.assign(4*n,0);
	arr.assign(n,0);
	for (auto & v:arr)cin>>v;
	build(1,0,n-1);
	int x,y;
	for (int i=0;i<q;i++){
		cin>>x>>y;
		cout<<get(1,0,n-1,x-1,y-1)<<'\n';
	}
	return 0;
}