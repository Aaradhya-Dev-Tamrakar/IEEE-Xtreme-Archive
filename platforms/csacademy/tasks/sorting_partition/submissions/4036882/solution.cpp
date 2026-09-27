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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    vector<int> mn(n, v[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
      mn[i] = min(v[i], mn[i + 1]);
    }
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(v[i], mx);
      if (i + 1 < n and mx <= mn[i + 1]) {
        ++ans;
      }
    }
    cout << ans + 1 << '\n';
  };

  {
    int tt = 1;
    while (tt--) solve();
  }
  return 0;
}
