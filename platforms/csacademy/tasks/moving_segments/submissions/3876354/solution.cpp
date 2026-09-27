#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int n;
int x[100000], y[100000];

inline long long value(int xx) {
    long long res = 0;
    for(int i=0; i<n; i++) {
        if(x[i] <= xx && xx <= y[i]) continue;
        res += min(abs(xx - x[i]), abs(xx - y[i]));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];
    int dw = -1e9, up = 1e9;
    while(up - dw > 11) {
        int m1 = dw + (up - dw) / 3;
        int m2 = up - (up - dw) / 3;
        long long v1 = (value(m1));
        long long v2 = (value(m2));
        if(v1 > v2) dw = m1;
        else if(v1 < v2) up = m2;
        else {
            dw = m1;
            up = m2;
        }
    }
    long long mn = (long long) (1e18);
    for(int i=dw; i<=up; i++) mn = min(mn, value(i));
    cout << mn << endl;
    return 0;
}