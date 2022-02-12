# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<b;i++)
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main(){
	fastio;
	int n,x;
	cin>>n>>x;
	vector <pair<int,int>> a(n);
	REP(i,0,n) {
		cin>>a[i].first;
		a[i].second=i+1;
	}
	sort(all(a));
	for (int l=0,r=n-1;l<r;){
		int s=a[l].first+a[r].first;
		if(s==x){
			cout<<a[l].second<<' '<<a[r].second<<'\n';
			return 0;
		}
		if (s<x) l++;
		else r--;
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}