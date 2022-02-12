# include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector <int> nums (n+1);
	int temp;
	for (int i=0;i<n-1;i++){cin>>temp;nums[temp]=1;}
	for (int i=1;i<=n;i++) if (!nums[i]){cout<<i;break;}
	return 0;
}