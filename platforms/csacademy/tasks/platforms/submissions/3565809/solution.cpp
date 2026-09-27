#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include <unistd.h>
#include <tuple>
#include <vector>
#include <algorithm>

#define GU p1 == p2 && (p2 = (p1 = buf) + read (0, buf, BUF_SIZE), p1 == p2) ? -1 : *p1++
#define PU(x) vi[p3++]=x

const int BUF_SIZE = 1 << 16, T_SIZE = 20;
static char buf[BUF_SIZE], vi[BUF_SIZE], *p1 = buf, *p2 = buf;
static int p3;

int in() {
    int re = 0;
    char c = GU;
    while (c == ' ' || c == '\n') {
        c = GU;
    }
    bool f = 0;
    if (c == '-') {
        f = 1, c = GU;
    }
    while (c >= '0' && c <= '9') {
        re = (re << 3) + (re << 1) + (c ^ '0'), c = GU;
    }
    return f ? -re : re;
}

void out (long long x) {
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

#define Waimai ios::sync_with_stdio(false),cin.tie(0)
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define pb emplace_back
#define F first
#define S second

const int SIZE = 1e5 + 5;
const int INF = 2e9;

int n, m;
int gap[SIZE];
std::tuple<int, int, int> p[SIZE];
int x[SIZE], ans[SIZE];
std::vector<int> st;

void solve() {
    n=in(),m=in();
    FOR (i, 1, n) {
        auto &[lp, rp, id] = p[i];
        lp = in(), rp = in(), id = i;
    }
    FOR (i, 1, m) x[i] = in();
    std::fill (ans + 1, ans + n + 1, INF);
    std::sort (p + 1, p + n + 1);
    std::sort (x + 1, x + m + 1);
    x[m + 1] = x[m] + INF;
    FOR (i, 1, m) gap[i] = x[i + 1] - x[i];
    int pos = m;
    for (int i = n; i >= 1; i--) {
        auto [lp, rp, id] = p[i];
        while (pos >= 1 && lp <= x[pos]) {
            while (st.size() && gap[pos] >= gap[st.back()]) {
                st.pop_back();
            }
            st.pb (pos--);
        }
        if (pos == m || rp <= x[pos + 1]) {
            ans[id] = 0;
            continue;
        }
        int l = 0, r = st.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (gap[st[mid]] >= rp - lp) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans[id] = std::min (ans[id], x[st[l]] - lp);
    }
    FOR (i, 1, n) {
        auto &[lp, rp, id] = p[i];
        lp = -lp, rp = -rp;
        std::swap (lp, rp);
    }
    FOR (i, 1, m) x[i] = -x[i];
    std::sort (p + 1, p + n + 1);
    std::sort (x + 1, x + m + 1);
    x[m + 1] = x[m] + INF;
    FOR (i, 1, m) gap[i] = x[i + 1] - x[i];
    pos = m;
    st.clear();
    for (int i = n; i >= 1; i--) {
        auto [lp, rp, id] = p[i];
        while (pos >= 1 && lp <= x[pos]) {
            while (st.size() && gap[pos] >= gap[st.back()]) {
                st.pop_back();
            }
            st.pb (pos--);
        }
        if (pos == m || rp <= x[pos + 1]) {
            ans[id] = 0;
            continue;
        }
        int l = 0, r = st.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (gap[st[mid]] >= rp - lp) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans[id] = std::min (ans[id], x[st[l]] - lp);
    }
    long long sum = 0;
    FOR (i, 1, n) sum += ans[i];
    out (sum);
}

int main() {
    //Waimai;
    solve();
    write (1, vi, p3);
}
