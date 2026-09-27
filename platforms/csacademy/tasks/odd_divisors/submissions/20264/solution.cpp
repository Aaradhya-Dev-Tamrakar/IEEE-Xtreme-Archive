#include <cstdio>

using namespace std;

int t, a, b;

long long prog(int x) {
    return (1ll * x * (x + 1)) / 2;
}

long long func(int n) {
    int k = (n + 1) / 2;
    return 2 * prog(k - 1) + k;
}

long long solve(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return func(n) + solve(n / 2);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", solve(b) - solve(a - 1));
    }
    return 0;
}