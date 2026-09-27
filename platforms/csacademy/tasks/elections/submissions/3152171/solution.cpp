#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb emplace_back
#define AI(i) begin(i), end(i)
template<class T> bool chmin(T &a, T b) { return b < a && (a = b, true); }
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); }
#ifdef KEV
#define DE(args...) kout("[ " + string(#args) + " ] = ", args)
void kout() { cerr << endl; }
template<class T, class ...U> void kout(T a, U ...b) { cerr << a << ' ', kout(b...); }
template<class T> void debug(T l, T r) { while (l != r) cerr << *l << " \n"[next(l)==r], ++l; }
#else
#define DE(...) 0
#define debug(...) 0
#endif

const int MAX_N = 500010;

int n, q;
char w[MAX_N];
int lp[MAX_N], mar[MAX_N], ql[MAX_N], qr[MAX_N];
int res[MAX_N];

vector<pair<int,int>> allq[MAX_N];

bool ban[MAX_N];

// bit tree1
// sgt tree2

struct bit {
	int n;
	vector<int> v;
	bit (int _n) {
		n = _n + 10;
		v.resize(n);
	}
	void add(int i, int val) {
		for (++i;i <= n;i += i&-i)
			v[i] += val;
	}
	int qry(int i) {
		int res = 0;
		for (++i;i;i ^= i&-i) 
			res += v[i];
		return res;
	}
	int qry(int l, int r) { return qry(r) - qry(l-1); }
};
struct sgt {
	struct node {
		int mn, at;
		node () : mn(0), at(0) {}
		void operator += (int v) {
			mn += v, at += v;
		}
		node (node a, node b) {
			mn = min(a.mn, b.mn);
			at = 0;
		}
	};
	int n;
	vector<node> val;
	sgt (int _n) {
		n = _n;
		val.resize(n<<1);
	}
	void push(int i) {
		if (i >= n) return;
		int &at = val[i].at;
		val[i<<1] += at, val[i<<1|1] += at;
		at = 0;
	}
	void upd(int i) {
		if (i >= n) return;
		push(i);
		val[i] = node(val[i<<1], val[i<<1|1]);
	}
	void add(int l, int r, int v) {
		DE(l, r, v);
		int sl = l += n, sr = r += n;
		for (;l < r;l>>=1, r>>=1) {
			if (l&1) val[l++] += v;
			if (r&1) val[--r] += v;
		}
		for (;sl>>=1, sr>>=1;)
			upd(sl), upd(sr);
	}
	int qry(int l, int r) {
		if (l == r) return 0;
		int res = n;
		l += n, r += n;
		for (int i = 20;i > 0;--i) push(l>>i), push(r>>i);
		for (;l < r;l>>=1, r>>=1) {
			if (l&1) chmin(res, val[l++].mn);
			if (r&1) chmin(res, val[--r].mn);
		}
		return res;
	}
};
void solve() {

	bit tree1(n);
	sgt tree2(n);

	for (int i = 0;i < n;++i) {
		if (ban[i]) {
			tree1.add(i, 1);
			continue;
		}
		DE(i, w[i]);
		if (w[i] == 'T') {
			tree2.add(0, i+1, -1);
		}
		if (w[i] == 'C') {
			tree2.add(0, i+1, 1);
		}
	}
	for (int i = 0;i < n;++i) DE(i, tree2.qry(i, i+1));

	for (int i = 0;i < n;++i) {
		for (auto [r, id] : allq[i]) {
			DE(i, r, tree2.qry(r+1, r+2), tree2.qry(i, r+1));
			res[id] = tree1.qry(i, r);
			int suf = tree2.qry(r+1, r+2);
			res[id] += max(0, suf - tree2.qry(i, r+1));
		}
		if (mar[i] == -1) continue;
		int j = mar[i];
		ban[j] = true;
		tree1.add(j, 1);
		tree2.add(0, j+1, 1);
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n >> w;
	{
		vector<int> stk{-1};
		fill(mar, mar + n, -1);
		for (int i = 0;i < n;++i) {
			lp[i] = i;
			if (w[i] == 'C')
				stk.pb(i);
			if (w[i] == 'T') {
				lp[i] = stk.back();
				if (lp[i] == -1) {
					ban[i] = true;
					continue;
				}
				mar[ lp[i] ] = i;
				stk.pop_back();
			}
		}
	}
	cin >> q;
	for (int i = 0;i < q;++i) {
		cin >> ql[i] >> qr[i], --ql[i], --qr[i];
		allq[ ql[i] ].pb( qr[i], i);
	}

	solve();

	for (int i = 0;i < q;++i)
		cout << res[i] << '\n';
}
