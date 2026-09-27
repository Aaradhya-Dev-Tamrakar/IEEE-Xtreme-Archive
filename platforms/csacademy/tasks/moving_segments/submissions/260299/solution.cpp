#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 100005;
int n;
int a[MAXN][2];

long long score(long long dest) {
    long long ans = 0LL;
    for (int i = 0; i < n; ++i) {
        if (dest < a[i][0]) {
            ans += a[i][0] - dest;
        } else if (dest > a[i][1]) {
            ans += dest - a[i][1];
        }
    }
    
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
 
    long long lo = -1e9 - 7;
    long long hi = 1e9 + 7;
    
    while (lo + 2 < hi) {
        long long m1 = lo + (hi - lo) / 3;
        long long m2 = lo + 2 * (hi - lo) / 3;
        //printf("%lld %lld %lld %lld\n", lo, m1, m2, hi);
        //printf("%lld %lld\n", score(m1), score(m2));
        if (m1 >= m2) break;
        
        if (score(m1) > score(m2)) {
            lo = m1;
        } else {
            hi = m2;
        }
    }

    printf("%lld\n", min(score(lo + 1), score(hi - 1)));
    return 0;
}