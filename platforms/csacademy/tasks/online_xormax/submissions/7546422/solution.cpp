#include <bits/stdc++.h>
using namespace std;

const int B = 30;
int n;
vector<array<int, 2>> ch;
vector<int> freeList;

int newNode() {
    int id;
    if (!freeList.empty()) {
        id = freeList.back();
        freeList.pop_back();
    } else {
        id = ch.size();
        ch.push_back({0, 0});
    }
    ch[id] = {0, 0};
    return id;
}

void insertVal(int root, int x) {
    int c = root;
    for (int b = B - 1; b >= 0; b--) {
        int t = (x >> b) & 1;
        if (!ch[c][t]) {
            int nn = newNode();
            ch[c][t] = nn;
        }
        c = ch[c][t];
    }
}

int queryMax(int root, int x) {
    int c = root, r = 0;
    for (int b = B - 1; b >= 0; b--) {
        int t = (x >> b) & 1;
        if (ch[c][t ^ 1]) {
            r |= 1 << b;
            c = ch[c][t ^ 1];
        } else {
            c = ch[c][t];
        }
    }
    return r;
}

void freeTrie(int root) {
    vector<int> st;
    st.push_back(root);
    while (!st.empty()) {
        int c = st.back();
        st.pop_back();
        if (ch[c][0]) st.push_back(ch[c][0]);
        if (ch[c][1]) st.push_back(ch[c][1]);
        freeList.push_back(c);
    }
}

vector<int> par, rt, bst;
vector<vector<int>> vals;

int find(int x) {
    while (par[x] != x) {
        par[x] = par[par[x]];
        x = par[x];
    }
    return x;
}

int main() {
    scanf("%d", &n);
    vector<int> a(n + 1), P(n + 1, 0), p(n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        P[i] = P[i - 1] ^ a[i];
    }
    for (auto &x : p) scanf("%d", &x);
    ch.reserve((size_t)(B + 1) * (n + 2) + 10);
    ch.push_back({0, 0});
    par.resize(n + 1);
    rt.resize(n + 1);
    bst.assign(n + 1, 0);
    vals.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        rt[i] = newNode();
        insertVal(rt[i], P[i]);
        vals[i].push_back(P[i]);
    }
    vector<int> ans(n);
    int best = 0;
    for (int k = n - 1; k >= 0; k--) {
        int i = p[k];
        int x = find(i - 1), y = find(i);
        if (vals[x].size() < vals[y].size()) swap(x, y);
        int cross = 0;
        for (int v : vals[y]) cross = max(cross, queryMax(rt[x], v));
        for (int v : vals[y]) {
            insertVal(rt[x], v);
            vals[x].push_back(v);
        }
        freeTrie(rt[y]);
        vector<int>().swap(vals[y]);
        bst[x] = max(max(bst[x], bst[y]), cross);
        par[y] = x;
        best = max(best, bst[x]);
        ans[k] = best;
    }
    for (int k = 0; k < n; k++) printf("%d\n", ans[k]);
    return 0;
}