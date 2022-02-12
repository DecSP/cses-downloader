#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for (int&v:arr)cin>>v;

	vector<int> lastNum;
	for (int i=0;i<n;++i) {
		auto it = lower_bound(lastNum.begin(),lastNum.end(),arr[i]);
		if (it!=lastNum.end()){
			*it=arr[i];
		}
		else {
			lastNum.push_back(arr[i]);
		}
	}
	cout<<lastNum.size()<<'\n';
}