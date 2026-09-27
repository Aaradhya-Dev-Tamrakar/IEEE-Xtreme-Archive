#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <unistd.h>
#include <algorithm>

#define GU p1 == p2 && (p2 = (p1 = buf) + read (0, buf, BUF_SIZE), p1 == p2) ? -1 : *p1++
#define PU(x) vi[p3++]=x

const int BUF_SIZE = 1 << 16, T_SIZE = 10;
static char buf[BUF_SIZE], vi[BUF_SIZE], *p1 = buf, *p2 = buf;
static int p3;

int in() {
    int re = 0;
    char c = GU;
    while (c == ' ' || c == '\n') {
        c = GU;
    }
    while (c >= '0' && c <= '9') {
        re = (re << 3) + (re << 1) + (c ^ '0'), c = GU;
    }
    return re;
}

void out (int x) {
    char str[T_SIZE];
    int p = 0;
    do {
        str[p++] = '0' ^ (x % 10);
        x /= 10;
    } while (x);
    for (--p; p >= 0; p--) {
        vi[p3++] = str[p];
    }
    vi[p3++] = '\n';
    if (p3 > BUF_SIZE - T_SIZE) {
        write (1, vi, p3), p3 = 0;
    }
}

#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define pb emplace_back
#define F first
#define S second

int main() {
    int n = in();
    int a[n + 1], mn[n + 1];
    FOR (i, 1, n) mn[i] = a[i] = in();
    for (int i = n - 1; i >= 1; i--) {
        mn[i] = std::min (mn[i], mn[i + 1]);
    }
    int ans = 0, mx = -1;
    FOR (i, 1, n) {
        mx = std::max (a[i], mx);
        if (i == n || mx <= mn[i + 1]) {
            ans++;
            mx = -1;
        }
    }
    out (ans);
    write (1, vi, p3);
}
