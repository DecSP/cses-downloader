# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
using namespace std;
bool comp(int x,int y){
	return x>y;
}
int main(){
	fastio;
	int n,tmp;cin>>n;
	vector <pair<pair<int,int>,int>> a(2*n);
	vector <int> re(n);
	for (int i=0;i<2*n;i+=2){
		cin>>a[i].first.first>>a[i+1].first.first;
		a[i].first.second=-1;a[i+1].first.second=1;
		a[i].second=a[i+1].second=i/2;
	}
	sort(all(a));
	int num=1,roomid;
	set <int> remainRooms;
	for (auto v:a){
		tmp=v.first.second;
		roomid=v.second;
		if (tmp==-1) {
			if (remainRooms.size()>0) {
				re[roomid]=*remainRooms.begin();
				remainRooms.erase(remainRooms.begin());
			}
			else re[roomid]=num++;
		}
		else{
			remainRooms.insert(re[roomid]);
		}
	}
	cout<<num-1<<'\n';
	cout<<re[0];
	for (int i=1;i<n;i++)cout<<' '<<re[i];
	cout<<'\n';
	return 0;
}