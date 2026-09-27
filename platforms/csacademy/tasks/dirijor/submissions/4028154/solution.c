#include <stdio.h>
#include <string.h>

#define N	250
#define N_	(1 << 12)	/* N_ = pow2(ceil(log2(N))) */
#define INF	0x7fffffff

int min(int a, int b) { return a < b ? a : b; }

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

int kk[N_ * 2], ss[N_ * 2], n_;

void pul(int i) {
	int l = i << 1, r = l | 1;

	kk[i] = kk[l] + kk[r], ss[i] = ss[l] + ss[r];
}

void update(int i) {
	i += n_;
	kk[i] = 0, ss[i] = 0;
	while (i > 1)
		pul(i >>= 1);
}

int query_k(int l) {
	int r = n_ - 1, k = 0;

	for (l += n_, r += n_; l <= r; l >>= 1, r >>= 1)
		if ((l & 1) == 1)
			k += kk[l++];
	return k;
}

int query_s(int k) {
	int i, s;

	if (k >= kk[1])
		return ss[1];
	i = 1, s = 0;
	while (i < n_)
		if (k < kk[i << 1 | 0])
			i = i << 1 | 0;
		else
			s += ss[i << 1 | 0], k -= kk[i << 1 | 0], i = i << 1 | 1;
	return s;
}

int main() {
	static int ii[N], bb[N], dp[N][N];
	int n, k, i, l, r, m, ans, sum;

	scanf("%d%d", &n, &k);
	sum = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &aa[i]);
		sum += aa[i];
	}
	for (i = 0; i < n; i++)
		ii[i] = i;
	sort(ii, 0, n);
	for (i = 0; i < n; i++)
		bb[ii[i]] = i;
	n_ = 1;
	while (n_ < n)
		n_ <<= 1;
	for (l = 0; l < n; l++)
		for (r = n - 1; r >= 0; r--)
			dp[l][r] = INF;
	dp[0][n - 1] = 0, ans = INF;
	for (l = 0; l < n; l++) {
		for (i = l; i < n; i++)
			ss[n_ + bb[i]] = aa[i], kk[n_ + bb[i]] = 1;
		for (i = n_ - 1; i > 0; i--)
			pul(i);
		for (r = n - 1; r >= l; r--) {
			m = dp[l][r];
			if (m == INF)
				continue;
			if (l + n - 1 - r + m == k * 2) {
				ans = min(ans, sum - query_s(n - k * 2));
				continue;
			}
			if (query_k(bb[l]) <= m)
				dp[l + 1][r] = min(dp[l + 1][r], m - 1);
			else if (query_k(bb[r]) <= m)
				dp[l][r - 1] = min(dp[l][r - 1], m - 1);
			else
				dp[l + 1][r] = min(dp[l + 1][r], m + 1), dp[l][r - 1] = min(dp[l][r - 1], m + 1);
			update(bb[r]);
		}
	}
	printf("%d\n", ans);
	return 0;
}