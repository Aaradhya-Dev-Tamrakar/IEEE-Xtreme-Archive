#include <bits/stdc++.h>
using namespace std;
typedef long long i64;

const int MAX_N = 1e5 + 7;

i64 dp[2][MAX_N];

int32_t main() {
//	freopen("input", "r", stdin);
	string state;
	cin >> state;
	int n = state.size();
	dp[0][n - 1] = (state[n - 1] == '1' ? 1 : 0);
	dp[1][n - 1] = (state[n - 1] == '0' ? 1 : 0);
	for (int i = n - 2; ~i; --i) {
		if (state[i] == '1') {
			dp[1][i] = dp[0][i + 1];
			dp[0][i] = dp[1][i + 1] + 1 + (1LL << (n - i - 1)) - 1;
		} else {
			dp[0][i] = dp[0][i + 1];
			dp[1][i] = dp[1][i + 1] + 1 + (1LL << (n - i - 1)) - 1;
		}
	}
	cout << dp[0][0] << "\n";
}