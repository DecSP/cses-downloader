# include <bits/stdc++.h>
using namespace std;
int main(){
	int n=0,m;
	string s;
	cin>>s;
	char a='\0';
	for (int i=0;i<s.size();i++){
		if(a!=s[i]){
			m=max(n,m);
			n=0;
			a=s[i];
		}
		n++;
	}
	m=max(n,m);
	cout<<m<<endl;
	return 0;
}