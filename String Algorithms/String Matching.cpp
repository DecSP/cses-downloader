#include <bits/stdc++.h>
using namespace std;
string s,t;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>s>>t;
	vector<int>pi(t.size()+1,-1);
	for (int i=1;i<=t.size();++i){
		int k=pi[i-1];
		while (k>=0&& t[i-1]!=t[k]) k=pi[k];
		pi[i]=k+1;
	}
	int re=0,pre=0;
	for (int i=0;i<s.size();++i){
		while (pre>=0&&t[pre]!=s[i]) pre=pi[pre];
		++pre;
		if (pre==t.size()){
			++re;
			pre=pi[pre];
		} 
	}
	cout<<re<<'\n';
	return 0;
}