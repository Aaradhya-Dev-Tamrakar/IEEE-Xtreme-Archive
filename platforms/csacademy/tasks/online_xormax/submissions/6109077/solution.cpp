// coached by rainboy
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;
const int L = 30;
const int M = (N + 1) * (L + 1) + 1;

int aa[N + 1], ii[N], xx[N];
int tt[M][2];
int ds[N + 1], uu[N + 1], ll[N + 1], rr[N + 1];
int x_;

int merge(int u, int v) {
	if (!u)
		return v;
	if (!v)
		return u;
	tt[u][0] = merge(tt[u][0], tt[v][0]);
	tt[u][1] = merge(tt[u][1], tt[v][1]);
	return u;
}

int query(int u, int b) {
	int x = 0;
	for (int h = L - 1; h >= 0; h--) {
		int a = b >> h & 1;
		if (tt[u][a ^ 1])
			x ^= 1 << h, a ^= 1;
		if (!(u = tt[u][a])) {
			x = -1;
			break;
		}
	}
	return x;
}

int find(int i) {
	return ds[i] < 0 ? i : (ds[i] = find(ds[i]));
}

void join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)
		return;
	if (ds[i] == ds[j])
		ds[i]--;
	if (ds[i] < ds[j])
		swap(i, j);
	ds[i] = j;
	ll[j] = min(ll[j], ll[i]);
	rr[j] = max(rr[j], rr[i]);
	for (int k = ll[i]; k <= rr[i]; k++)
		x_ = max(x_, query(uu[j], aa[k]));
	uu[j] = merge(uu[j], uu[i]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> aa[i], aa[i] ^= aa[i - 1];
	for (int h = 0; h < n; h++)
		cin >> ii[h];
	int m = 1;
	for (int i = 0; i <= n; i++) {
		ds[i] = -1, ll[i] = rr[i] = i;
		for (int u = uu[i] = m++, h = L - 1; h >= 0; h--) {
			int a = aa[i] >> h & 1;
			u = tt[u][a] = m++;
		}
	}
	for (int h = n - 1; h >= 0; h--) {
		join(ii[h], ii[h] - 1);
		xx[h] = x_;
	}
	for (int h = 0; h < n; h++)
		cout << xx[h] << '\n';
	return 0;
}
