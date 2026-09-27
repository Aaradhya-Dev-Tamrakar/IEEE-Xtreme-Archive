#include <bits/stdc++.h>
#pragma GCC optimze("Ofast")
#pragma loop-opt(on)
#define rep(i, a, b) for(int i = a; i <= b; i++)
using namespace std;
namespace solver {
	int n, g;
	vector<int> a;
	void init_(int _n) {
		n = _n, g = 0;
		a.assign(n + 1, 0);
	}
	void update(int x, int y) {
		a[x] /= y;
		g = __gcd(g, a[x]);
	}

};
using namespace solver;
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m; cin >> n >> m;
	init_(n);
	rep(i, 1, n) cin >> a[i], g = __gcd(g, a[i]);
	while(m --) {
		int x, y; cin >> x >> y;
		update(x, y);
		cout << g << "\n";
	}
	return 0;
}