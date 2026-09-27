#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod = 1000000007, oo = 1000000009;

void Emsawy() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define clr(v,d)     memset(v, d, sizeof(v))
#define sz(v)	     ((int)((v).size()))
#define all(v)	     ((v).begin()), ((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define V	         vector
#define MP	         make_pair
#define bug(n)           cout<< #n <<" = "<< n << endl;
int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

V<V<int> > adj;
const ll N = 100000 + 5;
int n, m, k, w;

int main() {

	Emsawy();
	string s;
	while (cin >> s){
		int st = 0;
		while (st < s.size() && s[st] == '0') st++;
		s = s.substr(st);
		bitset<60> bt;
		bt[0] = 1;
		bool ok = 1;
		for (int i = 1; i < s.size(); i++){
			if (ok){
				if (s[i] == '1'){
					ok = 0;
					continue;
				}
				bt[i] = 1;
			}
			if (!ok){
				if (s[i] == '1'){
					ok = 1;
					bt[i] = 1;
				}
			}
		}
		ll ans = 0;
		for (int i = s.size() - 1; i >= 0; i--){
			if (bt[i]){
				ans += 1;
				ans += (1LL << (s.size() - i - 1));
				ans -= 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
