#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
vector<int> a,F;
map<int,int> lvis;

void increase(int pos, int add){
	for (int i=pos;i<n;i=i|(i+1)){
		F[i]+=add;
	}
}

int sum1(int x){
	int re=0;
	for (int i=x;i>=0;i=(i&(i+1))-1){
		re+=F[i];
	}
	return re;
}
int sum(int l,int r){
	return sum1(r)-sum1(l-1);
}

int main(){
	cin>>n>>q;
	a.assign(n,0);
	for (int &v:a) cin>>v;
	vector<array<int,3>> Q(q);
	for (int i=0;i<q;++i){
		cin>>Q[i][1]>>Q[i][0];
		Q[i][2]=i;
		--Q[i][1];--Q[i][0];
	}
	sort(Q.begin(),Q.end());
	vector<int> ans(q);
	int curr=0;
	F.assign(n,0);
	for (auto &qu:Q){
		while (curr<=qu[0]) {
			int x=lvis[a[curr]];
			if (x) {
				increase(x-1,-1);
			}
			lvis[a[curr]]=curr+1;
			increase(curr,1);
			++curr;
		}
		ans[qu[2]]=sum(qu[1],qu[0]);
	}
	for (int &r:ans) cout<<r<<'\n';
	return 0;
}