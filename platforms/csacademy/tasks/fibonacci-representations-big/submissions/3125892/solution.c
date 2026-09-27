#include <stdio.h>

#define Q	100000
#define Q_	(Q * 3)
#define MD	1000000007

unsigned int Z = 12345;

int rand_() {
	return (Z *= 3) >> 1;
}

int zz[1 + Q_], ll[1 + Q_], rr[1 + Q_], xx[1 + Q_], xx_[1 + Q_], aa[1 + Q_], bb[1 + Q_], cc[1 + Q_], dd[1 + Q_], aa_[1 + Q_], bb_[1 + Q_], cc_[1 + Q_], dd_[1 + Q_]; char all2[1 + Q_], is2[1 + Q_]; int u_, l_, r_;

int node(int x) {
	static int _ = 1;

	zz[_] = rand_();
	xx_[_] = xx[_] = x;
	aa_[_] = aa[_] = (x + 1) / 2, bb_[_] = bb[_] = (x + 1) % 2, cc_[_] = cc[_] = aa[_] - 1, dd_[_] = dd[_] = (x + 1) % 2;
	all2[_] = is2[_] = x == 2;
	return _++;
}

void pul(int u) {
	int l = ll[u], r = rr[u], a, b, c, d;

	xx_[u] = xx_[l] + xx[u] + xx_[r];
	a = ((long long) aa_[r] * aa[u] + (long long) bb_[r] * cc[u]) % MD;
	b = ((long long) aa_[r] * bb[u] + (long long) bb_[r] * dd[u]) % MD;
	c = ((long long) cc_[r] * aa[u] + (long long) dd_[r] * cc[u]) % MD;
	d = ((long long) cc_[r] * bb[u] + (long long) dd_[r] * dd[u]) % MD;
	aa_[u] = ((long long) a * aa_[l] + (long long) b * cc_[l]) % MD;
	bb_[u] = ((long long) a * bb_[l] + (long long) b * dd_[l]) % MD;
	cc_[u] = ((long long) c * aa_[l] + (long long) d * cc_[l]) % MD;
	dd_[u] = ((long long) c * bb_[l] + (long long) d * dd_[l]) % MD;
	all2[u] = all2[l] && is2[u] && all2[r];
}

void split_x(int u, int x) {
	int xl;

	if (u == 0) {
		u_ = l_ = r_ = 0;
		return;
	}
	xl = xx_[ll[u]];
	if (xl + xx[u] <= x) {
		split_x(rr[u], x - xl - xx[u]);
		rr[u] = l_, l_ = u;
	} else if (xl > x) {
		split_x(ll[u], x);
		ll[u] = r_, r_ = u;
	} else {
		u_ = u, l_ = ll[u], r_ = rr[u];
		ll[u] = rr[u] = 0;
	}
	pul(u);
}

void split2l(int u) {
	if (u == 0) {
		u_ = l_ = r_ = 0;
		return;
	}
	if (!all2[ll[u]]) {
		split2l(ll[u]);
		ll[u] = r_, r_ = u;
	} else if (is2[u]) {
		split2l(rr[u]);
		rr[u] = l_, l_ = u;
	} else {
		u_ = u, l_ = ll[u], r_ = rr[u];
		ll[u] = rr[u] = 0;
	}
	pul(u);
}

void split2r(int u) {
	if (u == 0) {
		u_ = l_ = r_ = 0;
		return;
	}
	if (!all2[rr[u]]) {
		split2r(rr[u]);
		rr[u] = l_, l_ = u;
	} else if (is2[u]) {
		split2r(ll[u]);
		ll[u] = r_, r_ = u;
	} else {
		u_ = u, l_ = ll[u], r_ = rr[u];
		ll[u] = rr[u] = 0;
	}
	pul(u);
}

int merge(int u, int v) {
	if (u == 0)
		return v;
	if (v == 0)
		return u;
	if (zz[u] < zz[v]) {
		rr[u] = merge(rr[u], v), pul(u);
		return u;
	} else {
		ll[v] = merge(u, ll[v]), pul(v);
		return v;
	}
}

void upd_last(int u, int x) {
	if (rr[u] == 0) {
		xx[u] += x;
		aa[u] = (xx[u] + 1) / 2, bb[u] = (xx[u] + 1) % 2, cc[u] = aa[u] - 1, dd[u] = (xx[u] + 1) % 2;
		is2[u] = xx[u] == 2;
	} else
		upd_last(rr[u], x);
	pul(u);
}

int main() {
	int q;

	scanf("%d", &q);
	aa_[0] = aa[0] = 1, bb_[0] = bb[0] = 0, cc_[0] = cc[0] = 0, dd_[0] = dd[0] = 1, is2[0] = all2[0] = 1;
	while (q--) {
		int x, l, r, u, v;

		scanf("%d", &x);
		split_x(u_, x), u = u_, l = l_, r = r_;
		if (xx_[l] < x) {
			if (u && x + 1 == xx_[l] + xx[u]) {
				split2l(r);
				l = merge(l, node(xx[u] + 1 + xx_[l_])), r = u_ == 0 ? 0 : merge(node(xx[u_] - 1), r_);
			} else if (l && xx_[l] + 1 == x) {
				if (xx[u] != 3)
					upd_last(l, 2), r = u == 0 ? 0 : merge(node(xx[u] - 2), r);
				else {
					split2l(r);
					upd_last(l, 4 + xx_[l_]), r = u_ == 0 ? 0 : merge(node(xx[u_] - 1), r_);
				}
			} else
				r = u == 0 ? 0 : merge(node(xx_[l] + xx[u] - x), r), l = merge(l, node(x - xx_[l]));
		} else {
			split2r(l), v = u_;
			if (v == 0)
				l = merge(node(1), r_);
			else if (xx[v] == 1)
				l = merge(node(2), r_);
			else if (l_ && xx[v] == 3)
				upd_last(l_, 2), l = merge(merge(l_, node(2)), r_);
			else
				l = merge(merge(l_, merge(node(xx[v] - 2), node(3))), r_);
			if (u != 0) {
				if (xx[u] != 2)
					r = merge(node(xx[u] - 1), r);
				else {
					split2l(r);
					upd_last(l, 2 + xx_[l_]), r = u_ == 0 ? 0 : merge(node(xx[u_] - 1), r_);
				}
			}
		}
		u_ = merge(l, r);
		printf("%d\n", aa_[u_]);
	}
	return 0;
}
