#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000000

#define MAXN 100000
#define MAXM 250000

struct myc {
    int x, y, z;
    inline bool operator < (const myc &u) const {
        return z < u.z;
    }
} v[MAXM + 1];
int a[MAXN + 1], t[MAXN + 1], cul[MAXN + 1];

int ans1 = INF, ans2 = INF;

int sef(int x) {
    if (t[x] == 0) return x;
    int r = sef(t[x]);
    cul[x] ^= cul[t[x]];
    return t[x] = r;
}

inline void vezi(int x, int y) {
    if (a[x])
        ans1 = min(ans1, a[x] + y);
    else
        a[x] = y;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++)
        cin >> v[i].x >> v[i].y >> v[i].z;
    sort(v + 1, v + m + 1);
    
    int p = 1;
    bool ok = 1;
    while (p <= m && ok) {
        int x = sef(v[p].x), y = sef(v[p].y);
        //cout << v[p].x << ' ' << v[p].y << ' ' << x << ' ' << y << ' ' << cul[v[p].x] << ' ' << cul[v[p].y] << '\n';
        if (x == y) {
            if (cul[v[p].x] == cul[v[p].y])
                ok = 0;
        } else {
            t[x] = y;
            cul[x] = 1 ^ cul[v[p].x] ^ cul[v[p].y];
        }
        if (ok) {
            vezi(v[p].x, v[p].z);
            vezi(v[p].y, v[p].z);
        } else
            ans2 = v[p].z;
        p++;
    }
    int ans = min(ans1, ans2);
    if (ans == INF)
        ans = -1;
        
    cout << ans;
    
    return 0;
}