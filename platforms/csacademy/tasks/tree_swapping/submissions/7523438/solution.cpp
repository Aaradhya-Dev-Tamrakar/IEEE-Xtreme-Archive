#include <bits/stdc++.h>
using namespace std;

#define forw(i, l, r) for(int i = (l); i < (r); i++)
#define forb(i, r, l) for(int i = (r); i >= (l); i--)
#define Pi acos(-1.0l)
#define log2i(x) (64 - __builtin_clzll(1ll * (x)) - 1)
#define getBit(x, i) ((x) >> (i) & 1)
#define numBit(x) (__builtin_popcountll(1ll * (x)))
#define mask(x) ((1ll << (x)) - 1)
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    #define rd() (rng() >> 1)
    unsigned int res = 0;
    forw(i, 0, 8) {
        res <<= 4;
        res |= rd() & 15;
    }
    return l + res % (1ll * r - l + 1);
}

const int N = 5e6 + 7;
int n, numEdges, numG;
string st;
int edgesListPtr[N], from[N], to[N], nxtEdge[N];
int colorOffset[N];
long long dp[N];

void addEdge(int f, int t) {
    from[numEdges] = f;
    to[numEdges] = t;
    nxtEdge[numEdges] = edgesListPtr[f];
    edgesListPtr[f] = numEdges++;
}

void input() {
    cin >> n >> st;
    numEdges = numG = 0;
    for (int i = 0; i < n; i++) {
        edgesListPtr[i] = -1;
        numG += (st[i] == 'B');
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        addEdge(u, v);
        addEdge(v, u);
    }
}

void dfs(int &cnt, int u, int h, int par = -1) {
    cnt += h;
    dp[u] = 0;
    colorOffset[u] = h - (st[u] == 'B');
    for (int idx = edgesListPtr[u], v; idx != -1; idx = nxtEdge[idx]) {
        v = to[idx];
        if (v == par) continue;
        dfs(cnt, v, 1 ^ h, u);
        dp[u] += abs(colorOffset[v]) + dp[v];
        colorOffset[u] += colorOffset[v];
    }
}

void solve() {
    int tmpCnt = 0;
    long long ans = -1;

    dfs(tmpCnt, 0, 0);
    if (tmpCnt == numG) ans = dp[0];

    tmpCnt = 0;
    dfs(tmpCnt, 0, 1);
    if (tmpCnt == numG) ans = (ans == -1 ? dp[0] : min(ans, dp[0]));

    cout << ans << '\n';
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(nullptr);
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);

    int testcase = 1;
//    cin >> testcase;
    while (testcase--) {
        input();
        solve();
    }

    return 0;
}
