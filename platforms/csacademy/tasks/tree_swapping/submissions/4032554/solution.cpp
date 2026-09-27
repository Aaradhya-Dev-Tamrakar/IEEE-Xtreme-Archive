#include<iostream>
#include<cstring>
#define mem(a,b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 100100
#define Inf 0x3f3f3f3f3f3f3f3f
#define ll long long
using namespace std;
int head[N], to[2*N], nxt[2*N];
ll cnt, dp[N][2], diff[N][2];
string s;

void init(){mem(head, -1), cnt = -1;}
void add_e(int a, int b, bool id){
    nxt[++cnt] = head[a], head[a] = cnt, to[cnt] = b;
    if(id) add_e(b, a, 0);
}

void dfs(int x, int fa){
    for(int i = head[x]; ~i; i = nxt[i]){
        if(to[i] == fa) continue;
        dfs(to[i], x);
        rep(k,0,1){
            ll d = diff[to[i]][k^1];
            dp[x][k] += dp[to[i]][k^1] + std::abs(d);
            diff[x][k] += d;
        }
    }
    if(s[x-1] == 'R') diff[x][1]--;
    else diff[x][0]++;
}

int main(){
    ios::sync_with_stdio(false);
    int u, v, n;
    cin>>n>>s;
    init();
    rep(i,2,n) cin>>u>>v, add_e(u, v, 1);
    dfs(1, 0);
    ll ans = Inf;
    rep(k,0,1) if(!diff[1][k]) 
        ans =min(ans, dp[1][k]);
    if(ans == Inf) cout<<"-1\n";
    else cout<<ans<<endl;
    return 0;
}