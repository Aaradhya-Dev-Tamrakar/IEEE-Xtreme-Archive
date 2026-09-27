#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define all(i) (i).begin(), (i).end()
#ifdef SYL
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl
#else
#define debug(x)
#endif
using namespace std;
template<typename T1, typename T2>
ostream& operator << (ostream &i, pair<T1, T2> j) {
    return i << j.first << ' ' << j.second;
}
template<typename T>
ostream& operator << (ostream &i, vector<T> j) {
    i << '{' << j.size() << ':';
    for (T ii : j) i << ' ' << ii;
    return i << '}';
}
typedef long long ll;
typedef pair<int, int> pi;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7, INF = 0x3f3f3f3f3f3f3f3f;

const int N = 5e5 + 5, lg = 20, maxn = N * lg * 2;
int a[N], suf[N], nxt[N][lg];
struct seg {
    static seg mem[maxn], *pmem;
    
    int l, r, v, lz;
    seg *ch[2]{};
    seg() {}
    seg(int _l, int _r) : l(_l), r(_r), v(0), lz(0) {
        if (l < r - 1)
            ch[0] = new (pmem++) seg(l, l + r >> 1), ch[1] = new (pmem++) seg(l + r >> 1, r), pull();
        else
            v = a[l];
    }
    seg(seg *oth) : l(oth->l), r(oth->r), v(oth->v), lz(oth->lz), ch{oth->ch[0], oth->ch[1]} {}
    seg* modify(int _l, int _r, int d) {
        seg *copy = new (pmem++) seg(this);
        if (_l <= l && r <= _r) {
            copy->v += d, copy->lz += d;
            return copy;
        }
        copy->push();
        if (_l < l + r >> 1)
            copy->ch[0] = copy->ch[0]->modify(_l, _r, d);
        if (_r > l + r >> 1)
            copy->ch[1] = copy->ch[1]->modify(_l, _r, d);
        copy->pull();
        return copy;
    }
    void push() {
        if (lz) {
            ch[0] = ch[0]->modify(l, r, lz);
            ch[1] = ch[1]->modify(l, r, lz);
            lz = 0;
        }
    }
    void pull() {
        v = min(ch[0]->v, ch[1]->v);
    }
    int query(int _l, int _r) {
        if (_l <= l && r <= _r)
            return v;
        push();
        int res = inf;
        if (_l < l + r >> 1)
            res = min(res, ch[0]->query(_l, _r));
        if (_r > l + r >> 1)
            res = min(res, ch[1]->query(_l, _r));
        return res;
    }
} seg::mem[maxn], *seg::pmem = mem, *rts[N];
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    string s;
    cin >> n >> s >> q;
    a[0] = 0;
    for (int i = 0; i < n; ++i)
        a[i + 1] = a[i] + (s[i] == 'C' ? 1 : -1);
    int ptr = 0;
    rts[ptr++] = new (seg::pmem++) seg(0, n + 1);
    vector<int> stk;
    suf[n + 1] = 0, stk.push_back(n + 1);
    for (int i = n - 1; ~i; --i) {
        suf[i + 1] = suf[i + 2] + (s[i] == 'C' ? 1 : -1);
        while (!stk.empty() && suf[stk.back()] > suf[i + 1])
            nxt[stk.back()][0] = i + 1, stk.pop_back();
        stk.push_back(i + 1);
    }
    while (!stk.empty())
        nxt[stk.back()][0] = 0, stk.pop_back();
    nxt[0][0] = 0;
    for (int i = 1; i < lg; ++i)
        for (int j = 0; j < n + 2; ++j)
            nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
    s += 'C';
    for (int i = 1; i < n + 2; ++i) {
        if (s[i - 1] == 'C')
            rts[ptr++] = rts[nxt[i][0]];
        else
            rts[ptr++] = rts[nxt[i][0]]->modify(i, n + 1, 1);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        ++r;
        int ans = rts[r]->query(l - 1, l) - rts[r]->query(l - 1, r);
        for (int i = lg - 1; ~i; --i)
            if (nxt[r][i] >= l)
                ans += 1 << i, r = nxt[r][i];
        cout << ans << '\n';
    }
}
/*
[], 1-based
rt[i] : prefix sum when r = i and delete all suf-illegal
bi-lifting calc nums of suf-illegal
pre-illegal = v[l-1] - min{vi, l-1 <= i <= r}
            = rt[r+1].qmin(l-1, l) - rt[r+1].qmin(l-1,r+1)
ans = suf-illegal + pre-illegal

s[i-1]='T'
j=nxt[i]
rt[i] = rt[j].modify(i,i+1,inf).modify(i,n+1,1)
*/