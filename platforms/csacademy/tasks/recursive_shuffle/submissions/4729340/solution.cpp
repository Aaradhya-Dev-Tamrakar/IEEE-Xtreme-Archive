#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
#include <list>
#include <map>
#include <iostream>
#include <iomanip>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()

using ll = long long;

int f(int x, int n) {
    if(n == 1) {
        return 1;
    }
    if(x & 1) {
        return n / 2 + f((x+1)/ 2, (n+1)/2);
    }
    return f(x / 2, n / 2);
}

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    int base = f(x, n);
    for(int i = 1; i < m; i++) {
        cin >> x;
        if(base + i != f(x, n)) {
            cout << 0;
            return;
        }
    }
    cout << 1;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
