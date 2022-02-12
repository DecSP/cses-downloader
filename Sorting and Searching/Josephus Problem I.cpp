#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

vector<int> a;
int n;

int root(int x){
	while (a[x]!=x) x=a[x]=a[a[x]];
	return x;
}

int main(){
	fastio;
	cin>>n;
	a.assign(n,0);
	iota(a.begin(),a.end(),0);
	int cnt = 0, i=0;
	while (cnt<n){
		i = root(i);
		i= (i+1)%n;
		i = root(i);
		if (cnt!=0) cout<<' ';
		cout<<i+1;
		a[i]=root((i+1)%n);
		i= (i+1)%n;
		++cnt;
	}	
	cout<<'\n';
    return 0;
}