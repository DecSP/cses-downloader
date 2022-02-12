# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
vector <ll> st;
vector <int> arr;
int n;


void update(int v, int tl ,int tr, int l , int r, int val){
	if(tl==l&&tr==r) {
		st[v]+=val;
		return;
	}
	if (tl>r||tr<l) return;
	int mid=(tl+tr)>>1;
	update(v*2,tl,mid,l,min(mid,r),val);
	update(v*2+1,mid+1,tr,max(mid+1,l),r,val);	
}

ll get(int v, int tl ,int tr, int pos){
	if(tl==tr) return st[v];
	int mid=(tl+tr)>>1;
	ll re=st[v];
	if (mid>=pos)return re+get(v*2,tl,mid,pos);
	else return re+get(v*2+1,mid+1,tr,pos);
}

int main(){
	fastio;
	int q;
	cin>>n>>q;
	arr.assign(n,0);
	st.assign(4*n,0);
	for (auto&v:arr)cin>>v;
	int k,a,b,u,pos;
	for (int i=0;i<q;i++){
		cin>>k;
		if (k==1) {
			cin>>a>>b>>u;
			update(1,0,n-1,a-1,b-1,u);
		}
		else{
			cin>>pos;
			pos--;
			cout<<get(1,0,n-1,pos)+arr[pos]<<'\n';
		}
	}
	return 0;
}