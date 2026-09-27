#include <bits/stdc++.h>
using namespace std;
int p = 1000000007;
int n, x;
int f[100020];
int v[100020];
int C(int n, int m) {
	return (long long)f[n] * v[m] % p * v[n - m] % p;
}
int main() {
	map<int, int> g;
	long long s = 1;
	scanf("%d", &n);
	v[1] = 1;
	for (int i = 2; i <= n; i++) {
		v[i] = (long long)v[p % i] * (p - p / i) % p;
	}
	v[0] = 1;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = (long long)f[i - 1] * i % p;
		v[i] = (long long)v[i - 1] * v[i] % p;
//		cout << f[i] << ' ' << v[i] << endl;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		g[x]++;
	}
	int l = 0;
	for (pair<int, int> i: g) {
		if (l > 0) {
			long long t = s;
			s = 0;
			for (int j = 0; j < i.second; j++) {
				s = (s + t * C(l + j - 1, j) % p * (i.second - j) % p) % p;
//				cout << s << ' ' << t << ' ' << C(l + j, j) << endl;
			}
		}
		l += i.second;
		for (int j = i.second; j >= 2; j--) {
			s = s * ((long long)j * (j - 1) / 2 % p) % p;
		}
//		cout << s << endl;
	}
	printf("%lld\n", s);
	return 0;
}