#include <algorithm>
#include <iostream>
using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;
const int inf = 1e9;

int a[100000], b[100000];

void solve() {
    int n, k, m;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll result = 0;
    k = __gcd(n, k);
    for(int i = 0; i < k; i++) {
        m = 0;
        for(int j = i; j < n; j += k) {
            b[m++] = a[j];
        }
        nth_element(b, b + m / 2, b + m);
        for(int j = i; j < n; j += k) {
            result += abs(b[m / 2] - a[j]);
        }
    }
    cout << result;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
