#include <cassert>
#include <cstdio>

#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 50;

int n;
string s;

long long solve(int i, char target) {
    if (i == n-1) {
        if (s[i] == target) return 0;
        else return 1;
    }
    if (s[i] == target) return solve(i + 1, '0');
    return 1 + solve(i + 1, '1') + ((1LL << (n - i - 1)) - 1);
}

int main() {
    cin >> s;
    n = s.size();
    
    assert(1 <= n && n <= MAX_N);
    for (auto ch : s) {
        assert(ch == '0' || ch == '1');
    }
    
    cout << solve(0, '0');
}
