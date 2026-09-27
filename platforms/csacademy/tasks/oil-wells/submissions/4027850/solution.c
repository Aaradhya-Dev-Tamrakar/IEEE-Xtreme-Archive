#include <stdio.h>

#define N	100000
#define N_	(1 << 18)	/* N_ = pow2(ceil(log2(N))) */

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

unsigned int X = 12345;

int rand_() {
	return (X *= 3) >> 1;
}

int aa[N];

void sort(int *ii, int l, int r) {
	while (l < r) {
		int i = l, j = l, k = r, i_ = ii[l + rand_() % (r - l)], tmp;

		while (j < k)
			if (aa[ii[j]] == aa[i_])
				j++;
			else if (aa[ii[j]] < aa[i_]) {
				tmp = ii[i], ii[i] = ii[j], ii[j] = tmp;
				i++, j++;
			} else {
				k--;
				tmp = ii[j], ii[j] = ii[k], ii[k] = tmp;
			}
		sort(ii, l, i);
		l = k;
	}
}

int ss[N_ * 2], ppmn[N_ * 2], ppmx[N_ * 2], qqmn[N_ * 2], qqmx[N_ * 2], n_;

void pul(int i) {
	int l = i << 1, r = l | 1;

	ss[i] = ss[l] + ss[r];
	ppmn[i] = min(ppmn[l], ss[l] + ppmn[r]), ppmx[i] = max(ppmx[l], ss[l] + ppmx[r]);
	qqmn[i] = min(qqmn[l] + ss[r], qqmn[r]), qqmx[i] = max(qqmx[l] + ss[r], qqmx[r]);
}

void build(int n) {
	int i;

	n_ = 1;
	while (n_ <= n)
		n_ <<= 1;
	for (i = 0; i < n_; i++)
		if (i < n)
			ss[n_ + i] = 1, ppmn[n_ + i] = 0, ppmx[n_ + i] = 1, qqmn[n_ + i] = 0, qqmx[n_ + i] = 1;
		else
			ss[n_ + i] = 0, ppmn[n_ + i] = 0, ppmx[n_ + i] = 0, qqmn[n_ + i] = 0, qqmx[n_ + i] = 0;
	for (i = n_ - 1; i > 0; i--)
		pul(i);
}

void update(int i, int x) {
	i += n_;
	ss[i] = x;
	ppmn[i] = min(x, 0), ppmx[i] = max(x, 0);
	qqmn[i] = min(x, 0), qqmx[i] = max(x, 0);
	while (i > 1)
		pul(i >>= 1);
}

void query_p(int l, int *pmn_, int *pmx_) {
	int r, pmn, pmx, s;

	r = n_ - 1;
	pmn = 0, pmx = 0, s = 0;
	for (l += n_, r += n_; l <= r; l >>= 1, r >>= 1)
		if ((l & 1) == 1)
			pmn = min(pmn, s + ppmn[l]), pmx = max(pmx, s + ppmx[l]), s += ss[l], l++;
	*pmn_ = pmn, *pmx_ = pmx;
}

void query_q(int r, int *qmn_, int *qmx_) {
	int l, qmn, qmx, s;

	l = 0;
	qmn = 0, qmx = 0, s = 0;
	for (l += n_, r += n_; l <= r; l >>= 1, r >>= 1)
		if ((r & 1) == 0)
			qmn = min(qmn, qqmn[r] + s), qmx = max(qmx, qqmx[r] + s), s += ss[r], r--;
	*qmn_ = qmn, *qmx_ = qmx;
}

int main() {
	static int ii[N], qqmn[N], qqmx[N], ppmn[N], ppmx[N], bb[N];
	int n, m, k, h, i, j, l, r, pmn, pmx, qmn, qmx, s, good;

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	for (i = 0; i < n; i++)
		ii[i] = i;
	sort(ii, 0, n);
	build(n);
	m = 0;
	for (h = 0; h < n; h++) {
		i = ii[h];
		update(i, -1);
		query_q((l = max(i - k + 1, 0)) - 1, &qmn, &qmx);
		while (l <= i) {
			qqmn[l] = qmn, qqmx[l] = qmx;
			qmn = min(qmn + (aa[l] <= aa[i] ? -1 : 1), 0), qmx = max(qmx + (aa[l] <= aa[i] ? -1 : 1), 0);
			l++;
		}
		query_p((r = min(i + k - 1, n - 1)) + 1, &pmn, &pmx);
		while (r >= i) {
			ppmn[r] = pmn, ppmx[r] = pmx;
			pmn = min((aa[r] <= aa[i] ? -1 : 1) + pmn, 0), pmx = max((aa[r] <= aa[i] ? -1 : 1) + pmx, 0);
			r--;
		}
		l = max(i - k + 1, 0), r = l + k - 1;
		s = 0;
		for (j = l; j <= r; j++)
			s += aa[j] <= aa[i] ? -1 : 1;
		good = 0;
		while (1) {
			if (qqmn[l] + s + ppmn[r] <= -1 && -1 <= qqmx[l] + s + ppmx[r]) {
				good = 1;
				break;
			}
			if (l == i || r == n - 1)
				break;
			s -= aa[l++] <= aa[i] ? -1 : 1, s += aa[++r] <= aa[i] ? -1 : 1;
		}
		if (good)
			bb[m++] = aa[i];
	}
	printf("%d\n", m);
	for (h = 0; h < m; h++)
		printf("%d ", bb[h]);
	printf("\n");
	return 0;
}