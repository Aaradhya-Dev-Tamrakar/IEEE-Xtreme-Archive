//#define  NDEBUG

//#pragma optimize("tree-vectorize")
//#pragma optimize ("fast-math")
//#pragma optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#define all(v)                  v.begin(), v.end()
#define db(x)                   cout << #x << " = " << (x) << "\n"
#define fend(x)                 ((x) & ((x)+1)) - 1
#define fenu(x)                 (x) | ((x)+1)
#define forn(i, n)              for (int i = 0; i < (int)n; ++i)
#define for1n(i, b, e)          for (int i = b; i < (int)e; ++i)
#define ft                      first
#define len(s)                  s.length()
#define mp                      std::make_pair
#define pob                     pop_back
#define pof                     pop_front
#define pub                     push_back
#define puf                     push_front
#define sc                      second

typedef double dbl;
typedef long double ldbl;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const long long MILLER_RABIN = 3215031751;
const long double PI = acos(-1);

#if __cplusplus >= 201103L

struct config_io {
    config_io() {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios_base::sync_with_stdio(false);
    }
} cnf_io;

struct config_rand {
    config_rand() {
        srand(chrono::duration_cast<chrono::nanoseconds>(
                chrono::high_resolution_clock::now().time_since_epoch()).count());
    }
} cnf_rand;

namespace std {
    template<>
    struct hash<pair<int, int> > {
        size_t operator()(const pair<int, int>& x) const {
            return (x.first * 71ll + x.second) % ((int) 1e9 + 7);
        }
    };

    template<>
    struct hash<vector<int>> {
        size_t operator()(const vector<int>& v) const {
            size_t hsh = 0;
            for (int i = 0; i < v.size(); ++i) {
                hsh = (hsh * 71ll + v[i]) % (int) (1e9 + 7);
            }
            return hsh;
        }
    };
}

// __builtin_popcount(x) - Returns the number of 1-bits in x.
// __builtin_parity(x) - Returns the parity of x, i.e. the number of 1-bits in x modulo 2.
// __builtin_ffs(x) - Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
// __builtin_clz(x) - Returns the number of leading 0-bits in x, starting at the most significant bit position. If x is 0, the result is undefined.
// __builtin_ctz(x) - Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.

//inline string tobin(long long x) { bitset<63>(x).to_string(); }


template<class T>
void trace(T collection) {
    for (auto elem : collection) { cout << elem << " "; }
    cout << endl;
}

#endif

typedef pair<pair<int, int>, int> ppi;

void process(vector<ppi>& plat, vector<int>& pt, int n, int m) {
    sort(all(plat), [](const ppi& p1, const ppi& p2) {
        return p1.first.second < p2.first.second ||
               (p1.first.second == p2.first.second &&
                (p1.first.second - p1.first.first < p2.first.second - p2.first.first));
    });
    sort(all(pt));
    vector<pair<int, int>> gaps;
    int pt_ptr = 0;
    forn(i, n) {
        int l = plat[i].first.first, r = plat[i].first.second;
        while (pt_ptr < m && pt[pt_ptr] < r) {
            if (pt_ptr == 0) {
                gaps.push_back(mp(1e9, pt[0]));
            }
            else {
                auto cur = mp(pt[pt_ptr] - pt[pt_ptr - 1] + 1, pt[pt_ptr]);
                while (gaps.back().first <= cur.first) gaps.pop_back();
                gaps.push_back(cur);
            }
            pt_ptr++;
        }
        if (pt_ptr - 1 < 0 || pt[pt_ptr - 1] <= l) {
            plat[i].second = 0;
            continue;
        }
        int L = 0, R = gaps.size();
        while (R - L > 1) {
            int mid = (L + R) / 2;
            gaps[mid].first < (r - l + 1) ? R = mid : L = mid;
        }
        plat[i].second = min(plat[i].second, r - gaps[L].second);
    }
}

void solve(int test) {
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int, int>, int>> plat(n);
    vector<int> pt(m);
    forn(i, n) {
        cin >> plat[i].first.first >> plat[i].first.second;
        plat[i].second = 1e9;
    }
    forn(i, m) {
        cin >> pt[i];
    }
    sort(all(pt));
    pt.resize(unique(all(pt)) - pt.begin());

    process(plat, pt, n, m);

    forn(i, n) {
        plat[i].first.first = 100000001 - plat[i].first.first;
        plat[i].first.second = 100000001 - plat[i].first.second;
        swap(plat[i].first.first, plat[i].first.second);
    }
    forn(i, m) {
        pt[i] = 100000001 - pt[i];
    }
    process(plat, pt, n, m);

    ll ans = 0;
    forn(i, n) {
        ans += plat[i].second;
    }
    cout << ans << endl;
}

int main() {
#ifdef HOME
    freopen("home.in", "r", stdin);
    freopen("home.out", "w", stdout);
#endif

    int tests = 1;
    //cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        solve(test);
    }

#ifdef HOME
    cout << "\n\nTime: " << clock() / (double) CLOCKS_PER_SEC << endl;
#endif
    return 0;
}