/**
 _  _   __  _ _ _  _  _ _
 |a  ||t  ||o    d | |o  |
| __    _| | _ | __|  _ |
| __ |/_  | __  /__\ / _\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100000;
const int MOD = (int) 1e9 + 7;

int pwr (const int &a, const int &b) {
    if (b == 0) {
        return 1;
    } else if (b & 1) {
        return (ll) a * pwr(a, (b ^ 1)) % MOD;
    } else {
        int aux = pwr(a, (b >> 1));
        return (ll) aux * aux % MOD;
    }
}
int inv (const int &a) {
    return pwr(a, MOD - 2);
}

int N;
int A[N_MAX + 2];

int fact[N_MAX + 2];
int ifact[N_MAX + 2];

void precalc () {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = (ll) fact[i - 1] * i % MOD;
    }
    ifact[N] = inv(fact[N]);
    for (int i = N - 1; i >= 0; i--) {
        ifact[i] = (ll) ifact[i + 1] * (i + 1) % MOD;
    }
}

int choose (const int &a, const int &b) {
    return (ll) fact[a] * ifact[b] % MOD * ifact[a - b] % MOD;
}

int prog_sum (const int &a) {
    return (ll) a * (a + 1) / 2 % MOD;
}

int M;
int B[N_MAX + 2];

int dp[N_MAX + 2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + N + 1);
    precalc();
    M = 1; B[1] = 0;
    for (int i = 2; i <= N; i++) {
        if (A[i] != A[i - 1]) {
            M++;
        }
        B[M]++;
    }
    if (B[1] == 0) {
        reverse(B + 1, B + M + 1);
        M--;
        reverse(B + 1, B + M + 1);
    }
    dp[0] = 1;
    int behind = 0;
    for (int i = 1; i <= M; i++) {
        int ways = dp[i - 1];
        for (int j = 1; j <= B[i] - 1; j++) {
            ways = (ll) ways * prog_sum(j) % MOD;
        }
        dp[i] = 0;
        for (int j = 1; j <= B[i]; j++) {
            dp[i] = (dp[i] + (ll) ways * j % MOD * choose(behind + B[i] - j, behind)) % MOD;
        }
        behind += B[i];
    }
    cout << dp[M] << "\n";

    return 0;
}
