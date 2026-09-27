#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/debug.cc"
#else
#define debug(...) 0
#endif

#define int long long

int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0);

  auto solve = [&]() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> v(n);
    for (auto& i : v) {
      cin >> i[0] >> i[1];
      i[2] = i[1] - i[0];
    }
    sort(v.begin(), v.end(),
         [&](const auto& x, const auto& y) -> bool { return x[2] > y[2]; });
    vector<int> b(m);
    for (auto& i : b) cin >> i;
    sort(b.begin(), b.end());
    vector<array<int, 3>> vb(m - 1);
    for (int i = 0; i + 1 < m; ++i) {
      vb[i][0] = b[i];
      vb[i][1] = b[i + 1];
      vb[i][2] = b[i + 1] - b[i];
    }
    sort(vb.begin(), vb.end(),
         [&](const auto& x, const auto& y) -> bool { return x[2] > y[2]; });
    int ans = 0;
    set<pair<int, int>> vis;
    vis.emplace(-1e9, b[0]);
    vis.emplace(b.back(), 1e9);
    for (int i = 0, j = 0; i < n; ++i) {
      while (j < m - 1 and v[i][2] <= vb[j][2]) {
        vis.emplace(vb[j][0], vb[j][1]);
        ++j;
      }
      auto it = vis.lower_bound({v[i][0], v[i][0]});
      int t = 1e9;
      if (it != vis.begin()) {
        t = min(t, max(0ll, v[i][1] - prev(it)->second));
      }
      if (it != vis.end()) t = min(t, it->first - v[i][0]);
      ans += t;
    }
    cout << ans << '\n';
  };

  {
    int tt = 1;
    while (tt--) solve();
  }
  return 0;
}
