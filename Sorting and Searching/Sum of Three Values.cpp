# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;
int main(){
	fastio;
	int n,x;
	cin>>n>>x;
	vector <pair<int,int>> a(n),b;
	for (int i=1;i<=n;i++){
		cin>>a[i-1].first;
		a[i-1].second=i;
	}
	sort(all(a));
	for (int i=0;i<n;i++){
		auto a1=a[i];
		int tg=x-a1.first,l=i+1,r=n-1;
		while(l<r){
			int tmp=a[l].first+a[r].first;
			if (tmp>tg)r--;
			else if (tmp<tg) l++;
			else{
				cout<<a1.second<<' '<<a[l].second<<' '<<a[r].second<<'\n';
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE\n";
	return 0;
}