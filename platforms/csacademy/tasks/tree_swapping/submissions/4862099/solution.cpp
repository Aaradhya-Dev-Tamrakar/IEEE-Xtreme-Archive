#include <algorithm>
#include <iostream>

using namespace std;

const       int   N = 100000;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;

char cc[N + 1];
int aa[N], bb[N];
int *ej[N], eo[N];

void append(int i, int j) {
	int o = eo[i]++;
	if (!o)
		ej[i] = (int *) malloc(sizeof *ej[i]);
	else if (!(o & o - 1))
		ej[i] = (int *) realloc(ej[i], (o << 1) * sizeof *ej[i]);
	ej[i][o] = j;
}

int dfs(int p, int i) {
	int a = aa[i];
	for (int o = 0; o < eo[i]; o++) {
		int j = ej[i][o];
		if (j != p)
			a += dfs(i, j);
	}
	return aa[i] = a;
}

int dfs(int p, int i, int a) {
	int b = a; a ^= 1;
	for (int o = 0; o < eo[i]; o++) {
		int j = ej[i][o];
		if (j != p)
			b += dfs(i, j, a);
	}
	return bb[i] = b;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n; cin >> n >> cc;
	for (int i = 0; i < n; i++)
		aa[i] = cc[i] == 'R';
	for (int h = 0; h < n - 1; h++) {
		int i, j; cin >> i >> j, i--, j--;
		append(i, j), append(j, i);
	}
	long long ans = INF;
	dfs(-1, 0);
	dfs(-1, 0, 0);
	if (aa[0] == bb[0]) {
		long long s = 0;
		for (int i = 1; i < n; i++)
			s += abs(bb[i] - aa[i]);
		ans = min(ans, s);
	}
	dfs(-1, 0, 1);
	if (aa[0] == bb[0]) {
		long long s = 0;
		for (int i = 1; i < n; i++)
			s += abs(bb[i] - aa[i]);
		ans = min(ans, s);
	}
	if (ans == INF)
		ans = -1;
	cout << ans << '\n';
	return 0;
}
