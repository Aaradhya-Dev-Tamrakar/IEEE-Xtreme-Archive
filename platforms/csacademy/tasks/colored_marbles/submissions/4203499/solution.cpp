/**
 *    title:  Colored Marbles
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    int cnt = 0;
    int lst = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] == lst) {
            cnt++;
        } else {
            b.push_back(cnt);
            cnt = 1;
            lst = a[i];
        }
    }
    b.push_back(cnt);
    a.resize(unique(a.begin(), a.end()) - a.begin());
    long long sum = 0;
    int rems = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        sum += (b[i] + a[i] - 1) / a[i] * a[i];
        rems += b[i] % a[i] != 0;
    }
    long long ans = (long long) 2e18;
    for (int i = 0; i < (int) a.size(); i++) {
        int rems_ = rems - (b[i] % a[i] != 0);
        int cost = a[i] == 1 || b[i] % a[i] == 1 ? a[i] : 0;
        int extra = rems_ ? 0 : (a[i] == 1 ? 2 : 1);
        ans = min(ans, sum - cost + extra);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
