
#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m; cin >> n >> m;
	vector<array<int, 3>> seg(n);
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r;
		seg[i] = {l, r, i};
	}
	sort(seg.begin(), seg.end(), [&](array<int, 3> a, array<int, 3> b) {
		return (a[1] - a[0]) > (b[1] - b[0]);
	});
	vector<int>point(m);
	for (int &x : point) {
		cin >> x;
	}
	sort(point.begin(), point.end());

	vector<pair<int, int>>space;
	for (int i = 0; i < m; i++) {
		if (i == 0) {
			space.push_back({-1e9, point[i]});
		} else {
			space.push_back({point[i - 1], point[i]});
		}

		if (i == m - 1) {
			space.push_back({point[i], 1e9});
		}
	}
	sort(space.begin(), space.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.second - a.first > b.second - b.first;
	});

	set<int> L, R;
	int cur = 0;
	vector<int>res(n);
	for (auto [l, r, idx] : seg) {
		while (cur < m + 1 && space[cur].second - space[cur].first >= r - l) {
			L.insert(space[cur].first);
			R.insert(space[cur].second);
			cur++;
		}
		auto it1 = L.lower_bound(l);
		auto it2 = R.lower_bound(r);
		res[idx] = 1e9;
		if (it1 != L.end()) {
			res[idx] = min(res[idx], abs(l - *it1));
		}
		if (it1 != L.begin()) {
			res[idx] = min(res[idx], abs(l - *(--it1)));
		}

		if (it2 != R.end()) {
			res[idx] = min(res[idx], abs(r - *it2));
		}
		if (it2 != R.begin()) {
			res[idx] = min(res[idx], abs(r - *(--it2)));
		}
	}

	long long ans = accumulate(res.begin(), res.end(), 0LL);

	cout << ans << '\n';
	return 0;
}	
