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
#define debug(args...) cerr << "Line(" << __LINE__ << ") -> [" << #args << "] is [", Debug(false, args), cerr << "]" << endl
#define debuga(i) cerr << "Line(" << __LINE__ << ") -> [" << #i << "] is ", Debuga(i, sizeof(i) / sizeof(typeid(*i).name()))
#else
#define debug(args...) void(0)
#define debuga(i) void(0)
#endif
typedef long long ll;
typedef pair<int, int> pi;
const int inf = 0x3f3f3f3f, lg = 20;
const ll mod = 1e9 + 7, INF = 0x3f3f3f3f3f3f3f3f;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int, pi> e[m];
    int ans = inf, mn[n];
    fill(mn, mn + n, inf);
    for (auto &[x, y] : e) {
        cin >> y.first >> y.second >> x;
        --y.first, --y.second;
        ans = min(ans, x + min(mn[y.first], mn[y.second]));
        mn[y.first] = min(mn[y.first], x), mn[y.second] = min(mn[y.second], x);
    }
    vector<int> rt(2 * n);
    iota(all(rt), 0);
    function<int(int)> find = [&](int i) {
        return rt[i] = rt[i] == i ? i : find(rt[i]);
    };
    sort(e, e + m);
    for (auto [x, y] : e) {
        if (x >= ans)
            return cout << ans, 0;
        int i = y.first, j = y.second;
        rt[find(i)] = find(n + j);
        rt[find(j)] = find(n + i);
        if (find(i) == find(n + i))
            return cout << x, 0;
    }
    cout << (ans == inf ? -1 : ans);
}
 