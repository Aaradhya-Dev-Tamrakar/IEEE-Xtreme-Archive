#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int n, m;

int getPos(int l, int r, int x) {
	if (l == r) return x;
	if (x & 1) {
		int cnt = r / 2 - (l - 1) / 2;
		int cnt2 = (x - 1) / 2;
		return getPos(1, r - cnt, x - cnt2) + cnt;
	} else {
		int cnt = r / 2 - (l - 1) / 2;
		return getPos(l, l + cnt - 1, x / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	int prv = -1;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		int curr = getPos(1, n, x);
		if (prv == -1) {
			prv = curr;
		} else {
			if (curr != prv + 1) {
				cout << 0;
				return 0;
			}
			prv = curr;
		}
	}
	cout << 1;
	
	
	return 0;
	
}