# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;
bool comp(int x,int y){
	return x>y;
}
int main(){
	fastio;
	int x,n,tmp;cin>>x>>n;
	map <int,int> s;
	cin>>tmp;
	set <int> m={0,tmp,x};
	s[x-tmp]++;s[tmp]++;
	cout<<(*s.rbegin()).first;
	for (int i=1;i<n;i++){
		cin>>tmp;
		auto it2=m.upper_bound(tmp);
		auto it=it2--;
		int olddis=*it-*it2;
		auto sit=s.find(olddis);
		--(*sit).second;
		if ((*sit).second==0) s.erase(sit);
		s[*it-tmp]++;s[tmp-*it2]++;
		m.insert(tmp);
		cout<<' '<<(*s.rbegin()).first;
	}
	cout<<'\n';
	return 0;
}