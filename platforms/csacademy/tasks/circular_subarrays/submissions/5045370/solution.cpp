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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& i : v) cin >> i;
    long long ans = 0;
    vector<bool> vis(n);
    for (int i = 0; i < k; ++i) {
      vector<int> t;
      for (int j = i; !vis[j]; j = (j + k) % n) {
        vis[j] = 1;
        t.push_back(v[j]);
      }
      const int m = t.size();
      nth_element(t.begin(), t.begin() + m / 2, t.end());
      for (auto& j : t) ans += 1ll * abs(j - t[m / 2]);
    }
    cout << ans << '\n';
  };

  {
    int tt = 1;
    while (tt--) solve();
  }
  return 0;
}
