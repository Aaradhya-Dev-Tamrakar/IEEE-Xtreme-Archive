#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<int>x(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	vector<int>l(n, -1e9 + 7), r(n + 1, 1e9 + 7);
	l[0] = x[0];
	for (int i = 1; i < n; i++) {
		l[i] = max(x[i], l[i - 1]);
	}
	r[n - 1] = x[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		r[i] = min(x[i], r[i + 1]);
	}
	int ans = 0;
	for (int i = 0; i < n ; i++) {
		if (l[i] <= r[i + 1]) {
			ans++;
		}
	}
	cout << ans << endl;

}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
}