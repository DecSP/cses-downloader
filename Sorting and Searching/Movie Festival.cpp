# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<b;i++)
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int main(){
	fastio;
	int n;
	cin>>n;
	vector<pair<int,int>>a(n);
	REP(i,0,n) cin>>a[i].second>>a[i].first;
	sort(all(a));
	int re=1, end=a[0].first;
	REP(i,1,n){
		if (a[i].second>=end){
			re++;end=a[i].first;
		}
	}
	cout<<re<<endl;
	return 0;
}