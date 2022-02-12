#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
using namespace std;

int main(){
	fastio;
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for (int&v:a){
		string s;
		cin>>s;
		for (int i=0;i<sz(s);++i){
			if (s[i]=='1'){
				v|=1<<(sz(s)-i-1);
			}
		}
	}
	int re=31;
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){

			re=min(re,__builtin_popcount(a[i]^a[j]));
		}
	}
	cout<<re<<'\n';
}
