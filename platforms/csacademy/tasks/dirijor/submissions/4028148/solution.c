#include <stdio.h>
#include <string.h>

#define N	250
#define INF	0x7fffffff

int min(int a, int b) { return a < b ? a : b; }

int main() {
	static int aa[N], bb[N], bbb[N][N][N], dp[N][N][N + 1];
	int n, k, i, l, r, m, tmp;

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
	for (l = n - 1; l >= 0; l--)
		for (r = l; r < n; r++)
			for (m = 0; m <= r - l; m++) {
				if ((l + n - 1 - r + m) % 2 != 0 || l + n - 1 - r + m > k * 2)
					continue;
				if (l + n - 1 - r + m == k * 2)
					dp[l][r][m] = 0;
				else {
					if (m > 0 && aa[l] >= bbb[l][r][m - 1])
						dp[l][r][m] = dp[l + 1][r][m - 1];
					else if (m > 0 && aa[r] >= bbb[l][r][m - 1])
						dp[l][r][m] = dp[l][r - 1][m - 1];
					else
						dp[l][r][m] = min(dp[l + 1][r][m + 1] + aa[l] + bbb[l + 1][r][m], dp[l][r - 1][m + 1] + aa[r] + bbb[l][r - 1][m]);
				}
			}
	printf("%d\n", dp[0][n - 1][0]);
	return 0;
}