#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> marbles(n);
    for (int i = 0; i < n; i++) {
        cin >> marbles[i];
    }
    sort(marbles.begin(), marbles.end());
    vector<int> counts;
    int count = 0;
    int last = marbles[0];
    for (int i = 0; i < n; i++) {
        if (marbles[i] == last) {
            count++;
        } else {
            counts.push_back(count);
            count = 1;
            last = marbles[i];
        }
    }
    counts.push_back(count);
    marbles.resize(unique(marbles.begin(), marbles.end()) - marbles.begin());
    long long total_sum = 0;
    int remainder_count = 0;
    for (int i = 0; i < (int) marbles.size(); i++) {
        total_sum += (counts[i] + marbles[i] - 1) / marbles[i] * marbles[i];
        remainder_count += counts[i] % marbles[i] != 0;
    }
    long long answer = (long long) 2e18;
    for (int i = 0; i < (int) marbles.size(); i++) {
        int remaining = remainder_count - (counts[i] % marbles[i] != 0);
        int additional_cost = marbles[i] == 1 || counts[i] % marbles[i] == 1 ? marbles[i] : 0;
        int extra = remaining ? 0 : (marbles[i] == 1 ? 2 : 1);
        answer = min(answer, total_sum - additional_cost + extra);
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num_test_cases;
    cin >> num_test_cases;
    while (num_test_cases--) {
        solve();
    }
}
