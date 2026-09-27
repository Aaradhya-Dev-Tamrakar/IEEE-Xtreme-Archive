#include <bits/stdc++.h>

#define rep(i, s, e) for(int i = s; i <= e; ++i)
#define fep(i, s, e) for(int i = s; i < e; ++i)
#define _rep(i, s, e) for(int i = s; i >= e; --i)
#define _fep(i, s, e) for(int i = s; i > e; --i)

#define int long long
#define pii pair<int, int>

namespace FastIO {
	template <typename _Tp> inline void read(_Tp &x) { int neg = 1; char ch; while(ch = getchar(), !isdigit(ch)) if(ch == '-') neg = -1; x = ch - '0'; while(ch = getchar(), isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ '0'); x *= neg; }
	template <typename _Tp, typename... _Args> inline void read(_Tp &x, _Args &...args) { read(x); read(args...); }
	template <typename _Tp> inline void read(_Tp* begin, _Tp* end) { int len = end - begin; for(int i = 0; i < len; ++i) read(*(begin + i)); }
	template <typename _Tp> inline void write(_Tp x) { if(x < 0) putchar('-'), x= -x; if(x > 9) write(x / 10); putchar(x % 10 + '0'); }
	template <typename _Tp, typename... _Args> inline void write(_Tp x, _Args ...args) { write(x); putchar(' '); write(args...); }
	template <typename _Tp> inline void write(_Tp* begin, _Tp* end) { int len = end - begin; for(int i = 0; i < len; ++i) write(*(begin + i)), putchar(' '); }
}

using namespace std;
using namespace FastIO;

const int inf = numeric_limits<int>::max() / 2;
const int ninf = numeric_limits<int>::min() / 2;
const int mod = 998244353;
const double eps = 0.000001;

struct edge {
	int u, v, w;
	edge() {
		return;
	}
	edge(int uu, int vv, int ww) {
		u = uu, v = vv, w = ww;
		return;
	}
};

int n, m, a, b, c, vis[100005], ans, mn1, mn2;
edge e[250005];
vector<int> to[100005];

bool dfs(int u, int col, int r) {
	vis[u] = col;
	for(int v : to[u]) {
		if(v > r) continue;
		if(e[v].u == u) v = e[v].v;
		else v = e[v].u;
		if(vis[v] and vis[v] == col) return false;
		else if(!vis[v] and !dfs(v, -col, r)) return false;
	}
	return true;
}

bool check(int x) {
	rep(i, 1, n) vis[i] = 0;
	rep(i, 1, n) if(!vis[i]) if(!dfs(i, 1, x - 1)) return false;
	return true;
}

void solve() {
	read(n, m), ans = inf;
	rep(i, 1, m) read(a, b, c), e[i] = edge(a, b, c);
	if(n == 2) return puts("-1"), void();
	sort(e + 1, e + 1 + m, [](edge x, edge y) {
		return x.w < y.w;
	});
	rep(i, 1, m) {
		to[e[i].u].push_back(i);
		to[e[i].v].push_back(i);
	}
	rep(i, 1, n) {
		mn1 = mn2 = inf;
		for(auto j : to[i]) {
			if(e[j].w < mn1) mn2 = mn1, mn1 = e[j].w;
			else if(e[j].w < mn2) mn2 = e[j].w;
		}
		ans = min(ans, mn1 + mn2);
	}
	e[m + 1].w = inf;
	int l = 1, r = m + 1, mid;
	while(l <= r) {
		mid = (l + r) >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	ans = min(ans, e[l - 1].w);
	write(ans >= inf ? -1 : ans);
	return;
}

signed main() {
	// freopen("tour.in", "r", stdin);
	// freopen("tour.out", "w", stdout);
	int T = 1;
	while(T--) solve();
	return 0;
}