#include <bits/stdc++.h>
using namespace std;

const bool pcc = false;
const int mxn = 1e5+10;

long long ans = 1e18;
int dep[mxn];
long long dp[mxn];
vector<int> tree[mxn];
int col[mxn];
int rest[mxn];
int n;

void dfs1(int now,int par){
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dep[nxt] = dep[now]+1;
        dfs1(nxt,now);
    }
    return;
}

void dfs2(int now,int par){
    rest[now] = dp[now] = 0;
    for(auto nxt:tree[now]){
        if(nxt == par)continue;
        dfs2(nxt,now);
        dp[now] += dp[nxt]+abs(rest[nxt]);
        rest[now] += rest[nxt];
    }
    int tar = dep[now]&1;
    if(col[now]&&tar != col[now])rest[now]++;
    else if(!col[now]&&tar != col[now])rest[now]--;
    //cout<<now<<":"<<col[now]<<','<<tar<<','<<dp[now]<<','<<rest[now]<<endl;
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int cnt = 0;
    for(int i =1 ;i<=n;i++){
        char c;
        cin>>c;
        if(c == 'R')col[i] = 1,cnt++;
    }
    for(int i = 1;i<n;i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs1(1,1);
    int odd = 0;
    for(int i = 1;i<=n;i++)if(dep[i]&1)odd++;
    if(odd == cnt){
        dfs2(1,1);
        ans = min(ans,dp[1]);
    }
    for(int i = 1;i<=n;i++)col[i] ^= 1;
    cnt = n-cnt;
    if(odd == cnt){
        dfs2(1,1);
        ans = min(ans,dp[1]);
    }
    cout<<(ans>=1LL*n*n?-1:ans);
}