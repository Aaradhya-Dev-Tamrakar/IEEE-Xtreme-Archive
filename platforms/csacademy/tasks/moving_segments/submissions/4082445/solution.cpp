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
    cin >> n;
    vector<int> v(2 * n);
    vector<int> l(n);
    vector<int> r(n);
    for (int j = 0, i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
      v[j++] = l[i];
      v[j++] = r[i];
    }
    nth_element(v.begin(), v.begin() + n, v.end());
    long long ans = 0;
    int mid = v[n];
    for (int i = 0; i < n; ++i) {
      ans += max(0, mid - r[i]);
      ans += max(0, l[i] - mid);
    }
    cout << ans << '\n';
  };

  {
    int tt = 1;
    while (tt--) solve();
  }
  return 0;
}
