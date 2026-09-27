#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
#include <bitset>

#define f first
#define s second
#define pb push_back
#define NMAX 100000
#define pii pair <int, int>

using namespace std;

char buffer[NMAX + 10];
int bufpoz = NMAX + 10;

inline void get (int &n);

inline long long compute (int a)
{
    if (!a) return 0LL;
    if (a == 1) return 1LL;

    int b = a;
    if (!(a & 1)) --a;

    return 1LL * (a + 1) * (a + 1) / 4LL + compute (b / 2);
}

int main ()
{
    //freopen ("file.in", "r", stdin);

    int t;
    get (t);

    for (; t; --t)
    {
        int a, b;
        get (a);
        get (b);

        printf ("%lld\n", compute (b) - compute (a - 1));
    }

    return 0;
}

inline void get (int &n)
{
    n = 0;
    if (bufpoz > NMAX)
        fread (buffer, NMAX, 1, stdin), bufpoz = 0;

    int semn = 1;
    while ('0' > buffer[bufpoz] || buffer[bufpoz] > '9')
    {
        if (buffer[bufpoz] == '-') semn = -1;

        if (++bufpoz == NMAX)
            fread (buffer, 1, NMAX, stdin), bufpoz = 0;
    }

    while ('0' <= buffer[bufpoz] && buffer[bufpoz] <= '9')
    {
        n = n * 10 + buffer[bufpoz] - 48;
        if (++bufpoz == NMAX)
            fread (buffer, 1, NMAX, stdin), bufpoz = 0;
    }

    n *= semn;
}
