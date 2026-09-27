#include <cstdio>

long long sqr(long long a) { return a * a; }

void solve()
{
    long long a, b, s = 0;
    scanf("%lld %lld", &a, &b); a--;
    while (a != b)
    {
        s += sqr((b + 1) / 2) - sqr((a + 1) / 2);
        a /= 2; b /= 2;
    }
    printf("%lld\n", s);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}
