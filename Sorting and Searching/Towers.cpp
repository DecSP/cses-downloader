#include <bits/stdc++.h>
using namespace std;
multiset <int> s;
int n;

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>n;
	for (int i=0;i<n;++i){
		int t;cin>>t;
		set<int>::iterator it=s.upper_bound(t);
		if (it!=s.end()) s.erase(it);
		s.insert(t);
	}
	cout<<s.size()<<'\n';
	return 0;
}