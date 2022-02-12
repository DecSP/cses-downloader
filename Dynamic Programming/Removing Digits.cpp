# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002

using namespace std;
int main()
{
    fastio;
    int x;
    cin>>x;
    vector <int> ten (7);
    ten[0]=1;
    int mxDig=x%10;
    for (int i = 1;i<7;i++) {
        ten[i]=10*ten[i-1];
        mxDig=max(mxDig,x/ten[i-1]%10);
    }
    int cnt=0;
    while (x){
        x-=mxDig;
        mxDig=x%10;
        for (int i = 1;i<7;i++) {
        mxDig=max(mxDig,x/ten[i-1]%10);
        }
        cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}