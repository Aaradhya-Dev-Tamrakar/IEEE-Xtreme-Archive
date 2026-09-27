#include<bits/stdc++.h>

using namespace std;

# define ll long long
# define N 100
ll dp[N], dn[N], r[N];
char  s[N];
int main() {

    cin >> (s+1);
    int n = strlen(s+1);
    dp[n] = s[n] - '0';
    dn[n] = 1 - dp[n];
    r[n] = 1;
    for(int i = n - 1;i;i--) {
        if (s[i] == '0') {
            dp[i] = dp[i+1];
            dn[i] = dn[i+1] + 1 + r[i+1];
        } else {
            dp[i] = dn[i+1] + 1 + r[i+1];
            dn[i] = dp[i+1];
        }
        r[i] = r[i+1] + r[i+1] + 1;
    }
    cout << dp[1];
}

