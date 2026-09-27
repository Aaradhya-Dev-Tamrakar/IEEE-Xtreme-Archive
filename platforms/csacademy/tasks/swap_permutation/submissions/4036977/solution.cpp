#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#include "lib/debug.cc"
#else
#define debug(...) 0
#endif

int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0);

  auto solve = [&]() {
    int n, m, k;
    cin >> n >> m >> k;
    --k;
    vector<int> pos(m);
    vector<pair<int, int>> p(m + 1);
    for (int i = 0; i < m; ++i) {
      cin >> p[i].first >> p[i].second;
      p[i].first -= 1;
      p[i].second -= 1;
    }
    int now = k;
    pos[m] = k;
    for (int i = m - 1; i >= 0; --i) {
      if (p[i].first == now)
        now = p[i].second;
      else if (p[i].second == now)
        now = p[i].first;
      pos[i] = now;
    }
    now = 0;
    for (int i = 0; i < m; ++i) {
      if (pos[i + 1] == now) {
        cout << i + 1 << '\n';
        return;
      }
      if (p[i].first == now)
        now = p[i].second;
      else if (p[i].second == now)
        now = p[i].first;
    }
  };

  {
    int tt = 1;
    while (tt--) solve();
  }
  return 0;
}
