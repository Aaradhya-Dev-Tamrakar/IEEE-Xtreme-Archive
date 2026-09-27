#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5, inf = 1e8;
int n, pre[N], last[N], tar[N], t, dp[N][3];
bool vis[N];

void add(int a, int b)
{
    t++;
    pre[t] = last[a];
    last[a] = t;
    tar[t] = b;
}

void dfs(int x)
{
    vis[x] = 1;
    int sum0 = 0, sum1 = 0, dif = -inf, dif2 = -inf;
    bool mk = 0;
    for (int ptr = last[x]; ptr; ptr = pre[ptr])
    {
        int xx = tar[ptr];
        if (!vis[xx])
        {
            mk = 1;
            dfs(xx);
            sum0 += dp[xx][0];
            sum1 += max(dp[xx][0], max(dp[xx][1], dp[xx][2]));
            dp[x][2] += max(dp[xx][0], dp[xx][1] + 1);
            int var = max(dp[xx][1], dp[xx][2]) - dp[xx][0];
            if (var > dif)
            {
                dif2 = dif;
                dif = var;
            }
            else if (var > dif2) dif2 = var;
        }
    }
    if (dif < 0) sum1 += dif + dif2;
    else if (dif2 < 0) sum1 += dif2;
    dp[x][0] = max(sum0, sum1 + 1);
    dp[x][1] = sum0 + dif;
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << max(max(dp[1][1], dp[1][0]), dp[1][2]) << endl;
    return 0;
}