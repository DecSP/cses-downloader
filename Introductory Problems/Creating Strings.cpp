# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int k=1;
	unordered_map <char,int> m;
	cin>>s;
	for (int i=1;i<=s.size();i++)k*=i;
	for (auto c:s) m[c]++;
	for (auto p:m){for(int i=2;i<=p.second;i++)k/=i;}
	sort(all(s));
	cout<<k<<endl;
	do{
		cout<<s<<endl;
	}
	while (next_permutation(all(s)));
	return 0;
}