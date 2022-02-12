# include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,pre=0,curr,re=0;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>curr;
		if (curr<pre) {
			re+=pre-curr;
			curr=pre;
		}
		pre=curr;
	}
	cout<<re<<endl;
	return 0;
}