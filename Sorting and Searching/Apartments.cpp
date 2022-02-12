# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<=b;i++)
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	vector <int> narr(n);
	vector <int> marr(m);
	REP(i,0,n-1) cin>>narr[i];
	REP(i,0,m-1) cin>>marr[i];
	sort(narr.begin(),narr.end());
	sort(marr.begin(),marr.end());
	int cn=n-1,cm=m-1,c=0;
	while (cn>=0&&cm>=0){
		if (abs(narr[cn]-marr[cm])<=k) {
			cm--;cn--;c++;
		}
		else {
			if (narr[cn]>marr[cm]+k) cn--;
			else cm--;	
		}
	}
	cout<<c<<endl;
	return 0;
}