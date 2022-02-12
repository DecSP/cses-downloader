#include <bits/stdc++.h>
#define ll long long
#define fastio ios::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
const int MOD = 1000000007;

int main(){
	fastio;
	int n,x;
	cin>>n>>x;
	vector<pair<int,int>> arr(n);
	for (int i=0;i<n;++i) {
		cin>>arr[i].first;
		arr[i].second=i+1;
	}
	sort(arr.begin(),arr.end());
	for (int l1=0;l1<n;++l1){
	for (int r1=l1+3;r1<n;++r1){
		int l2=l1+1,r2=r1-1;
		int tmp=arr[l1].first+arr[r1].first;
		while (l2<r2){
			int curr=arr[l2].first+arr[r2].first+tmp;
			if (curr==x) {
				cout<<arr[l1].second<<' '<<arr[l2].second<<' '<<arr[r2].second<<' '<<arr[r1].second<<'\n';
				return 0;
			}
			else if (curr<x) ++l2;
			else --r2;
		}
	}
	}
	cout<<"IMPOSSIBLE\n";
    return 0;
}