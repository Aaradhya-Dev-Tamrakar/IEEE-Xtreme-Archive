#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int tt, n;
const int N = 5e4 + 10;
char c[N];
signed main(void) {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tt;
    while (tt --) {
    	string s;
    	cin >> s;
    	n = s.size();
    	for (int i = 1; i <= n; i ++) c[i] = s[i - 1];
    	int cntb = 0, cnta = 0;
    	for (int i = 1; i <= n; i ++) {
    		cntb += (c[i] == 'B');
    		cnta += (c[i] == 'A');
    	}
    	int sum = 0, maxn = 0, minn = 0;
    	for (int i = 1; i <= n; i ++) {
    		sum += (c[i] == 'A' ? cntb : - cnta);
    		maxn = max(maxn, sum);
    		minn = min(minn, sum);
    	}
    	cout << (maxn - minn < n) << endl;
    }
    return 0;
}