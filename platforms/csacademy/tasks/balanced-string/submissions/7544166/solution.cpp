// Author: albertting
// Time: 2026/09/21 09:10:40
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

bool solve(string s) {
    if (s.length() == 1) return 1;
    int n = s.length();

    // 环形检测：是否同时存在相邻 AA 和相邻 BB（含首尾相接）
    bool hasAA = false, hasBB = false;
    for (int i = 0; i < n; i++) {
        char c = s[i], d = s[(i + 1) % n];
        if (c == d) (c == 'A' ? hasAA : hasBB) = true;
    }
    if (hasAA && hasBB) return 0;
    if (hasBB)  // 只有 B 能相邻：条件关于 A/B 对称（同长子串 |ΔA数|=|ΔB数|），交换后归约为原情况
        for (auto &c : s) c = (c == 'A' ? 'B' : 'A');

    // 编码：每个 B 前的 A-run 长度，末尾再补最后一个 B 之后的 run
    vector<int> a;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') cur++;
        else { a.pb(cur); cur = 0; }
    }
    a.pb(cur);
    // 环形合并相邻的 A-run
    if (a.size() > 1) {
        if (s[0] == 'A' && s[n - 1] == 'A') { a[0] += a.back(); a.pop_back(); }
        else if (s[0] == 'B') { a.back() += a[0]; a.erase(a.begin()); }
        else a.pop_back();  // s[0]=='A' 且 s[n-1]=='B'，尾部是空 run
    }

    int mn = INT_MAX, mx = INT_MIN;
    for (auto x : a) { mn = min(mn, x); mx = max(mx, x); }   // 修复笔误：原来是 mn = max(mx, x)
    if (mx > mn + 1) return 0;
    string t;
    for (auto x : a) t.pb(x == mn ? 'A' : 'B');
    return solve(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}