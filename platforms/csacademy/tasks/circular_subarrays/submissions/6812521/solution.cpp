#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if(!(cin >> N >> K)) return 0;
    vector<long long> a(N);
    for(int i = 0; i < N; ++i) cin >> a[i];

    int g = std::gcd(N, K);
    long long cost = 0;

    vector<vector<long long>> buckets(g);
    for(int i = 0; i < N; ++i) buckets[i % g].push_back(a[i]);

    for(int r = 0; r < g; ++r){
        auto &v = buckets[r];
        sort(v.begin(), v.end());
        long long med = v[v.size()/2];
        for(long long x : v) cost += llabs(x - med);
    }

    cout << cost << '\n';
    return 0;
}
