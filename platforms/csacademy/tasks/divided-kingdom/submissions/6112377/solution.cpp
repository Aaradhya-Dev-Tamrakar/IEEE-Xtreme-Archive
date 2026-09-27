#include <bits/stdc++.h>
#ifdef LOCAL
char *p1, *p2, buf[100000];
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread (buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++)
#endif
using namespace std;

template <typename T> void read (T &x) {
	x = 0; int f = 1; char ch = getchar ();
	while (!isdigit (ch)) f = (ch == '-') ? -1 : f, ch = getchar ();
	while (isdigit (ch)) x = x * 10 + (ch & 15), ch = getchar (); x *= f;
}

const int N = 100010, M = 500010;
int n, m, ans, fa[N], head[N], to[M], val[M], nxt[M], cnte, col[N], f;
int findfa (int u) { return u == fa[u] ? u : fa[u] = findfa (fa[u]); }
struct edge { int u, v, w; bool operator < (const edge &r) { return w < r.w; } } e[M];
void adde (int u, int v, int w) { to[++cnte] = v, val[cnte] = w, nxt[cnte] = head[u], head[u] = cnte; }

void dfscolor (int u) {
	for (int i = head[u]; i; i = nxt[i]) {
		if (val[i] >= ans) continue;
		if (col[to[i]] == -1) col[to[i]] = col[u] ^ 1, dfscolor (to[i]);
		else if (col[to[i]] != (col[u] ^ 1)) f = 1;
	}
}

bool check (int x) {
	memset (head, 0, sizeof head), cnte = 0, f = 0;
	for (int i = 1; i <= x; i++) {
		adde (e[i].u, e[i].v, e[i].w), adde (e[i].v, e[i].u, e[i].w);
	}
	for (int i = 1; i <= n; i++) col[i] = -1;
	for (int i = 1; i <= n; i++) if (col[i] == -1) {
		col[i] = 0, dfscolor (i);
	}
	return f;
}

signed main () {
	read (n), read (m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		read (e[i].u), read (e[i].v), read (e[i].w);
		fa[findfa (e[i].v)] = findfa (e[i].u);
		adde (e[i].u, e[i].v, e[i].w), adde (e[i].v, e[i].u, e[i].w);
	}
	ans = 1e9;
	if (n <= 2) { puts ("-1"); return 0; }
	for (int u = 1; u <= n; u++) {
		int mn1 = 1e9, mn2 = 1e9;
		for (int i = head[u]; i; i = nxt[i]) {
			if (val[i] < mn1) mn2 = mn1, mn1 = val[i];
			else if (val[i] < mn2) mn2 = val[i];
		}
		ans = min (ans, mn1 + mn2);
	}
	sort (e + 1, e + m + 1);
	int l = 1, r = m, mid, best = 0;
	e[0].w = 1e9;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check (mid)) r = mid - 1, best = mid;
		else l = mid + 1;
	}
	int x = min (e[best].w, ans);
	printf("%d", x >= 1e9 ? -1 : x);
	return 0;
}