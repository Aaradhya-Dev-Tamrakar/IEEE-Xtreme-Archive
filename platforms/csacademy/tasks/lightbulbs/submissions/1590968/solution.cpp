#include <bits/stdc++.h>

using namespace std;

char s[55];
long long dp[55], dp2[55];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);

	scanf("%s", s+1);
	long long n = strlen(s+1);
	if (s[n] == '1')
		dp[n] = 1;
	else
		dp2[n] = 1;
	for (long long i = n-1; i > 0; i--) {
		if (s[i] == '1') {
			dp2[i] = dp[i+1];
			dp[i] = dp2[i+1]+(1ll<<(n-i));
		} else {
			dp[i] = dp[i+1];
			dp2[i] = dp2[i+1]+(1ll<<(n-i));
		}
	}
	cout << dp[1] << endl;
	return 0;
}
