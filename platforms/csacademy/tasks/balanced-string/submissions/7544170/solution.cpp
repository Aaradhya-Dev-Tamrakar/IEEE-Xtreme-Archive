// Author: albertting
// Time: 2026/09/21 09:10:40
#include <bits/stdc++.h>
#define __Made return
#define in 0
#define China__ ;
#define ll long long
#define ld long double
#define lll __int128
#define pb push_back
#define uset unordered_set
#define umap unordered_map
using namespace std;

int solve(string s) {
    if(s.length() == 1) return 1;
    int n = s.length();

    bool hasAA = 0, hasBB = 0;
    for(int i = 0; i < n; i++) {
        char c = s[i], d = s[(i + 1) % n];
        if(c == d) (c == 'A' ? hasAA : hasBB) = 1;
    }
    if(hasAA && hasBB) return 0;
    if(hasBB)
        for(auto &c : s) c = (c == 'A' ? 'B' : 'A');

    vector<int> a;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') cur++;
        else { a.pb(cur); cur = 0; }
    }
    a.pb(cur);
    if(a.size() > 1) {
        if(s[0] == 'A' && s[n - 1] == 'A') { a[0] += a.back(); a.pop_back(); }
        else if (s[0] == 'B') { a.back() += a[0]; a.erase(a.begin()); }
        else a.pop_back();
    }

    int mn = INT_MAX, mx = INT_MIN;
    for(auto x : a) { mn = min(mn, x); mx = max(mx, x); }
    if(mx > mn + 1) return 0;
    string t;
    for(auto x : a) t.pb(x == mn ? 'A' : 'B');
    return solve(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), clog.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << solve(s) << '\n';
    }
    __Made in China__
}
