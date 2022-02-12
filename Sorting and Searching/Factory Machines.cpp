# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main(){
	fastio;
	int n,t;
	cin>>n>>t;
	double s=0;
	vector <int> arr(n);
	for (int i=0;i<n;i++){
		cin>>arr[i];
		s+=1.0/arr[i];
	}
	long long base=(double)t/s;
	long long curr=0;
	multiset <pair<int,int>> rem;
	for (int i=0;i<n;i++){
		curr+=base/arr[i];
		rem.insert({arr[i]-base%arr[i],arr[i]});
	}
	long long re=base;
	pair<int,int> tmp={0,0};
	for(;curr<t;curr++){
		tmp=(*(rem.begin()));
		rem.insert({tmp.first+tmp.second,tmp.second});
		rem.erase(rem.begin());
	}
	re+=tmp.first;
	cout<<re<<'\n';
	return 0;
}