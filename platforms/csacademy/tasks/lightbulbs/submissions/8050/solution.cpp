#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char s[100];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    int cur = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' != cur) {
            cur = 1;
            sum += 1LL << (n - 1 - i);
        } else {
            cur = 0;
        }
    }
    printf("%lld\n", sum);
    return 0;
}
