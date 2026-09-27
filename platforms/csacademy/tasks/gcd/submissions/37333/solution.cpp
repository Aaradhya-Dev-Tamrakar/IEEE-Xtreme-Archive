#include <cstdio>
#include <iostream>

using namespace std;

int a, b;

int gcd(int a, int b) {
    if(!b) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    cin >> a >> b;
    cout << gcd(a, b);
}