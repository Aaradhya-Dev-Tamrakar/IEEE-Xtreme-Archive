#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int n;
int over[nmax]; long long ans, dp[nmax];

string str;
vector < int > g[nmax];

char ch[nmax];

void run_labels(int node, int dad) {
    if (ch[dad] == 'R') ch[node] = 'B'; else ch[node] = 'R';
    for (auto &it : g[node]) {
        if (it == dad) continue;
        run_labels(it, node);
    }
}

void run_dfs(int node, int dad) {
    dp[node] = 0; over[node] = 0;
    for (auto &it : g[node]) {
        if (it == dad) continue;
        run_dfs(it, node);
        dp[node] += dp[it] + max(over[it], -over[it]);
        over[node] += over[it];
    }

    int sign = (str[node] == 'R') ? 1 : -1;
    over[node] += sign * (str[node] != ch[node]);
}

int main()
{
    cin >> n >> str; str = ' ' + str;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    run_labels(1, 0);
    run_dfs(1, 0); ans = (over[1]) ? inf : dp[1];

    for (int i = 1; i <= n; ++i) str[i] = (str[i] == 'R') ? 'B' : 'R';
    run_dfs(1, 0); ans = min(ans, (over[1]) ? inf : dp[1]);

    (ans == inf) ? printf("-1\n") : printf("%lld\n", ans);

    return 0;
}
