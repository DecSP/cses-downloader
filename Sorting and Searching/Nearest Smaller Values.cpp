# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
int main(){
	fastio;
	int n,tmp,pre;
	cin>>n;
	vector <int> dsu (n+1);
	iota(all(dsu),-1);
	vector <int> s(n);
	cin>>s[0];cout<<0;
	for (int i=1;i<n;i++){
		cin>>s[i];
		while (dsu[i]!=-1&&s[dsu[i]]>=s[i]){
			dsu[i]=dsu[dsu[i]];
		}
		cout<<' '<<dsu[i]+1;
	}
	cout<<'\n';
	return 0;
}