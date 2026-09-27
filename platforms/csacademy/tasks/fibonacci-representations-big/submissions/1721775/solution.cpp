#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <climits>
#include <cassert>

using namespace std;

const int module = (int)1e9 + 7;

struct Matrix {
	int a, b, c, d;
	
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0)
		: a(a), b(b), c(c), d(d) {
	}
};

inline Matrix operator*(const Matrix &a, const Matrix &b) {
	return Matrix (
		((int64_t)a.a * b.a + (int64_t)a.b * b.c) % module,
		((int64_t)a.a * b.b + (int64_t)a.b * b.d) % module,
		((int64_t)a.c * b.a + (int64_t)a.d * b.c) % module,
		((int64_t)a.c * b.b + (int64_t)a.d * b.d) % module
	);
}

inline Matrix makeMat(int delta) {
	delta--;
	if (delta & 1) {
		return Matrix(0, 1, module-1, delta/2 + 2);
	} else {
		return Matrix(0, 1, 0, delta/2 + 1);
	}
}

mt19937 rnd(42);

struct Treap {
	Treap *l, *r;
	int y, val, sum, sz;
	Matrix mat;
	
	Treap(int val)
		: l(nullptr), r(nullptr), y(rnd()), val(val), sum(val), sz(1), mat(makeMat(val)) {
	}
	
	Treap() {}
};
typedef Treap *pTreap;

inline int getSum(pTreap t) {
	return t ? t->sum : 0;
}

inline int getSz(pTreap t) {
	return t ? t->sz : 0;
}

inline Matrix getMat(pTreap t) {
	return t ? t->mat : Matrix(1, 0, 0, 1);
}

inline void upd(pTreap t) {
	if (t) {
		t->sum = getSum(t->l) + t->val + getSum(t->r);
		t->sz = getSz(t->l) + 1 + getSz(t->r);
		t->mat = getMat(t->r) * makeMat(t->val) * getMat(t->l);
	}
}

inline bool find(pTreap t, int val) {
	if (!t) {
		return false;
	}
	int mid = getSum(t->l) + t->val;
	if (val < mid) {
		return find(t->l, val);
	} else if (mid == val) {
		return true;
	} else {
		return find(t->r, val - mid);
	}
}

struct SplitPosCondition {
	inline static bool goLeft(pTreap t, int x) {
		return x < getSum(t->l) + t->val;
	}
	
	inline static int mutX(pTreap t, int x) {
		return x - getSum(t->l) - t->val;
	}
};

struct SplitSizeCondition {
	inline static bool goLeft(pTreap t, int x) {
		return x <= getSz(t->l);
	}
	
	inline static int mutX(pTreap t, int x) {
		return x - getSz(t->l) - 1;
	}
};

struct SplitTwoCondition {
	inline static bool goLeft(pTreap t, int) {
		return t->val == 2 && getSum(t->r) == 2 * getSz(t->r);
	}
	
	inline static int mutX(pTreap, int) {
		return 0;
	}
};

template<typename Condition>
inline void split(pTreap t, pTreap &l, pTreap &r, int x) {
	if (!t) {
		l = r = nullptr;
		return;
	}
	if (Condition::goLeft(t, x)) {
		split<Condition>(t->l, l, t->l, x);
		r = t;
	} else {
		split<Condition>(t->r, t->r, r, Condition::mutX(t, x));
		l = t;
	}
	upd(t);
}

// Left half contains all ones with the position <= x
inline void splitPos(pTreap t, pTreap &l, pTreap &r, int x) {
	split<SplitPosCondition>(t, l, r, x);
}

// Left half has exactly x elements
inline void splitSize(pTreap t, pTreap &l, pTreap &r, int x) {
	split<SplitSizeCondition>(t, l, r, x);
}

// Right half contains only twos
inline void splitTwo(pTreap t, pTreap &l, pTreap &r) {
	split<SplitTwoCondition>(t, l, r, 0);
}

inline void merge(pTreap &t, pTreap l, pTreap r) {
	if (!l || !r) {
		t = l ? l : r;
		return;
	}
	if (l->y > r->y) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	upd(t);
}

const int treapSz = 1000000;
static Treap treaps[treapSz];
static pTreap curTreap = treaps, lastTreap = treaps + treapSz;

inline pTreap alloc(int val) {
	assert(curTreap != lastTreap);
	pTreap res = curTreap++;
	*res = Treap(val);
	return res;
}

inline void dealloc(pTreap &) {}

class LongFib {
private:
	pTreap t;
	
	inline bool m_HasBit(int x) {
		return find(t, x);
	}
	
	inline void m_DelBit(int x) {
		pTreap l, m, r;
		splitPos(t, l, r, x);
		splitPos(l, l, m, x-1);
		int add = m->val;
		dealloc(m);
		if (r) {
			splitSize(r, m, r, 1);
			m->val += add; upd(m);
			merge(r, m, r);
		}
		merge(t, l, r);
	}
	
	inline void m_TryDelBit(int x) {
		if (m_HasBit(x)) {
			m_DelBit(x);
		}
	}
	
	inline void m_InsBit(int x) {
		pTreap l, r;
		splitPos(t, l, r, x);
		int add = x - getSum(l);
		pTreap m = alloc(add);
		merge(l, l, m);
		if (r) {
			splitSize(r, m, r, 1);
			m->val = m->val - add; upd(m);
			merge(r, m, r);
		}
		merge(t, l, r);
	}
	
	inline void m_AddZero(int x) {
		if (m_HasBit(x+1)) {
			m_DelBit(x+1);
			m_AddZero(x+2);
		} else if (m_HasBit(x-1)) {
			m_DelBit(x-1);
			m_AddZero(x+1);
		} else {
			m_InsBit(x);
		}
	}
	
	inline void m_AddOne(int x) {
		if (m_HasBit(x-2)) {
			m_DelBit(x);
			m_AddZero(x+1);
			pTreap l, m, r; splitPos(t, l, r, x-2);
			splitSize(r, m, r, 1);
			m->val--; upd(m);
			merge(r, m, r);
			splitTwo(l, l, m);
			merge(r, m, r);
			int add = getSum(l) - 2;
			splitSize(l, l, m, getSz(l) - 1);
			m->val++; upd(m);
			merge(l, l, m);
			merge(t, l, r);
			m_AddZero(add);
		} else {
			m_DelBit(x);
			m_AddZero(x+1);
			m_AddZero(x-2);
		}
	}
	
	inline void m_AddBit(int x) {
		m_HasBit(x) ? m_AddOne(x) : m_AddZero(x);
	}
public:
	inline bool hasBit(int x) {
		return m_HasBit(x + 3);
	}
	
	inline void addBit(int x) {
		m_AddBit(x + 3);
		if (!m_HasBit(1)) {
			m_AddZero(1);
		}
		m_TryDelBit(1);
	}
	
	inline int getAns() {
		if (!m_HasBit(3)) {
			m_InsBit(2);
		}
		pTreap m;
		splitSize(t, m, t, 1);
		int res = 1;
		if (t) {
			pTreap m;
			splitSize(t, m, t, 1);
			Matrix mat = getMat(t);
			mat = mat * Matrix(1, 0, (m->val + 1) / 2, 0);
			res = mat.c;
			merge(t, m, t);
		}
		merge(t, m, t);
		m_TryDelBit(2);
		return res;
	}
	
	LongFib()
		: t(nullptr) {
	}
};

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	LongFib q;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a; a--;
		q.addBit(a);
		cout << q.getAns() << "\n";
	}
	return 0;
}
