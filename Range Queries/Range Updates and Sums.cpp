#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define sz(x) (int)((x).size())
#define ll long long
using namespace std;

const ll M=998244353LL;
struct Node{
	ll s,a,inc;
    Node(ll s,ll a,ll inc){
        this->s=s;
        this->a=a;
        this->inc=inc;
	}
};
    
struct ST{
	vector<ll> a;
	vector<Node> st;
	ll n;
    ST(vector<ll>&a,ll n){
        st.assign(n*4,Node(0,0,0));
        this->a=a;
        buildTree(0,n-1,1);
	}
    void buildTree(ll tl,ll tr,ll v){
        if (tl==tr){
            st[v]=Node(a[tl],0,0);
            return;
		}
        ll mid=(tl+tr)>>1;
        buildTree(tl,mid,v*2);
        buildTree(mid+1,tr,v*2+1);
        st[v].s=st[v*2].s+st[v*2+1].s;
	}
    void ass(ll tl,ll tr,ll l,ll r,ll v,ll val){
        if (l>r) return;
        push(v,tr-tl+1);
        if (tl==l && tr==r){
            st[v].a=val;
            st[v].s=val*(r-l+1);
            return;
		}
        ll mid=(tl+tr)>>1;
        ass(tl,mid,l,min(mid,r),v*2,val);
        ass(mid+1,tr,max(mid+1,l),r,v*2+1,val);
        st[v].s=st[v*2].s+st[v*2+1].s;
	}
	void add(ll tl,ll tr,ll l,ll r,ll v,ll val){
        if (l>r) return;
        push(v,tr-tl+1);
        if (tl==l && tr==r){
            st[v].inc=val;
            st[v].s+=val*(r-l+1);
            return;
		}
        ll mid=(tl+tr)>>1;
        add(tl,mid,l,min(mid,r),v*2,val);
        add(mid+1,tr,max(mid+1,l),r,v*2+1,val);
        st[v].s=st[v*2].s+st[v*2+1].s;
	}
    ll query(ll tl,ll tr,ll l,ll r,ll v){
        if (l>r) return 0;
        if (tl==l && tr==r) return st[v].s;
        push(v,tr-tl+1);
        ll mid=(tl+tr)>>1;
        ll re=0;
        re+=query(tl,mid,l,min(mid,r),v*2);
        re+=query(mid+1,tr,max(mid+1,l),r,v*2+1);
        return re;
	}
    void push(ll v,ll n){
        if (n==1) return;
        if (st[v].a){
            st[v*2].a=st[v*2+1].a=st[v].a;
            st[v*2].s=(n+1)/2*st[v].a;
			st[v*2+1].s=n/2*st[v].a;
            st[v].a=0;
			st[v*2].inc=st[v*2+1].inc=0;
		}
		else if (st[v].inc){
            st[v*2].inc+=st[v].inc;
			st[v*2+1].inc+=st[v].inc;
            st[v*2].s+=(n+1)/2*st[v].inc;
			st[v*2+1].s+=n/2*st[v].inc;
            st[v].inc=0;
			if (st[v*2].a){
				st[v*2].a+=st[v*2].inc;
				st[v*2].inc=0;
			}
			if (st[v*2+1].a){
				st[v*2+1].a+=st[v*2+1].inc;
				st[v*2+1].inc=0;
			}
		}
	}
};
int main(){
	fastio;
	int n,q;cin>>n>>q;
	vector<ll> a(n);
	for (auto &v:a) cin>>v;
	ST st=ST(a,n);
	for (ll i=0;i<q;++i){
		int t,x,y;cin>>t>>x>>y;
		if (t==3){
			cout<<st.query(0,n-1,x-1,y-1,1)<<'\n';
		}
		else if (t==1){
			int z;cin>>z;
			st.add(0,n-1,x-1,y-1,1,z);
		}
		else {
			int z;cin>>z;
			st.ass(0,n-1,x-1,y-1,1,z);
		}
	}
}