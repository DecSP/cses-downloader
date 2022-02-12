# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002
using namespace std;

vector<int> maxCommon(ten6,0);

vector<int> lsPrime;

int binpow(int x, int y){
    assert(y>=0);
    int re=1;
    while (y){
        if (y&1) re*=x;
        y>>=1;
        x*=x;
    }
    return re;
}

void setPrime(){
    bool isPrime[ten6]{0};
    for (int i=2;i<ten6;++i) isPrime[i]=true;
    for (int i=2;i*i<ten6;++i) {
        if (!isPrime[i]) continue;
        lsPrime.push_back(i);
        int k=i*i;
        while(k<ten6){
            isPrime[k]=false;
            k+=i;
        }
    }
}

void setFac(vector<pair<int,int>> & lsFac,int curr,int idx) {
    if (idx>=lsFac.size()) {
        ++maxCommon[curr];
        return;
    }
    for (int i=0;i<=lsFac[idx].second;++i){
        setFac(lsFac,curr*binpow(lsFac[idx].first,i),idx+1);
    }
}

void setFactor(int x) {
    if (x==1) return;
    vector<pair<int,int>> lsFac;
    for (int p:lsPrime) {
        if (p*p>x) break;
        int reTmp=0;
        while (x%p==0){
            ++reTmp;
            x/=p;
        }
        lsFac.push_back({p,reTmp});
    }
    if (x>1) {
        lsFac.push_back({x,1});
    }
    setFac(lsFac,1,0);
}


int main()
{
    // freopen("test_input.txt","r",stdin);
    fastio; 
    setPrime();
    int n;
    cin>>n;
    for (int i=0;i<n;++i) {
        int tmp;
        cin>>tmp;
        setFactor(tmp);
    }
    int re=1;
    for (int i=1;i<ten6;++i){
        if (maxCommon[i]>=2) re=i;
    }
    cout<<re<<'\n';
    return 0;
}