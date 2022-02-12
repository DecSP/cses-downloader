# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
# define MOD 1000000007
using namespace std;
int n;
vector<int> lsCoin;
vector<int> dp;

int main(){
	fastio;
    cin>>n;
    lsCoin.assign(n,0);
    int s=0;
    for (int i=0;i<n;++i) {
        cin>>lsCoin[i];
        s+=lsCoin[i];
    }
    dp.assign(s+1,-1);
    dp[0]=1;
    vector<int> allSum;
    for (int k=0;k<lsCoin.size();++k){
        for (int i=s;i>=1;--i) {
            if (lsCoin[k]<=i&&dp[i-lsCoin[k]]==1){
                dp[i]=1;
            }
        }
    }
    for (int i=1;i<=s;++i) {
        if (dp[i]==1)
                allSum.push_back(i);
    }
    cout<<allSum.size()<<'\n';
    for (int i=0;i<allSum.size();++i){
        if (i!=0) cout<<' ';
        cout<<allSum[i];
    }
    cout<<'\n';
	return 0;
}

