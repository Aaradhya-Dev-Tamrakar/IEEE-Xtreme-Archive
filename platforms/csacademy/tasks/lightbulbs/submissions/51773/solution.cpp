#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long dp[2][100];

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int n = s.size();
    if (s[0] == '0') {
        dp[0][0] = 0;
        dp[1][0] = 1;
    }
    else {
        dp[0][0] = 1;
        dp[1][0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == '0') {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1] + (1ll << i);
        }
        else {
            dp[0][i] = dp[1][i - 1] + (1ll << i);
            dp[1][i] = dp[0][i - 1];
        }
    }
    cout << dp[0][n - 1] << "\n";
}