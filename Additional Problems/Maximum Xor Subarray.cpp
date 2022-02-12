#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
using namespace std;

struct Trie{
	struct Node {
		int idx=-1;
		Node* arr[2]={nullptr,nullptr};
	};
	Node* root=new Node;
	void add(int y,int idx){
		Node* cur=root;
		for (int i=20;i>=0;--i){
			if ((1<<i)&y){
				if (!cur->arr[1]) cur->arr[1]=new Node;
				cur=cur->arr[1];
			}
			else {
				if (!cur->arr[0]) cur->arr[0]=new Node;
				cur=cur->arr[0];
			}
		}
		cur->idx=idx;
	}
	int get(int y){
		Node* cur=root;
		for (int i=20;i>=0;--i){
			if (!((1<<i)&y)){
				if (cur->arr[1]!=nullptr) {
					cur=cur->arr[1];
				}
				else {
					cur=cur->arr[0];
				}
			}
			else {
				if (cur->arr[0]!=nullptr) {
					cur=cur->arr[0];
				}
				else {
					cur=cur->arr[1];
				}
			}
		}
		return cur->idx;
	}
};


int main(){
	fastio;
	int n;
	cin>>n;
	vector<int> a(n);
	for (int &v:a) cin>>v;
	vector<int> b(n+1);
	for (int i=0;i<n;++i) b[i+1]=b[i]^a[i];
	Trie t;
	for (int i=0;i<=n;++i) t.add(b[i],i);
	int mx=0;
	for (int i=0;i<=n;++i) {
		mx=max(mx,b[i]^b[t.get(b[i])]);
	}
	cout<<mx<<'\n';
}