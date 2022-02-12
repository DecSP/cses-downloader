#include<bits/stdc++.h> 
using namespace std; 
long long sol(int n){
	switch(n){
		case 1:
			return 0;
		case 2:
			return 0;
		case 3:
			return 8;
		default:
			return 16*(n-2)-8+sol(n-2);
	}
}
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for (long long i=1;i<=n;i++){
		cout<<i*i*(i*i-1)/2-sol(i)<<'\n';
	}
	return 0; 
} 