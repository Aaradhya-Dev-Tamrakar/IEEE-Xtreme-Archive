#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;

int p[MAX_N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int pos_not_remove = 1;
    for (int i = 1; i <= n; ++ i) {
        p[i] = n + 1;
    }
    for (int x, y, i = 1; i <= m; ++ i) {
        cin >> x >> y;
        swap(p[x], p[y]);
        p[pos_not_remove] = min(p[pos_not_remove], i);
        if (pos_not_remove == x || pos_not_remove == y) {
            pos_not_remove = x + y - pos_not_remove;
        }
    }
    cout << p[k] << "\n";
}