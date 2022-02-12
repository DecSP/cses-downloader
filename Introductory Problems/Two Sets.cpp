#include<bits/stdc++.h> 
using namespace std; 
void printArr(vector <int> & x){
	cout<<x.size()<<'\n'<<x[0];
	for (int i=1;i<x.size();i++){
		cout<<' '<<x[i];
	}
	cout<<'\n';
}
int main() 
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector <int> nums,nums2;
	if (n%4!=0&&n%4!=3) {
		cout<<"NO"<<'\n';
	}
	else{
		cout<<"YES\n";
		if (n%4==0){
			for (int i=1;i<=n/4;i++)	
				{nums.push_back(i);nums.push_back(n-i+1);} 
			printArr(nums);
			nums={};
			for (int i=n/4+1;i<=n/2;i++)	
				{nums.push_back(i);nums.push_back(n-i+1);}
			printArr(nums);
		}
		else{
			int i;
			nums2.push_back(1);
			for(i=0;i<(n+1)/4;i++){
				nums.push_back(2*(i+1)+1);
				nums2.push_back(2*(i+1));
			}
			for (;i<n/2;i++){
				nums.push_back(2*(i+1));
				nums2.push_back(2*(i+1)+1);
			}
			printArr(nums);printArr(nums2);
		}
	}
	return 0; 
} 