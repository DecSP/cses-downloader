# include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	unordered_map <char,int> a;
	for (auto c:s){
		a[c]++;
	}
	string s1 (s.size(),' ');
	int l=0,r=s.size()-1;
	int m=-1;
	if (s.size()%2) m=(l+r)/2;
	for (auto x:a){
		if (x.second%2){
			if (m!=-1){
				s1[m]=x.first;
				m=-1;
			}
			else{
				cout<<"NO SOLUTION\n";
				return 0;
			}
		}
		for (int c=x.second;c>=2;c-=2){
			s1[l++]=s1[r--]=x.first;
		}	
	}
	cout<<s1<<endl;
	return 0;
}