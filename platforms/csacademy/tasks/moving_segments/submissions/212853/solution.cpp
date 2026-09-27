#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define fr first
#define sc second
#define pb push_back
#define mpr make_pair
#define ppb pop_back()
#define ins insert
#define sz(s) int(s.size())
#define all(x) x.begin(), x.end()
#define lb lower_bound
#define ub upper_bound
const int N = 1e5 + 7, INF = 1e9;
int n, a[N], b[N];
ll f(int x){
	ll res = 0;
	for(int i = 1;i <= n; ++ i){
		if(a[i] <= x && x <= b[i])continue;
		res += min(abs(x - a[i]), abs(x - b[i]));
	}
	return res;
}
int main()
{
	cin >> n;
	for(int i = 1;i <= n; ++ i){
		cin >> a[i] >> b[i];
	}
	int l = -INF, r = INF;
	while(l < r){
		int len = (r - l + 1) / 3;
		int l2 = l + len;
		int r2 = l2 + len;
		r2 += (r2 == l2);
		if(f(l2) < f(r2))r = r2 - 1;
		else l = l2 + 1;
	}
	cout << f(l);
	return 0;
}