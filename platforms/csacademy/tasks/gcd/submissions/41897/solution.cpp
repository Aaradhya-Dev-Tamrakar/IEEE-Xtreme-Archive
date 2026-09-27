#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;
    return gcd(a, b % a);
}

int main() {
    ios::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);
}