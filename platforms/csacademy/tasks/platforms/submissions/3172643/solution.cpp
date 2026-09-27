#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
template <typename T>
void checkmax(T &x, T y) {
  if (x < y) x = y;
}
template <typename T>
void checkmin(T &x, T y) {
  if (x > y) x = y;
}
struct Node {
  int l, r, len;
} a[100001], seg[100001];
int n, m, b[100001];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr), std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++)
    std::cin >> a[i].l >> a[i].r, a[i].len = a[i].r - a[i].l;
  for (int i = 1; i <= m; i++) std::cin >> b[i];
  std::sort(a + 1, a + n + 1,
            [](const Node &lhs, const Node &rhs) { return lhs.len > rhs.len; });
  std::sort(b + 1, b + m + 1);
  m = std::unique(b + 1, b + m + 1) - b - 1;
  for (int i = 1; i < m; i++) seg[i] = {b[i], b[i + 1], b[i + 1] - b[i]};
  std::sort(seg + 1, seg + m,
            [](const Node &lhs, const Node &rhs) { return lhs.len > rhs.len; });
  long long ans = 0LL;
  std::set<std::pair<int, int>> s;
  s.emplace(-1e9, b[1]), s.emplace(b[m], 1e9);
  int p = 1;
  for (int i = 1; i <= n; i++) {
    while (p < m && seg[p].len >= a[i].len) s.emplace(seg[p].l, seg[p].r), p++;
    auto it = s.lower_bound({a[i].l, a[i].l});
    int min = 0x7fffffff;
    if (it != s.end()) checkmin(min, it->first - a[i].l);
    if (it != s.begin()) checkmin(min, std::max(0, a[i].r - (--it)->second));
    ans += min;
  }
  std::cout << ans;
  return 0;
}