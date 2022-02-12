# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define REP(i,a,b) for (int i=a;i<b;i++)
using namespace std;
vector<int>memo;
int findMemo(int t){
	if (memo[t]==-2) return memo[t]=t;
	if (memo[t]<=0) return -1;
	memo[t]--;
	return memo[t]=findMemo(memo[t]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m;
	cin>>n>>m;
	vector <int>  h(n);
	vector<pair<int,int>> t;
	vector<int> re(m,-1);
	memo.assign(n,-2);
	int temp;
	REP(i,0,n)cin>>h[i];
	REP(i,0,m){cin>>temp;t.push_back({temp,i});}
	sort(all(h));
	sort(all(t));
	temp=0;
	for(int i=0;i<n&&temp<m;){
		if(t[temp].first<h[i]){
			re[t[temp].second]=i-1;
			temp++;
		}
		else i++;
	}
	for(;temp<m;temp++) re[t[temp].second]=n-1;
	
	REP(i,0,m){
		if (re[i]==-1) continue;
		re[i]=findMemo(re[i]);
		}
	REP(i,0,m) 
	{
		if (re[i]!=-1)
		cout<<h[re[i]]<<'\n';
		else cout<<-1<<'\n';
	}
	return 0;
}