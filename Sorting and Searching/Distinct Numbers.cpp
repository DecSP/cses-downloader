# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
vector <int> a(int(2e5)+10);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	REP(i,0,t-1) cin>>a[i];
	sort(a.begin(),a.begin()+t);
	vector<int>::iterator it=unique(a.begin(),a.begin()+t);
	cout<<it-a.begin()<<endl;
	return 0;
}