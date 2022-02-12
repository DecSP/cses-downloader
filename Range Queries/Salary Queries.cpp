#include <bits/stdc++.h>
#define ll long long
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree<array<int,2>, null_type,less<array<int,2>>, rb_tree_tag,tree_order_statistics_node_update> 

int n,q;
vector<int> v;
ordered_set s;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n>>q;
	v.assign(n,0);
	for (int i=0;i<n;++i) {
		cin>>v[i];
		s.insert({v[i],i});
	}
	for (int i=0;i<q;++i){
		char t;cin>>t;
		if (t=='?'){
			int x,y;cin>>x>>y;
			auto e=s.upper_bound({y+1,-1});
			auto b=s.upper_bound({x,-1});
			int ePos=n;
			if (e!=s.end()) ePos=s.order_of_key((*e));
			cout<<ePos - (int)s.order_of_key(*b)<<'\n';
		}
		else {
			assert(t=='!');
			int x,y;cin>>x>>y;--x;
			auto it=s.find({v[x],x});
			assert(it!=s.end());
			s.erase(it);
			v[x]=y;
			s.insert({v[x],x});
		}
	}
	return 0;
}
