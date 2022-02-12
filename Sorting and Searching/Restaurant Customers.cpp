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
	vector<pair<int,int>>a;
	int temp;
	REP(i,0,n) {
		cin>>temp;a.push_back({temp,1});
		cin>>temp;a.push_back({temp,-1});
	}
	sort(all(a));
	int re=0, c=0;
	for (auto p:a){
		c+=p.second;
		re=max(re,c);
	}
	cout<<re<<endl;
	return 0;
}