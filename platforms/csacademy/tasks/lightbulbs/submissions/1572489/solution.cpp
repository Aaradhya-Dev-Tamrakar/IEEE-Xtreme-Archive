#include <iostream>

using namespace std;

long long x[60];

int main() {
    string s; cin >> s;
    x[1] = 1;
    for (int i = 2; i <= 50; i++) {
        x[i] = x[i-1]*2 + 1;
    }
    long long k = 1;
    int l = s.size();
    long long ans = 0;
    for (int i = 0; i < l; i++) {
        if (s[i] == '1') {
            ans += k * x[l-i];
            k *= -1;
        }
    }
    cout << ans << endl;
    return 0;
}