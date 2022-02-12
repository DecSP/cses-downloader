# include <bits/stdc++.h>
# define ll long long
# define all(x) x.begin(), x.end()
# define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll re=0;
vector <pair<int,int>> arr;

int main()
{
    fastio;
    int n,k;
    cin>>n>>k;
    priority_queue <pair<int,int>> l;
    priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>r;
    arr.assign(n,pair<int,int>());
    for (int i=0;i<n;i++) {cin>>arr[i].first;arr[i].second=i;}
    int lcnt=0;
    int mid=(k+1)>>1;
    for (int i=0;i<k;i++){
        if (lcnt<mid) {
            r.push(arr[i]);
            l.push(r.top());
            r.pop();
            lcnt++;
        }
        else {
            l.push(arr[i]);
            r.push(l.top());
            l.pop();
        }
    }
    for (int i=0;i<k;i++)re+=abs(arr[i].first-l.top().first);
    cout<<re;
    for (int i=k;i<n;i++){
        ll oldmean=l.top().first;
        if (arr[i-k].first<=oldmean) lcnt--;
        while(!l.empty() && l.top().second<=i-k)l.pop();
        while(!r.empty() && r.top().second<=i-k)r.pop();
        if (lcnt<mid) {
            r.push(arr[i]);
            l.push(r.top());
            r.pop();
            lcnt++;
        }
        else {
            l.push(arr[i]);
            r.push(l.top());
            l.pop();
        }
        while(!l.empty() && l.top().second<=i-k)l.pop();
        while(!r.empty() && r.top().second<=i-k)r.pop();
        re+=abs(arr[i].first-l.top().first)-abs(arr[i-k].first-l.top().first);
        ll tmp=abs(oldmean-l.top().first);
        re+=tmp;
        if (k%2==0){
            if (oldmean>l.top().first) re+=tmp;
            else re-=tmp;
        }
        cout<<' '<<re;  
    }
    cout<<'\n';
    return 0;    
}