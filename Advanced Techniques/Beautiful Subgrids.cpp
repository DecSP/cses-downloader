#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
 
#define int long long
 
 
int32_t main() {
    int n;
    cin >> n;
    
    bitset<3005>b[3005];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
 
    int ans=0;
 
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           int common=(b[i]&b[j]).count();
           ans+=common*(common-1)/2;
       }
    }
 
    cout<<ans<<endl;
 
 
 
    return 0;
}
