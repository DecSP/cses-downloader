#include <bits/stdc++.h>
using namespace std;
string t;
int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>t;
	vector<int>pi(t.size()+1,-1);
	for (int i=1;i<=t.size();++i){
		int k=pi[i-1];
		while (k>=0&& t[i-1]!=t[k]) k=pi[k];
		pi[i]=k+1;
	}
	int k=pi[t.size()];
	vector<int> re;
	while (k>0){
		re.push_back(k);
		k=pi[k];
	}
	for (int i=1;i<=re.size();++i){
		cout<<re[re.size()-i]<<' ';
	}
	return 0;
}