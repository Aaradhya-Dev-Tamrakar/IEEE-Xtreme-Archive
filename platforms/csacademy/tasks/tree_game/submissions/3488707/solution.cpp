#include <stdio.h>

#define N	100000
#define INF	100000

int max(int a, int b) { return a > b ? a : b; }

struct L {
	struct L *next;
	int j;
} aa[N];

int dp0[N], dp1[N], dp2[N], dp3[N];

void link(int i, int j) {
	static struct L l91[N * 2], *l = l91;

	l->j = j;
	l->next = aa[i].next; aa[i].next = l++;
}

void dfs(int p, int i) {
	struct L *l;
	int j, sum0, sum1, sum2, sum_;

	sum0 = 0, sum1 = -INF, sum2 = -INF, sum_ = 0;
	for (l = aa[i].next; l; l = l->next)
		if ((j = l->j) != p) {
			dfs(i, j);
			sum2 = max(max(sum1, sum2) + dp3[j], sum2 + dp0[j]);
			if (sum2 < 0)
				sum2 = -INF;
			sum1 = max(sum0 + dp3[j], sum1 + dp0[j]);
			if (sum1 < 0)
				sum1 = -INF;
			sum0 += dp0[j];
			sum_ += max(dp0[j], dp1[j] + 1);
		}
	dp0[i] = max(sum0, sum2 + 1);
	dp1[i] = sum1;
	dp2[i] = sum_;
	dp3[i] = max(dp1[i], dp2[i]);
}

int main() {
	int n, h, i, j;

	scanf("%d", &n);
	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		link(i, j), link(j, i);
	}
	dfs(-1, 0);
	printf("%d\n", max(dp0[0], dp3[0]));
	return 0;
}