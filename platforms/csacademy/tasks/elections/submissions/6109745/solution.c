#include <stdio.h>

#define N	500000

int max(int a, int b) { return a > b ? a : b; }

int ss[N * 2], pp[N * 2], qq[N * 2], xx[N * 2], n;

void build(char *cc) {
	int i;

	for (i = 0; i < n; i++)
		if (cc[i] == 'C')
			ss[n + i] = pp[n + i] = qq[n + i] = xx[n + i] = 1;
		else
			ss[n + i] = -1, pp[n + i] = qq[n + i] = xx[n + i] = 0;
	for (i = n - 1; i > 0; i--) {
		int l = i << 1 | 0, r = i << 1 | 1;

		ss[i] = ss[l] + ss[r];
		pp[i] = max(pp[l], ss[l] + pp[r]);
		qq[i] = max(ss[r] + qq[l], qq[r]);
		xx[i] = max(max(xx[l], xx[r]), qq[l] + pp[r]);
	}
}

int query(int l, int r) {
	int s = 0, x = 0, p = 0, q = 0;

	for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
		if ((l & 1) == 1) {
			s += ss[l];
			x = max(max(x, xx[l]), q + pp[l]);
			q = max(q + ss[l], qq[l]);
			l++;
		}
		if ((r & 1) == 0) {
			s += ss[r];
			x = max(max(xx[r], x), qq[r] + p);
			p = max(p + ss[r], pp[r]);
			r--;
		}
	}
	x = max(x, q + p);
	return x - s;
}

int main() {
	static char cc[N + 1];
	int q;

	scanf("%d%s%d", &n, cc, &q);
	build(cc);
	while (q--) {
		int l, r;

		scanf("%d%d", &l, &r), l--, r--;
		printf("%d\n", query(l, r));
	}
	return 0;
}
