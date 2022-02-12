# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define ten6 1e6+1.5
using namespace std;


int main()
{
    fastio;
    int n,k;
    cin>>n;
    vector <vector<int>> div (ten6,vector<int>());
    vector <ll> re (ten6,1);
    for (ll i = 2;i<ten6;i++){
        if (div[i].size()==0){
            ll j;
            for (j=i;j<ten6 ;j+=i)
                    div[j].push_back(1);

            j=i*i;
            ll k =j;
            while (j<ten6){
                for (k=j;k<ten6 ;k+=j)
                    div[k][div[k].size()-1]=div[k].back()+1;
                j*=i;
            }
        }
    }
    for (int i=2;i<ten6;i++){
        for (auto &v:div[i])re[i]*=v+1;
    }
    while (n--){
        cin>>k;
        cout<<re[k]<<'\n';
    }
    return 0;    
}