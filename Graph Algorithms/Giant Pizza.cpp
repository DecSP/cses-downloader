#include<bits/stdc++.h>
using namespace std;

int n,q;
vector<vector<int>> neg,pos;
vector<int> ans1,ans2;

bool dfs(int cur, bool isPos,vector<int>&ans){
	bool re=true;
	if (ans[cur]) return (ans[cur]>0&&isPos)||(ans[cur]<0&&!isPos);
	ans[cur]=(isPos)?1:-1;
	if (isPos) {
		for(int &v:pos[cur]){
			if (v>0) re=re&&dfs(v-1,true,ans);
			else re=re&&dfs(abs(v)-1,false,ans);
		}
	}
	else {
		for(int &v:neg[cur]){
			if (v>0) re=re&&dfs(v-1,true,ans);
			else re=re&&dfs(abs(v)-1,false,ans);
		}	
	}
	return re;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin>>q>>n;
	neg.assign(n,vector<int>());
	pos.assign(n,vector<int>());

	for (int i=0;i<q;++i){
		int a,b;char ca,cb;
		cin>>ca>>a>>cb>>b;
		a=a*((ca=='-')*-2+1);
		b=b*((cb=='-')*-2+1);
		if (b<0) pos[-b-1].push_back(a);
		else neg[b-1].push_back(a);
		if (a<0) pos[-a-1].push_back(b);
		else neg[a-1].push_back(b);
	}

	ans1.assign(n,0);
	ans2.assign(n,0);
	vector<int> ans(n,0);
	for (int i=0;i<n;++i){
		if (ans[i]) continue;
		if(dfs(i,true,ans1)) 
			dfs(i,true,ans);
		else if (dfs(i,false,ans2))
			dfs(i,false,ans);
		else {
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
	}
	for (int i=0;i<n;++i){
		if (ans[i]>0) cout<<"+ ";
		else cout<<"- ";
	}
	cout<<'\n';
	return 0;
}