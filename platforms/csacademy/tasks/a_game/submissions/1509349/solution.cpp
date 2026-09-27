#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int result = 0, num_a = 0, b_streak = 0;
    char c;
    while (cin >> c) {
        cerr << c << '\n';
        if (c == 'B') {
            b_streak += 1;
        } else {
            result ^= b_streak;
            b_streak = 0;
            num_a += 1;
        }
    }
    
    
    cerr << num_a << '\n';
    
    result ^= b_streak;
    
    if (num_a % 2 == 0) {
        cout << "-1\n";
    } else {
        cout << (result != 0 ? 'A' : 'B');
    }
    
    return 0;
}
