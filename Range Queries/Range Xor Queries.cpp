# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
vector <int> st;
vector <int> arr;
int n;

void build(int v,  int tl,int tr){
	if (tl==tr){
		st[v]=arr[tl];
	}
	else{
		int mid = (tl+tr)>>1;
		build(v*2,tl,mid);
		build(v*2+1,mid+1,tr);
		st[v]=st[v*2]^st[v*2+1];
	}
}

int get(int v, int tl ,int tr, int l , int r){
	if(tl==l&&tr==r) return st[v];
	if (tl>r||tr<l) return 0;
	int mid=(tl+tr)>>1;
	return get(v*2,tl,mid,l,min(mid,r))^get(v*2+1,mid+1,tr,max(mid+1,l),r);	
}

int main(){
	fastio;
	int q;
	cin>>n>>q;
	arr.assign(n,0);
	st.assign(4*n,0);
	for (auto&v:arr)cin>>v;
	build(1,0,n-1);
	int a,b;
	for (int i=0;i<q;i++){
		cin>>a>>b;
		cout<<get(1,0,n-1,a-1,b-1)<<'\n';
	}
	return 0;
}