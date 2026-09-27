#include <stdio.h>
#include <string.h>

#define N	250
#define INF	0x7fffffff

int min(int a, int b) { return a < b ? a : b; }

int main() {
	static int aa[N], bb[N], bbb[N][N][N], dp[N][N];
	int n, k, i, l, r, r_, m, x, tmp, ans;

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	for (l = 0; l < n; l++)
		for (r = l; r < n; r++) {
			bb[r - l] = aa[r];
			for (i = r - l; i > 0 && bb[i] > bb[i - 1]; i--)
				tmp = bb[i], bb[i] = bb[i - 1], bb[i - 1] = tmp;
			memcpy(bbb[l][r], bb, (r - l + 1) * sizeof *bbb[l][r]);
		}
	for (l = 0; l < n; l++)
		for (r = n - 1; r >= 0; r--)
			dp[l][r] = INF;
	dp[0][n - 1] = 0;
	ans = INF;
	r_ = -1;
	for (l = 0; l < n; l++)
		for (r = n - 1; r > r_; r--) {
			m = dp[l][r];
			if (m == INF)
				continue;
			if (l + n - 1 - r + m == k * 2) {
				x = 0;
				for (i = 0; i < l; i++)
					x += aa[i];
				for (i = r + 1; i < n; i++)
					x += aa[i];
				for (i = 0; i < m; i++)
					x += bbb[l][r][i];
				ans = min(ans, x);
				r_ = r;
				break;
			}
			if (m > 0 && aa[l] >= bbb[l][r][m - 1])
				dp[l + 1][r] = min(dp[l + 1][r], m - 1);
			else if (m > 0 && aa[r] >= bbb[l][r][m - 1])
				dp[l][r - 1] = min(dp[l][r - 1], m - 1);
			else {
				dp[l + 1][r] = min(dp[l + 1][r], m + 1);
				dp[l][r - 1] = min(dp[l][r - 1], m + 1);
			}
		}
	printf("%d\n", ans);
	return 0;
}