// coached by rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int   N = 100000;
const int INF = 0x3f3f3f3f;

int *ej[N], eo[N], dp00[N], dp01[N], dp11[N];

void append(int i, int j) {
	int o = eo[i]++;
	if (!o)
		ej[i] = (int *) malloc(sizeof *ej[i]);
	else if (!(o & o - 1))
		ej[i] = (int *) realloc(ej[i], (o << 1) * sizeof *ej[i]);
	ej[i][o] = j;
}

void dfs(int p, int i) {
	int s = 0, psum = 0, pmax = 0, pcnt = 0, qmax = -INF, x11 = 0;
	for (int o = 0; o < eo[i]; o++) {
		int j = ej[i][o];
		if (j != p) {
			dfs(i, j);
			s += dp00[j];
			int d = max(dp01[j], dp11[j]) - dp00[j];
			if (d >= 0) {
				psum += d;
				pmax = max(pmax, d);
				pcnt++;
			} else
				qmax = max(qmax, d);
			x11 += max(dp00[j], dp01[j] + 1);
		}
	}
	dp00[i] = s + max((pcnt >= 2 ? psum : pcnt ? pmax + qmax : -1) + 1, 0);
	dp01[i] = s + (pcnt ? pmax : qmax);
	dp11[i] = x11;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n; cin >> n;
	for (int h = 0; h < n - 1; h++) {
		int i, j; cin >> i >> j, i--, j--;
		append(i, j), append(j, i);
	}
	dfs(-1, 0);
	cout << max(max(dp00[0], dp01[0]), dp11[0]) << '\n';
	return 0;
}
