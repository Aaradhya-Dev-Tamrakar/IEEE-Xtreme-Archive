#include <cstdio>
#include <iostream>

using namespace std;

long long f (int x) {
    if (x == 0) return 0;
    if (x & 1) return x + f(x - 1);
    return 1LL * (x >> 1) * (x >> 1) + f(x >> 1);
}

int main() {
    int t;
    scanf ("%d", &t);
    
    int a, b;
    while (t--) {
        scanf ("%d %d", &a, &b);
        printf ("%lld\n", f(b) - f(a-1));
    }
    return 0;
}