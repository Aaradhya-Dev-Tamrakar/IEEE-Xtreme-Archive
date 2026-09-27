#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int aa[N];

int solve(int a, int a_) {
	return a_ == 1 ? 1 : a % 2 == 0 ? solve(a / 2, a_ / 2) : solve((a + 1) / 2, (a_ + 1) / 2) + a_ / 2;
}

int main() {
	int n, a_; cin >> a_ >> n;
	int i_ = -1;
	while (n--) {
		int a; cin >> a;
		int i = solve(a, a_);
		if (i_ != -1 && i != i_ + 1) {
			cout << "0\n";
			return 0;
		}
		i_ = i;
	}
	cout << "1\n";
	return 0;
}
