#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
const int MAX_N = 100005;

int p[MAX_N];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int posremove = 1;
    for (int i = 1; i <= n; ++ i) {
        p[i] = n + 1;
    }
    for (int x, y, i = 1; i <= m; ++ i) {
        cin >> x >> y;
        swap(p[x], p[y]);
        p[posremove] = min(p[posremove], i);
        if (posremove == x || posremove == y) {
            posremove = x + y - posremove;
        }
        
    }
    cout << p[k] << "\n";
    return 0;}