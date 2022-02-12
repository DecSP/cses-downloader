#include<bits/stdc++.h> 
using namespace std; 
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	long long x,y;
	cin>>t;
	for (int i=0;i<t;i++){
		cin>>x>>y;
		long long m=max(x,y);
		if (m%2) swap(x,y);
		cout<<m*m-(m-x+y-1)<<'\n';
	}
	return 0; 
} 