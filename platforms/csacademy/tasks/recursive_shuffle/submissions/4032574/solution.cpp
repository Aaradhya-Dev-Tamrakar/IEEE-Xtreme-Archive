#define wiwihorz
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma loop-opt(on)

#define rep(i, a, b) for(int i = a; i <= b; i ++)
#define rrep(i, a, b) for(int i = b; i >= a; i --)
#define ceil(a, b) ((a + b - 1) / (b))
#define all(x) x.begin(), x.end()

#define INF 1000000000000000000
#define MOD 1000000007
#define eps (1e-9)

using namespace std;

#define int long long int
#define lld long double
#define pii pair<int, int>
#define random mt19938 rnd(chrono::steady_clock::now().time_since_epoch().count())

#ifdef wiwihorz
#define print(a...) cerr << "Line " << __LINE__ << ": ", kout("[" + string(#a) + "] = ", a)
void vprint(auto L, auto R) { while(L < R) cerr << *L << " \n"[next(L) == R], ++L;}
void kout() { cerr << endl; }
template<class T1, class ... T2> void kout(T1 a, T2 ... e) { cerr << a << " ", kout(e...); }
#else
#define print(...) 0
#define vprint(...) 0
#endif
namespace solver {
	int n, m;
	vector<int> a;
	void init_(int _n, int _m) {
		n = _n, m = _m;
		a.assign(m + 1, 0);
	}
	int f(int sz, int x) {
		if(sz == 1) return 0;
		if(x & 1) return f(sz / 2, x / 2);
		else return f(ceil(sz, 2), x / 2) + sz / 2;
	}
	bool solve() {
		if(m > n) return 0;
		a[1] = f(n, a[1] - 1);
		rep(i, 2, m) {
			int cur = f(n, a[i] - 1);
			if(cur != a[i - 1] + 1 || a[i] > n) return 0;
			else a[i] = cur;
		}
		return 1;
	}

};
using namespace solver;
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m; cin >> n >> m;
	init_(n, m);
	rep(i, 1, m) cin >> a[i];
	cout << solve() << "\n";	
	return 0;
}