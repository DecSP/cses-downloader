#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

const int INF=1e9;

int n,q;
vector<int>a;
vector<int>p;
vector<ll>acu;
vector<ll> F;

ll sumr(int l, int r){
	return acu[r+1]-acu[l];
}

ll sum(int idx){
	ll re=0;
	for (int i=idx;i>=0;i=(i&(i+1))-1){
		re+=F[i];
	}
	return re;
}

ll sum(int l,int r){
	return sum(r)-sum(l-1);
}

void increase(int idx, ll add){
	for (int i=idx;i<n;i=(i|(i+1))){
		F[i]+=add;
	}
}

int main(){
	fastio;
	cin>>n>>q;
	a.assign(n,0);
	F.assign(n,0);
	p.assign(n,-1);
	acu.assign(n+1,0);
	for (int i=0;i<n;++i){
		cin>>a[i];
		acu[i+1]=acu[i]+a[i];
	}
	
	vector<array<int,2>> st;
	for (int i=0;i<n;++i){
		while (st.size()&&st.back()[0]<a[i]){
			p[st.back()[1]]=i-1;
			st.pop_back();
		}
		st.push_back({a[i],i});
	}
	while (st.size()){
		p[st.back()[1]]=n-1;
		st.pop_back();
	}
	
	deque<int> ans;
	for (int i=0;i<n;i=p[i]+1){
		ans.push_back(i);
		increase(i,1LL*(p[i]-i+1)*a[i]);
	}
	vector<array<int,3>> query;
	for (int i=0;i<q;++i){
		int l,r;cin>>l>>r;--l;--r;
		query.push_back({l,r,i});
	}
	sort(query.begin(),query.end());
	
	stack<int>tmp;
	vector<ll> re(q,-1);
	for (int i=0;i<q;++i){
		int l=query[i][0],r=query[i][1],idx=query[i][2];
		while (l>ans[0]){
			int cur=ans[0]+1;
			ans.pop_front();
			int nxt=(ans.size()>0)?ans[0]:n;
			while (cur<nxt){
				tmp.push(cur);
				increase(cur,1LL*(p[cur]-cur+1)*a[cur]);
				cur=p[cur]+1;
			}
			while (!tmp.empty()){
				ans.push_front(tmp.top());
				tmp.pop();
			}
		}
		auto it=upper_bound(ans.begin(),ans.end(),r);
		int e=ans[prev(it)-ans.begin()];
		re[idx]=sum(l,r)-1LL*a[e]*(p[e]-r)-sumr(l,r);
		
	}
	for (int i=0;i<q;++i) cout<<re[i]<<'\n';
	
}