#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/debug.cc"
#else
#define debug(...) 0
#endif

int32_t main() {
  cin.tie(0)->sync_with_stdio(0);

  auto solve = [&]() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; ++i) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<vector<long long>> dp(2, vector<long long>(n));
    vector<vector<long long>> sum(2, vector<long long>(n));
    function<void(int, int)> dfs = [&](int u, int p) -> void {
      for (auto& v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 0; i < 2; ++i) {
          dp[i][u] += dp[i ^ 1][v] + abs(sum[i ^ 1][v]);
          sum[i][u] += sum[i ^ 1][v];
        }
      }
      if (s[u] == 'R')
        sum[1][u] += 1;
      else
        sum[0][u] -= 1;
    };
    dfs(0, -1);
    const long long inf = 1e18;
    long long ans = inf;
    for (int i = 0; i < 2; ++i)
      if (!sum[i][0]) ans = min(ans, dp[i][0]);
    if (ans >= inf) ans = -1;
    cout << ans << '\n';
  };

  {
    int tt = 1;
    while (tt--) solve();
  }
  return 0;
}
