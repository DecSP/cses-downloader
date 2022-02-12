# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
const ll MOD=1000000007;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x;
	cin>>n>>x;
	vector<int> arr(n);
	REP(i,0,n-1)cin>>arr[i];
	sort(arr.begin(),arr.end());
	int l=0,r=n-1,c=0;
	while(l<r){
		if(arr[l]+arr[r]<=x){
			l++;r--;
		}
		else r--;
		c++;
	}
	if (l==r) c++;
	cout<<c<<endl;
	return 0;
}