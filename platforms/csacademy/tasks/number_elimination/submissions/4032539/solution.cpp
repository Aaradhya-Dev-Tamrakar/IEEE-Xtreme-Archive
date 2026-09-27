#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

int invs[MAXN + 12], fact[MAXN + 12];

int Power(int A, int B) {
        int64_t res = 1;
        for (; B; B >>= 1, A = (1ll * A * A) % MOD) {
                if (B & 1) {
                        (res *= A) %= MOD;
                }
        }
        return (int)res;
}

int C(int N, int K) {
        if (K > N || N < 0 || K < 0) {
                return 0;
        }

        return (1ll * (1ll * fact[N] * invs[N - K]) % MOD * invs[K]) % MOD;
}

int P(int N, int K) {
        if (K > N) {
                return 0;
        }

        return (1ll * fact[N] * invs[N - K]) % MOD;
}

void prepare_fact(int N) {
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
                fact[i] = (1ll * fact[i - 1] * i) % MOD;
        }
        invs[N] = Power(fact[N], MOD - 2);
        for (int i = N - 1; i >= 0; i--) {
                invs[i] = (1ll * invs[i + 1] * (i + 1)) % MOD;
        }
}

int32_t main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        prepare_fact(n);
        int64_t res = 1;
        vector<int64_t> prod(n + 1);
        prod[1] = 1;
        for (int i = 2; i <= n; i++) prod[i] = prod[i - 1] * C(i, 2) % MOD;
        int ok = 0;
        for (int i = 0; i < n; i++) {
                int64_t cnt = 1;
                while (i + 1 < n && a[i] == a[i + 1]) cnt++, i++;
                if (ok == 0) {
                        ok = 1;
                        res = prod[cnt];
                        continue;
                }
                int64_t mul = 0;
                for (int j = 0; j < cnt; j++) {
                        mul += 1ll * (cnt - j) * C(i - cnt + j + 1 - 1, j);
                        mul %= MOD;
                }
                res *= mul * prod[cnt] % MOD;
                res %= MOD;
        }
        cout << res;
}