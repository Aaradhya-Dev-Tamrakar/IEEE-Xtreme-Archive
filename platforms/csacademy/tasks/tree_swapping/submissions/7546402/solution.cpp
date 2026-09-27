#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    static char buf[100005];
    scanf("%s", buf);
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> par(n + 1, 0), dep(n + 1, 0), ord;
    ord.reserve(n);
    ord.push_back(1);
    for (int i = 0; i < (int)ord.size(); i++) {
        int v = ord[i];
        for (int u : g[v])
            if (u != par[v]) {
                par[u] = v;
                dep[u] = dep[v] + 1;
                ord.push_back(u);
            }
    }
    int r = 0, p0 = 0;
    for (int v = 1; v <= n; v++) {
        if (buf[v - 1] == 'R') r++;
        if (dep[v] % 2 == 0) p0++;
    }
    int p1 = n - p0;
    long long best = -1;
    for (int t = 0; t < 2; t++) {
        int sz = t == 0 ? p0 : p1;
        if (sz != r) continue;
        vector<long long> d(n + 1, 0);
        for (int v = 1; v <= n; v++) {
            int cur = buf[v - 1] == 'R';
            int tar = (dep[v] % 2 == t);
            d[v] = cur - tar;
        }
        long long cost = 0;
        for (int i = n - 1; i >= 1; i--) {
            int v = ord[i];
            cost += llabs(d[v]);
            d[par[v]] += d[v];
        }
        if (best < 0 || cost < best) best = cost;
    }
    printf("%lld\n", best);
    return 0;
}