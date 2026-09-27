#include <stdio.h>
#include <string.h>
#include <sys/time.h>

#define N	100000
#define M	250000
#define INF	0x3f3f3f3f

int min(int a, int b) { return a < b ? a : b; }

unsigned int X;

void srand_() {
	struct timeval tv;

	gettimeofday(&tv, NULL);
	X = tv.tv_sec ^ tv.tv_usec;
}

int rand_() {
	return (X *= 3) >> 1;
}

int ii[M], jj[M], ww[M];

void sort(int *hh, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, h = hh[l + rand_() % (r - l)], tmp;

		while (j < k)
			if (ww[hh[j]] == ww[h])
				j++;
			else if (ww[hh[j]] < ww[h]) {
				tmp = hh[i], hh[i] = hh[j], hh[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = hh[j], hh[j] = hh[k], hh[k] = tmp;
			}
		sort(hh, l, i);
		l = k;
	}
}

int ds[N * 2];

int find(int i) {
	return ds[i] < 0 ? i : (ds[i] = find(ds[i]));
}

void join(int i, int j) {
	i = find(i);
	j = find(j);
	if (i == j)
		return;
	if (ds[i] > ds[j])
		ds[i] = j;
	else {
		if (ds[i] == ds[j])
			ds[i]--;
		ds[j] = i;
	}
}

int main() {
	static int hh[M], ww1[N], ww2[N];
	int n, m, h, i, j, ans;

	srand_();
	scanf("%d%d", &n, &m);
	memset(ww1, 0x3f, n * sizeof *ww1);
	memset(ww2, 0x3f, n * sizeof *ww2);
	for (h = 0; h < m; h++) {
		int w;

		scanf("%d%d%d", &i, &j, &w), i--, j--;
		ii[h] = i, jj[h] = j, ww[h] = w;
		hh[h] = h;
		if (ww1[i] > w)
			ww2[i] = ww1[i], ww1[i] = w;
		else if (ww2[i] > w)
			ww2[i] = w;
		if (ww1[j] > w)
			ww2[j] = ww1[j], ww1[j] = w;
		else if (ww2[j] > w)
			ww2[j] = w;
	}
	ans = INF;
	for (i = 0; i < n; i++)
		ans = min(ans, ww1[i] + ww2[i]);
	sort(hh, 0, m);
	memset(ds, -1, n * 2 * sizeof *ds);
	for (h = 0; h < m; h++) {
		int h_ = hh[h];

		i = ii[h_], j = jj[h_];
		join(i << 1 | 0, j << 1 | 1), join(i << 1 | 1, j << 1 | 0);
		if (find(i << 1 | 0) == find(i << 1 | 1)) {
			ans = min(ans, ww[h_]);
			break;
		}
	}
	printf("%d\n", ans == INF ? -1 : ans);
	return 0;
}
