#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wparentheses"
#include <bits/stdc++.h>
#define all(i) (i).begin(), (i).end()
#define random random_device rd; mt19937 rng(rd())
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
void Debug(bool _split) {}
template<typename T1, typename ...T2>
void Debug(bool _split, T1 x, T2 ...args) {
    if (_split)
        cerr << ", ";
    cerr << x, Debug(true, args...);
}
template<typename T>
void Debuga(T *i, int n) {
    cerr << '[';
    for (int j = 0; j < n; ++j) cerr << i[j] << " ]"[j == n - 1];
    cerr << endl;
}
#ifdef SYL
#define debug(args...) cerr << "Line(" << __LINE__ << ") -> [" << #args << "] is [", Debug(false, args), cerr << ']' << endl
#define debuga(i) cerr << "Line(" << __LINE__ << ") -> [" << #i << "] is ", Debuga(i, sizeof(i) / sizeof(typeid(*i).name()))
#else
#define debug(args...) void(0)
#define debuga(i) void(0)
#endif
typedef long long ll;
typedef pair<int, int> pi;
const int inf = 0x3f3f3f3f, lg = 20;
const ll mod = 1e9 + 7, INF = 0x3f3f3f3f3f3f3f3f;

ll modpow(ll i, ll j) {
    ll res = 1;
    for (; j; j >>= 1, (i *= i) %= mod)
        if (j & 1)
            (res *= i) %= mod;
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    const int N = 1e5 + 5;
    int f[N], inv[N];
    f[0] = inv[0] = 1;
    for (int i = 1; i < N; ++i)
        f[i] = 1ll * f[i - 1] * i % mod, inv[i] = modpow(f[i], mod - 2);
    int n;
    cin >> n;
    int a[n];
    for (int &i : a)
        cin >> i;
    sort(a, a + n);
    auto c = [&](int i, int j) {
        return 1ll * f[i] * inv[j] % mod * inv[i - j] % mod;
    };
    ll ans = 1;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1])
            ++cnt;
        else {
            for (int j = 2; j <= cnt; ++j)
                (ans *= c(j, 2)) %= mod;
            if (i > cnt) {
                ll tmp = 0;
                for (int j = 1; j <= cnt; ++j)
                    tmp += 1ll * j * c(i - 1 - j, cnt - j) % mod;
                (ans *= tmp % mod) %= mod;
            }
            cnt = 1;
        }
    }
    for (int j = 2; j <= cnt; ++j)
        (ans *= c(j, 2)) %= mod;
    if (n > cnt) {
        ll tmp = 0;
        for (int j = 1; j <= cnt; ++j)
            tmp += 1ll * j * c(n - 1 - j, cnt - j) % mod;
        (ans *= tmp % mod) %= mod;
    }
    cout << ans << '\n';
}
/*
x = pre ans
k = cnt[nxt]
m = pre len

x * c(k, 2) * c(k-1, 2) * .. * c(2, 2) * sum(c(m-1+k-i, k-i) * i, 1<=i<=k)

*/