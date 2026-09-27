#include <stdio.h>

#define N	5000
#define INF	0x7fffffff

int min(int a, int b) { return a < b ? a : b; }

int solve(int *aa, int n, int k) {
	int bb[N];
	int m, i, j, l, r, ans;

	if (k == 0)
		return 0;
	ans = INF;
	for (i = 0; i + 1 < n; i++) {
		l = -1;
		for (j = 0; j <= i; j++)
			if (l == -1 || aa[l] < aa[j])
				l = j;
		r = -1;
		for (j = i + 1; j < n; j++)
			if (r == -1 || aa[r] < aa[j])
				r = j;
		m = 0;
		for (j = 0; j < n; j++)
			if (j != l && j != r)
				bb[m++] = aa[j];
		ans = min(ans, solve(bb, n - 2, k - 1) + aa[l] + aa[r]);
	}
	return ans;
}

int main() {
	static int aa[N];
	int n, k, i;

	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
		scanf("%d", &aa[i]);
	printf("%d\n", solve(aa, n, k));
	return 0;
}