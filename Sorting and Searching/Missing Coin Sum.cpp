#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
	fastio;
	int n;
	cin>>n;
	vector<int> a(n);
	for (int &v:a)cin>>v;
	sort(a.begin(),a.end());
	ll s=0;
	for (int &v:a){
		if (v>s+1) {
			cout<<s+1<<'\n';
			return 0;
		}
		s+=v;
	}
	cout<<s+1<<'\n';
    return 0;
}