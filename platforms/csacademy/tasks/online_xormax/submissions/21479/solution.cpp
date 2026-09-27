#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <cassert>
#include <vector>
#define fin cin
#define fout cout
#define N 100100
#define NM 3500100

using namespace std;

//ifstream fin("test-0.in");
//ofstream fout("test-0.ok");

int nr[NM], lef[NM], rig[NM], n, p, S[N], R[N], nods, l[N], r[N], sol[N], op[N], x, cs;

void cpy(int a, int b) {
    lef[a] = lef[b];
    rig[a] = rig[b];
    nr[a] = nr[b] + 1;
}
void insert(int nod, int old, int x, int put) {
    if (!put) {
        return;
    }
    if (put & x) {
        rig[nod] = ++nods;
        cpy(nods, rig[old]);
        insert(rig[nod], rig[old], x, put >> 1);
    } else {
        lef[nod] = ++nods;
        cpy(nods, lef[old]);
        insert(lef[nod], lef[old], x, put >> 1);
        
    }
}
void query(int x, int ra, int rb, int &cs, int put) {
    if (!put) {
        return;
    }
    if (x & put) {
        if (nr[lef[rb]] - nr[lef[ra]] > 0) {
            cs += put;
            query(x, lef[ra], lef[rb], cs, put >> 1);
        } else if (nr[rig[rb]] - nr[rig[ra]] > 0) {
            query(x, rig[ra], rig[rb], cs, put >> 1);
        }
    } else {
        if (nr[rig[rb]] - nr[rig[ra]] > 0) {
            cs += put;
            query(x, rig[ra], rig[rb], cs, put >> 1);
        } else if (nr[lef[rb]] - nr[lef[ra]] > 0) {
            query(x, lef[ra], lef[rb], cs, put >> 1);
        }
        
    }
}
int main () {
    fin >> n;
    assert(n >= 1 && n <= 100000);
    for (int i = 1; i <= n; ++i) {
        fin >> x;
        assert(x >= 0 && x <= 1.e9);
        S[i] = S[i - 1] ^ x;
        R[i] = ++nods;
        cpy(R[i], R[i - 1]);
        insert(R[i], R[i - 1], S[i], 1<<30);
    }
    vector<int> P;
    for (int i = 1; i <= n; ++i) {
        fin >> op[i];
        P.push_back(op[i]);
        l[i] = i + 1;
        r[i] = i - 1;
    }
    sort(P.begin(), P.end());
    int pozu = 1;
    for (auto &it : P) {
        assert(it == pozu);
        pozu++;
    }
    l[0] = 1;
    r[0] = -1;
    l[n + 1] = n + 2;
    r[n + 1] = n;
    for (int i = n; i >= 1; --i) {
        x = S[op[i]] ^ S[op[i] - 1];
        sol[i] = max(sol[i + 1], x);
        p = op[i];
        if (r[p + 1] - l[p + 1] > r[p - 1] - l[p - 1]) {
            for (int j = l[p - 1]; j <= p; ++j) {
                cs = 0;
                x = S[j] ^ S[j - 1];
                sol[i] = max(sol[i], x ^ S[r[p + 1]] ^ S[j]);
                query(x ^ S[j], R[j], R[r[p + 1]], cs, 1<<30);
                sol[i] = max(sol[i], cs);
            }
        } else {
            for (int j = p; j <= r[p + 1]; ++j) {
                cs = 0;
                x = S[j] ^ S[j - 1];
                sol[i] = max(sol[i], x ^ S[j - 1] ^ S[l[p - 1] - 1]);
                query(x ^ S[j - 1], R[l[p - 1] - 1], R[j - 1], cs, 1<<30);
                sol[i] = max(sol[i], cs);
            }
        }
        int nl = min(p, min(l[p - 1], l[p + 1]));
        int nr = max(p, max(r[p + 1], r[p - 1]));
        l[nl] = nl;
        l[nr] = nl;
        r[nl] = nr;
        r[nr] = nr;
    }
    for (int i = 1; i <= n; ++i) {
        fout << sol[i] << "\n";
    }
    
    return 0;
}