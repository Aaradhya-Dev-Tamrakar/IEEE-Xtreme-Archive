#include<iostream>
#include<cstring>
#define mem(a,b) memset(a, b, sizeof(a))
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define per(i,b,a) for(int i = (b); i >= (a); i--)
#define N 100100
#define Inf 0x3f3f3f3f
using namespace std;
int head[N], to[2*N], nxt[2*N];
int cnt, dp[N][4];
int n;
void init(){mem(head, -1), cnt = -1;}
void add_e(int a, int b, bool id){
    nxt[++cnt] = head[a], head[a] = cnt, to[cnt] = b;
    if(id) add_e(b, a, 0);
}
void dfs(int x, int fa){
    int tot = 0;
    int sum = 0, mx1 = -Inf, mx2 = -Inf, cnt = 0;
    for(int i = head[x], y; ~i; i = nxt[i]){
        if((y = to[i]) == fa) continue;
        dfs(y, x);
        tot += dp[y][0];
        dp[x][2] += max(dp[y][0], dp[y][1]+1);
        int k = dp[y][3] - dp[y][0];
        if(k > 0) sum += k, cnt++;
        if(k >= mx1) mx2 = mx1, mx1 = k;
        else if(k > mx2) mx2 = k; 
    }
    dp[x][0] = tot;
    if(mx2 > -Inf){
        if(cnt <= 2) dp[x][0] += max(0, mx1+mx2+1);
        else dp[x][0] += sum+1;
    }
    dp[x][1] = tot+mx1;
    dp[x][3] = max(dp[x][1], dp[x][2]);
    //cout<<x<<" : "<<dp[x][0]<<" "<<dp[x][1]<<" "<<dp[x][2]<<" "<<dp[x][3]<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    int u, v;
    init();
    rep(i,2,n) cin>>u>>v, add_e(u, v, 1);
    dfs(1, 0);
    cout<<max(dp[1][0], dp[1][3])<<endl;
    return 0;
}