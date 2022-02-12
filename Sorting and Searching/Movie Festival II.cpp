# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;


int main()
{
    fastio;
    int n,k;
    cin>>n>>k;
    vector <pair<int,int>> a(n);
    for (int i=0;i<n;i++) cin>>a[i].second>>a[i].first;
    sort(all(a));
    vector <pair<int,pair<bool,int>>>b(2*n);
    for (int i=0;i<n;i++){
        b[i*2]={a[i].second,{true,i}};
        b[i*2+1]={a[i].first,{false,i}};
    }
    sort(all(b));
    int ans=0;
    set <int> s;
    for (auto v: b){
        int x,isBeg,pos;
        x=v.first;isBeg=v.second.first;pos=v.second.second;
        if(isBeg) s.insert(pos);
        else {
            set<int>::iterator it;
            it=s.find(pos);
            if (it!=s.end()) {
              ans++;
              s.erase(it);  
            }
        }
        if (s.size()>k) s.erase(prev(s.end()));
    }
    cout<<ans<<'\n';
    return 0;
}