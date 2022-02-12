#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF=1e9;
int main() {
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	vector<array<int,2>> a(n);
	vector<array<int,3>> b(n);
	vector<array<int,3>> c(n);
	vector<int> yidx(n);
	for (int i=0;i<n;++i) {
		cin>>a[i][0]>>a[i][1];
		b[i][0]=a[i][0];b[i][1]=-a[i][1];b[i][2]=i;
		c[i][0]=a[i][1];c[i][1]=-a[i][0];c[i][2]=i;
	}
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	for (int i=0;i<n;++i) yidx[b[i][2]]=i;
	int mx=-INF;
	vector<array<int,2>> s;
	fill(a.begin(),a.end(),array<int,2>({0,0}));
	for (int i=0;i<n;++i){
		array<int,2>cur={yidx[c[i][2]],c[i][2]};
		while (s.size()&&s.back()[0]>cur[0]){
			a[s.back()[1]][1]=1;
			a[cur[1]][0]=1;
			s.pop_back();
		}
		a[cur[1]][0]=cur[0]<mx;
		mx=max(mx,cur[0]);
		s.push_back(cur);
	}
	for (int i=0; i<n; ++i){
		if (i!=0) cout<<' ';
		cout<<a[i][0];
	}
	cout<<'\n';

	for (int i=0; i<n; ++i){
		if (i!=0) cout<<' ';
		cout<<a[i][1];
	}
	cout<<'\n';
	return 0;
}