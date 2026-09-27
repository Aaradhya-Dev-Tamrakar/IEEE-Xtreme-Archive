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
    int segment_count;
    cin >> segment_count;
    vector<int> endpoints(2 * segment_count);
    vector<int> left(segment_count);
    vector<int> right(segment_count);
    for (int endpoint_index = 0, segment_index = 0; segment_index < segment_count; ++segment_index) {
      cin >> left[segment_index] >> right[segment_index];
      endpoints[endpoint_index++] = left[segment_index];
      endpoints[endpoint_index++] = right[segment_index];
    }
    nth_element(endpoints.begin(), endpoints.begin() + segment_count, endpoints.end());
    long long total_cost = 0;
    int median_position = endpoints[segment_count];
    for (int segment_index = 0; segment_index < segment_count; ++segment_index) {
      total_cost += max(0, median_position - right[segment_index]);
      total_cost += max(0, left[segment_index] - median_position);
    }
    cout << total_cost << '\n';
  };

  {
    int test_cases = 1;
    while (test_cases--) solve();
  }
  return 0;
}
