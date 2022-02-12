#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,timer;
vector<int> p;
vector<array<int,3>> idx;
vector<vector<int>> l;
vector<vector<int>>up;

void genLine(int x){
	vector<int> v;
	while (idx[x][0]>0){
		v.push_back(x);
		idx[x][0]=-2;
		x=p[x];
	}
	if (idx[x][0]!=0) x=-1;
	else v.push_back(x);

 	reverse(v.begin(),v.end());
 	for (int& c:v){
 		if (c!=x) up[c][0]=p[c];
 		else up[c][0]=c;
 		for (int i=1;i<20;++i){
 			up[c][i]=up[up[c][i-1]][i-1];
 		}
 	}

}

void genCycle(int x){
	int pos=l.size();
	int turtle=p[x], rabbit=p[p[x]];
	while (turtle!=rabbit){
		turtle=p[turtle];
		rabbit=p[p[rabbit]];
	}
	int y=x;
	
	while (y!=turtle){
		y=p[y];
		turtle=p[turtle];
	}

	l.push_back({y});
	vector<int> &cycle=l[pos];
	idx[y]={0,pos,0};
	int y1=p[y];
	int tmp=1;
	while (y1!=y) {
		idx[y1]={0,pos,tmp++};
		cycle.push_back(y1);
		y1=p[y1];
	}

 	genLine(x);
}
 
void merge(int x){
	idx[x][0]=timer;
	int tmp=p[x];
	while (idx[tmp][0]==-1){
		idx[tmp][0]=timer;
		tmp=p[tmp];
	}
	int a=idx[tmp][0];
	if (a==timer) genCycle(x);
	else genLine(x);
	++timer;
}

bool checkroot(int x){
	return idx[x][0]==0;
}
int get(int x, int k){
	if (idx[x][0]==0){
		int & b=idx[x][1], &c=idx[x][2];
		return l[b][(c+k)%(l[b].size())];
	}
	else {
		for(int i=19;k>0&&i>=0;--i){
			if ((1<<i)<=k&&!checkroot(up[x][i])) {
				x=up[x][i];
				k-=(1<<i);
			}
		}
		if (k==0) return x;
		else return get(up[x][0],k-1);
	}
}

void solve(){
	idx.assign(n,{-1,-1,-1});
	up.assign(n,vector<int>(20,-1));
	timer=1;
	for (int i=0;i<n;++i){
		if (idx[i][0]==-1) merge(i);
	}
	for (int i=0;i<m;++i){
		int x,k;
		cin>>x>>k;
		cout<<get(x-1,k)+1<<'\n';
	}
}
 
int main(){
	ios::sync_with_stdio(0);cin.tie(NULL);
	cin>>n>>m;
	p.assign(n,-1);
	for (int i=0;i<n;++i){
		cin>>p[i];
		--p[i];
	}
	solve();
	return 0;
}