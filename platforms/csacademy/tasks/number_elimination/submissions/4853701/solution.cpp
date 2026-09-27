#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#ifdef local
#define safe cerr<<__PRETTY_FUNCTION__<<" line "<<__LINE__<<" safe\n"
#define pary(a...) danb(#a, a)
#define debug(a...) qqbx(#a, a)
template <typename ...T> void qqbx(const char *s, T ...a) {
    int cnt = sizeof...(T);
    ((std::cerr << "\033[1;32m(" << s << ") = (") , ... , (std::cerr << a << (--cnt ? ", " : ")\033[0m\n")));
}
template <typename T> void danb(const char *s, T L, T R) {
    std::cerr << "\033[1;32m[ " << s << " ] = [ ";
    for (int f = 0; L != R; ++L)
        std::cerr << (f++ ? ", " : "") << *L;
    std::cerr << " ]\033[0m\n";
}
#else
#define debug(...) ((void)0)
#define safe ((void)0)
#define pary(...) ((void)0)
#endif // local
#define all(v) begin(v),end(v)
#define pb emplace_back

using namespace std;
using ll = long long;
using ld = long double;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int mod = 1000000007;
const int inf = 1e9;
const ll INF = 1e18;
const int maxn = 100025;

class Mint {
    using T = int;
public:
    constexpr Mint() : v() {}
    template <typename U> Mint(const U &u) { v = mont.from(0 <= u && u < MOD ? u : (u%MOD+MOD)%MOD); }
    template <typename U> explicit operator U() const { return U(mont.get(v)); }
    T operator()() const { return mont.get(v); }
#define REFOP(type, expr...) Mint &operator type (const Mint &rhs) { return expr, *this; }
    REFOP(+=, v += rhs.v - MOD, v += MOD & (v >> width)) 
    REFOP(-=, v -= rhs.v, v += MOD & (v >> width))
    // fits for MOD^2 <= 9e18
    REFOP(*=, v = mont.redc(v, rhs.v))
#define VALOP(op) friend Mint operator op (Mint a, const Mint &b) { return a op##= b; }
    VALOP(+) 
    VALOP(-) 
    VALOP(*)
    Mint operator-() const { return 0 - *this; }
    friend bool operator == (const Mint &lhs, const Mint &rhs) { return lhs.v == rhs.v; }
    friend bool operator != (const Mint &lhs, const Mint &rhs) { return lhs.v != rhs.v; }
    friend std::istream & operator>>(std::istream &I, Mint &m) { T x; I >> x, m = mont.from(x); return I; }
    friend std::ostream & operator<<(std::ostream &O, const Mint &m) { return O << mont.get(m.v); }
private:
    constexpr static int width = sizeof(T) * 8 - 1;
    constexpr static int MOD = mod;
    T v;
    // Montegomery multiplication
    struct Mont {
        int Mod, R1Mod, R2Mod, NPrime;
        Mont(int mod) : Mod(mod) {
            const ll B = (1LL << 32);
            assert((mod & 1) != 0);
            ll R = B % mod;
            ll xinv = 1, bit = 2;
            for (int i = 1; i < 32; i++, bit <<= 1) { // Hensel lifting!
                ll y = xinv * mod;
                if ((y & bit) != 0)
                    xinv |= bit;
            }
            assert(((mod * xinv) & (B-1)) == 1);
            R1Mod = (int)R;
            R2Mod = (int)(R * R % mod);
            NPrime = (int)(B - xinv);
        }
        int redc(int a, int b) {
            ll T = (ll)a * b;
            ll m = (unsigned)T * NPrime;
            T += m * Mod;
            T >>= 32;
            if (T >= Mod)
                T -= Mod;
            return (int)T;
        }
        int from(int x) { assert (x < Mod); return redc(x, R2Mod); }
        int one() { return R1Mod; }
        int get(int a) { return redc(a, 1); }
        int mul(int a, int b) { return redc(a, b); }
    };
    static Mont mont;
};
Mint::Mont Mint::mont(MOD);

Mint fac[maxn], ifac[maxn], inv[maxn];
Mint dfac[maxn];
Mint C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return fac[n] * ifac[k] * ifac[n-k];
}

inline char readchar() {
    constexpr int B = 1<<20;
    static char buf[B], *p, *q;
    if(p == q && (q=(p=buf)+fread(buf,1,B,stdin)) == buf) return EOF;
    return *p++;
}
inline int nextint() {
    int x = 0, c = readchar();
    while(c < '0') c = readchar();
    while(c >= '0') x=x*10+(c^'0'), c=readchar();
    return x;
}
signed main() {
    // ios_base::sync_with_stdio(0), cin.tie(0);
    int n = nextint();
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = nextint();
    sort(all(v));

    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = inv[mod % i] * (mod - mod / i);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i-1] * i, ifac[i] = ifac[i-1] * inv[i];


    dfac[1] = 1;
    Mint sum = 1;
    for (int c = 2; c <= n; c++) {
        dfac[c] = dfac[c-1] * sum;
        sum += c;
    }

    Mint ans = 1;
    int smaller = 0;
    for (int i = 0, j = 0; i < n; i = j) {
        for (j = i; j < n; j++) if (v[i] != v[j]) break;
        int cnt = j - i;
        Mint way = (i ? C(smaller + cnt, cnt - 1) : 1) * dfac[cnt];
        ans = ans * way;
        smaller += cnt;
    }
    cout << ans << '\n';
}
