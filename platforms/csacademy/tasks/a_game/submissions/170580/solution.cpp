#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n >> s;
    
    int cnt = 0;
    int cur = 0, ans = 0;
    
    for (int i = 0; i < n; i++)
        if (s[i] == 'A') {
            cnt++;
            ans ^= cur;
            cur = 0;
        } else
            cur++;
    ans ^= cur;
    
    if (cnt % 2 == 0)
        cout << -1 << endl;
    else
        cout << (ans ? "A" : "B") << endl;
}