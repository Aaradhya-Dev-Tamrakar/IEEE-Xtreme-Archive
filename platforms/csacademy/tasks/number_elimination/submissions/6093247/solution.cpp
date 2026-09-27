#include <algorithm>
#include <iostream>

using namespace std;

const int  N = 100000;
const int MD = 1000000007;

int vv[N];

void init() {
	vv[1] = 1;
	for (int i = 2; i < N; i++)
		vv[i] = (long long) vv[i - MD % i] * (MD / i + 1) % MD;
}

int aa[N];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	init();
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	sort(aa, aa + n);
	int n_ = 0;
	for (int k = 1, i = 1; i <= n; i++) {
		if (i == n || aa[i] > aa[i - 1])
			aa[n_++] = k, k = 0;
		k++;
	}
	n = n_;
	int ans = 1, s = 0;
	for (int i = 0; i < n; i++) {
		for (int a = aa[i]; a > 1; a--)
			ans = (ans * ((long long) a * (a - 1) / 2 % MD)) % MD;
		if (i) {
			int x = 0, c = 1;
			for (int a = 0; a < aa[i]; a++) {
				x = (x + (long long) c * (aa[i] - a)) % MD;
				c = (long long) c * (s + a) % MD * vv[a + 1] % MD;
			}
			ans = (long long) ans * x % MD;
		}
		s += aa[i];
	}
	cout << ans << '\n';
	return 0;
}
