#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define Waimai ios::sync_with_stdio(false),cin.tie(0)
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define pb emplace_back
#define F first
#define S second

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n + 1], gcd = 0;
    FOR (i, 1, n) cin >> a[i], gcd = __gcd (gcd, a[i]);
    while (q--) {
        int p, x;
        cin >> p >> x;
        a[p] /= x;
        gcd = __gcd (gcd, a[p]);
        cout << gcd << '\n';
    }
}

int main() {
    Waimai;
    solve();
}
