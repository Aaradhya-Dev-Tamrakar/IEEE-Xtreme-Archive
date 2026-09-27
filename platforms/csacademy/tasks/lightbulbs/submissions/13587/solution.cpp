#include <iostream>

using namespace std;

long long dp1[60]; ///Turn on i and turn off (i + 1)...n
long long dp2[60]; ///Turn off i...n

string str;

long long n;

inline long long change(long long pos) {
    return ((long long) 1 << (n - pos + 1)) - 1;
}

int main() {
    cin >> str;
    n = str.size();
    dp1[n] = (str[n - 1] == '0');
    dp2[n] = (str[n - 1] == '1');

    for(int i = n - 1; i >= 1; --i) {
        if(str[i - 1] == '1') {
            dp1[i] = dp2[i + 1]; ///Turn 1 into 1 and the rest into 0
            dp2[i] = dp1[i + 1] + 1 + change(i + 1); ///Turn next into 1, curr into 0, then next into 0
        }
        else {
            dp1[i] = dp1[i + 1] + 1 + change(i + 1); ///Turn next into 1, curr into 1, then next into 0
            dp2[i] = dp2[i + 1]; ///Turn 0 into 0 and the rest into 0
        }
    }

    cout << dp2[1] << '\n';
    return 0;
}
