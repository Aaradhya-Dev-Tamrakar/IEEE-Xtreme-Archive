#include <bits/stdc++.h>

using namespace std;
int a[10000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
    #endif // ONLINE_JUDGE
    int n, mi = 1e9, mx = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i],
        mi = min(mi,a[i]),
        mx = max(mx,a[i]);

    int pos_min = 0, pos_max = 0, ans = n;
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] == mi)
            pos_min = i;
        if (a[i] == mx)
            pos_max = i;
        if (pos_min && pos_max)
            ans = min(ans, abs(pos_max-pos_min));
    }
    cout << ans + 1;
    return 0;
}
