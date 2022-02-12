# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	fastio;
	int n;cin>>n;
	unordered_map <int,int> s;
	s.reserve(2e5);
	int re=0,temp,c=1,i=1;
	for(;i<=n;i++){
		cin>>temp;
		if (s[temp] && s[temp]>=c){
			re=max(i-c,re);
			c=s[temp]+1;
		}
		s[temp]=i;
	}
	re=max(i-c,re);
	cout<<re<<endl;
	return 0;
}