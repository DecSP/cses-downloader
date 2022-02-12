#include <bits/stdc++.h>
using namespace std;

int g(char x){
	switch(x){
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'T':
			return 2;
		case 'G':
			return 3;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	string s;
	cin>>s;
	string re;
	array<int,4> check;
	check.fill(0);
	int cnt=0;
	for (char &c:s){
		if (!check[g(c)]){
			check[g(c)]=1;
			++cnt;
		}
		if (cnt==4){
			cnt=0;
			check.fill(0);
			re.push_back(c);
		}
	}
	string tmp="ACGT";
	for (char&c:tmp){
		if (!check[g(c)]){
			re.push_back(c);
			break;
		}
	}
	cout<<re<<'\n';
	return 0;
}