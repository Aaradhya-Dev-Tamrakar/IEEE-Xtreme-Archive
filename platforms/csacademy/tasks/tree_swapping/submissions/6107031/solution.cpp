#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define pb push_back
#define int long long

const int maxn = 100001;
vector<int> adj[maxn];
int A[maxn], d[maxn], num[maxn][2], num1[maxn][2];

void dfs(int s, int p){
    d[s] = d[p] + 1;
    num[s][A[s]] = 1;
    for(auto u: adj[s]){
        if(u == p) continue;
        dfs(u, s);
        for(int t=0; t<2; t++){
            num[s][t] += num[u][t];
        }
    }
}

void dfs1(int s, int p){
    num1[s][d[s]%2] = 1;
    for(auto u: adj[s]){
        if(u == p) continue;
        dfs1(u, s);
        for(int t=0; t<2; t++){
            num1[s][t] += num1[u][t];
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        char c; cin >> c;
        if(c == 'R') A[i] = 1;
    }
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(1, 0);
    dfs1(1, 0);
    int ans = 1e18;
    if(num[1][1] == num1[1][0]){
        int ret = 0;
        for(int i=2; i<=n; i++){
            ret += abs(num[i][1] - num1[i][0]);
        }
        ans = min(ans, ret);
    }
    if(num[1][1] == num1[1][1]){
        int ret = 0;
        for(int i=2; i<=n; i++){
            ret += abs(num[i][1] - num1[i][1]);
        }
        ans = min(ans, ret);
    }
    if(ans == 1e18) ans = -1;
    cout << ans;
}