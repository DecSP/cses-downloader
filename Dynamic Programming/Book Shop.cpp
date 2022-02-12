# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
# define MOD 1000000007
# define ten6 1000002
using namespace std;
int n, X;
vector<pair<int,int>> book,book2;
vector<vector<int>> dp;

int getMax(int money, int idx) {
    if (idx>=n||money<=0) return 0;
    if(dp[money][idx]>=0) return dp[money][idx];
    if (money>=book2[idx].first) return dp[money][idx]=book2[idx].second;
    if (book[idx].first>money) return dp[money][idx]=getMax(money,idx+1);
    return dp[money][idx]=max(book[idx].second+getMax(money-book[idx].first,idx+1),getMax(money,idx+1));
}

bool comp(pair<int,int> x,pair<int,int> y) {
    double f=1.0/x.first*x.second;
    double s= 1.0/y.first*y.second;
    return f==s&&x>y||f<s;
}

int main()
{
    // freopen("test_input.txt","r",stdin);
    // auto start=chrono::high_resolution_clock::now();

    fastio;
    cin>>n>>X;
    dp.assign(X+1,vector<int>(n,-1));
    book.assign(n,pair<int,int>());
    for (int i=0;i<n;++i) cin>>book[i].first;
    for (int i=0;i<n;++i) cin>>book[i].second;
    sort(book.begin(),book.end(),comp);
    book2.assign(n+1,pair<int,int>());
    int s=-1;
    for (int i=n-1;i>=0;--i) {
        book2[i].first=book2[i+1].first+book[i].first;
        book2[i].second=book2[i+1].second+book[i].second;
        if (s==-1&&book2[i].first>X){
            s=max(i-30,0);
        }
    }
    s=max(s,0);
    cout<<getMax(X,s)<<'\n';
 
    // auto end=chrono::high_resolution_clock::now();
    // cout<<"Time elapsed: "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<endl;
    return 0;
}