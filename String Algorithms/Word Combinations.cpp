#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MOD=1000000007;
struct Node{
	int val;
	vector<Node*>child;
public:
	Node():val(0){
		child.assign(26,nullptr);
	};
	Node(int val):val(val)	{
		child.assign(26,nullptr);
	};
	~Node(){
		for (auto x:child)
			if (x) delete(x);
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	string s;cin>>s;
	int n;cin>>n;
	vector<string> aS(n);
	Node * trie=new Node;
	for (string &s1:aS){
		cin>>s1;
		reverse(s1.begin(), s1.end());
		Node **tmp=&trie;
		for (char &c:s1){
			tmp=&((*tmp)->child[c-'a']);
			if((*tmp)==nullptr) *tmp=new Node;
		}
		(*tmp)->val+=1;
	}
	vector<ll> dp(s.size()+1,0);
	dp[0]=1;
	for (int i=1;i<=s.size();++i){
		Node **x=&trie;
		for (int j=i-1;j>=0;--j){
			x=&((*x)->child[s[j]-'a']);
			if (!(*x)) break;
			dp[i]=(dp[i]+dp[j]*((*x)->val)%MOD)%MOD;
		}
	}
	delete trie;
	cout<<dp[(int)s.size()]<<'\n';	
	return 0;
}