#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define fillchar(a, s) memset((a), (s), sizeof(a))

int N;
char S[52];
bitset<52> A;

ll solve (bitset<52> b, int n) {
	if (n == 1) {
		return b[0];
	}

	if (b[n - 1]) {
		return (1ll << n) - 1 - solve(b, n - 1);
	} else {
		return solve(b, n - 1);
	}
}

int main() {
	scanf("%s", S);
	N = strlen(S);
	for (int i = 0; i < N; i++) {
		A[i] = (S[N - 1 - i] == '1');
	}
	printf("%lld\n", solve(A, N));
}
