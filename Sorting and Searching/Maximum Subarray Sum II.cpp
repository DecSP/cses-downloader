# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;


int main()
{
    fastio;
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> arr(n);
    vector <ll> acuSum(n+1);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
        acuSum[i+1]=acuSum[i]+arr[i];
    }
    multiset<ll> ms;
    ll currMax=-1e18;
    ll re=-1e18;
    for (int i=0;i<=n;i++){
        if (i>=a){
            if (i>b) {
                multiset<ll>::iterator it=ms.find(acuSum[i-b-1]);
               ms.erase(it);
            } 
            ms.insert(acuSum[i-a]);
            
            re=max(re,acuSum[i]-*ms.begin());
            
        }
    }
    cout<<re<<'\n';
    return 0;
}