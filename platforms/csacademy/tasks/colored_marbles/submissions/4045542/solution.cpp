#include <bits/stdc++.h>
using namespace std;

const bool pcc = false;
#define ll long long
#define int ll
#define pii pair<ll,ll>
#define fs first
#define sc second

void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(auto &i:arr)cin>>i;
    if(n == 1){
        cout<<"1\n";
        return;
    }
    sort(arr,arr+n);
    vector<pii> v;
    for(auto &i:arr){
        if(v.empty())v.push_back({i,1});
        else if(v.back().fs != i)v.push_back({i,1});
        else v.back().sc++;
    }
    long long sum = 0;
    for(auto &i:v)sum += (i.sc+i.fs-1)/i.fs*i.fs;
    int spare = 0;
    long long ans = 1e18;
    for(auto &i:v)if(i.sc%i.fs != 0)spare++;
    for(auto &i:v){
        if(i.sc%i.fs != 0)spare--;
        sum -= (i.sc+i.fs-1)/i.fs*i.fs;
        i.sc--;
        sum += (i.sc+i.fs-1)/i.fs*i.fs;
        if(!spare)ans = min(ans,sum+1+(i.fs == 1));
        else ans = min(ans,sum);
        sum -= (i.sc+i.fs-1)/i.fs*i.fs;
        i.sc++;
        sum += (i.sc+i.fs-1)/i.fs*i.fs;
        if(i.sc%i.fs != 0)spare++;
    }
    cout<<ans<<'\n';
    return;
}

main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}