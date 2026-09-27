#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	200000
#define Q	200000

unsigned int X = 12345;

int rand_() {
	return (X *= 3) >> 1;
}

int n;

int *ej[N], eo[N];

void append(int i, int j) {
	int o = eo[i]++;

	if (o >= 2 && (o & o - 1) == 0)
		ej[i] = (int *) realloc(ej[i], o * 2 * sizeof *ej[i]);
	ej[i][o] = j;
}

int dd[N], pp[N], qq[N], sz[N], ta[N], tb[N], ii_[N];

void dfs1(int p, int i, int d) {
	int o, k_, j_;

	pp[i] = p, dd[i] = d;
	sz[i] = 1, k_ = 0, j_ = -1;
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (j != p) {
			dfs1(i, j, d + 1);
			sz[i] += sz[j];
			if (k_ < sz[j])
				k_ = sz[j], j_ = j;
		}
	}
	qq[i] = j_;
}

void dfs2(int p, int i, int q) {
	static int t = 0;
	int j_, o;

	ii_[ta[i] = t++] = i;
	j_ = qq[i], qq[i] = q;
	if (j_ != -1)
		dfs2(i, j_, q);
	for (o = eo[i]; o--; ) {
		int j = ej[i][o];

		if (j != p && j != j_)
			dfs2(i, j, j);
	}
	tb[i] = t;
}

int lca(int i, int j) {
	while (qq[i] != qq[j])
		if (dd[qq[i]] > dd[qq[j]])
			i = pp[qq[i]];
		else
			j = pp[qq[j]];
	return dd[i] < dd[j] ? i : j;
}

int ancestor(int i, int d) {
	while (dd[qq[i]] > d)
		i = pp[qq[i]];
	return ii_[ta[qq[i]] + d - dd[qq[i]]];
}

int dist(int i, int j) {
	return dd[i] + dd[j] - dd[lca(i, j)] * 2;
}

int next(int i, int j, int k) {
	int a = lca(i, j), d = dd[i] + dd[j] - dd[a] * 2;

	return dd[i] - k >= dd[a] ? ancestor(i, dd[i] - k) : ancestor(j, dd[j] - (d - k));
}

int ll[Q], rr[Q], ii[Q];

void sort(int *hh, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, h = hh[l + rand_() % (r - l)], tmp;

		while (j < k) {
			int c = ii[hh[j]] != ii[h] ? ii[hh[j]] - ii[h] : hh[j] - h;

			if (c == 0)
				j++;
			else if (c < 0) {
				tmp = hh[i], hh[i] = hh[j], hh[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = hh[j], hh[j] = hh[k], hh[k] = tmp;
			}
		}
		sort(hh, l, i);
		l = k;
	}
}

int center[N + 1], radius[N + 1], ans[N + 1], kk[N + 1], qu[N], t; char used[N];

void add(int i) {
	int c, c_, r, x, k, j, d;

	t++;
	k = kk[t - 1];
	if (ans[t - 1] == 0)
		c = -1, r = -1, x = 0;
	else if (center[t - 1] == -1)
		c = i, r = 0, x = n;
	else {
		c = center[t - 1], r = radius[t - 1], x = ans[t - 1];
		d = dist(c, i);
		if (d < r)
			c = -1, r = -1, x = 0;
		else if (d > r) {
			if (used[next(c, i, 1)] || (d - r) % 2 != 0)
				c = -1, r = -1, x = 0;
			else {
				c_ = next(c, i, (d - r) / 2);
				r = (r + d) / 2, x = n;
				j = next(c_, c, 1);
				used[j] = 1, qu[k++] = j, x -= pp[j] == c_ ? sz[j] : n - sz[c_];
				j = next(c_, i, 1);
				used[j] = 1, qu[k++] = j, x -= pp[j] == c_ ? sz[j] : n - sz[c_];
				c = c_;
			}
		} else {
			j = next(c, i, 1);
			if (!used[j])
				used[j] = 1, qu[k++] = j, x -= pp[j] == c ? sz[j] : n - sz[c];
		}
	}
	center[t] = c, radius[t] = r, ans[t] = x, kk[t] = k;
}

void undo() {
	int h;

	for (h = kk[t - 1]; h < kk[t]; h++)
		used[qu[h]] = 0;
	t--;
}

void solve(int *hh, int q, int l, int r) {
	int m, h, i, j, k, tmp;

	i = 0, j = 0, k = q;
	while (j < k)
		if (ll[hh[j]] <= l && r <= rr[hh[j]])
			j++;
		else if (ll[hh[j]] < r && l < rr[hh[j]]) {
			tmp = hh[i], hh[i] = hh[j], hh[j] = tmp;
			i++, j++;
		} else {
			k--;
			tmp = hh[j], hh[j] = hh[k], hh[k] = tmp;
		}
	for (h = i; h < j; h++)
		add(ii[hh[h]]);
	if (r - l == 1)
		printf("%d\n", ans[t]);
	else {
		m = (l + r) / 2;
		solve(hh, i, l, m), solve(hh, i, m, r);
	}
	for (h = j; h > i; h--)
		undo();
}

int main() {
	static int hh[Q];
	int q, q_, h, h_, i, j;

	scanf("%d%d", &n, &q);
	for (i = 0; i < n; i++)
		ej[i] = (int *) malloc(2 * sizeof *ej[i]);
	for (j = 0; j < n; j++) {
		scanf("%d", &i), i--;
		if (i >= 0)
			append(i, j), append(j, i);
	}
	dfs1(-1, 0, 0);
	dfs2(-1, 0, 0);
	for (h = 0; h < q; h++) {
		scanf("%d", &ii[h]);
		if (ii[h] < 0)
			ii[h] = -ii[h];
		ii[h]--;
	}
	for (h = 0; h < q; h++)
		hh[h] = h;
	sort(hh, 0, q);
	q_ = 0;
	for (h = 0; h < q; h++) {
		h_ = hh[h];
		if (h + 1 < q && ii[h_] == ii[hh[h + 1]])
			ll[h_] = h_, rr[h_] = hh[h + 1], hh[q_++] = hh[h], h++;
		else
			ll[h_] = h_, rr[h_] = q, hh[q_++] = hh[h];
	}
	center[0] = -1, radius[0] = -1, ans[0] = n, kk[0] = 0;
	t = 0, solve(hh, q_, 0, q);
	return 0;
}