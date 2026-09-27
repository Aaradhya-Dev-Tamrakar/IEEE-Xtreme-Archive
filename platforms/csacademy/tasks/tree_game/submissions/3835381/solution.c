
#include <stdio.h>

#define N	100000
#define INF	100000

int max(int a, int b) { return a > b ? a : b; }

struct L {
	struct L *next;
	int j;
} aa[N];

int d0[N], d1[N], d2[N], d3[N];

void lk(int i, int j) {
	static struct L l91[N * 2], *l = l91;

	l->j = j;
	l->next = aa[i].next; aa[i].next = l++;
}

void df(int p, int i) {
	struct L *l;
	int j, s, s1, s2, s3;

	s = 0, s1 = -INF, s2 = -INF, s3 = 0;
	for (l = aa[i].next; l; l = l->next)
		if ((j = l->j) != p) {
			df(i, j);
			s2 = max(max(s1, s2) + d3[j], s2 + d0[j]);
			if (s2 < 0)
				s2 = -INF;
			s1 = max(s + d3[j], s1 + d0[j]);
			if (s1 < 0)
				s1 = -INF;
			s += d0[j];
			s3 += max(d0[j], d1[j] + 1);
		}
	d0[i] = max(s, s2 + 1);
	d1[i] = s1;
	d2[i] = s3;
	d3[i] = max(d1[i], d2[i]);
}

int main() {
	int n, h, i, j;

	scanf("%d", &n);
	for (h = 0; h < n - 1; h++) {
		scanf("%d%d", &i, &j), i--, j--;
		lk(i, j), lk(j, i);
	}
	df(-1, 0);
	printf("%d\n", max(d0[0], d3[0]));
	return 0;
}
