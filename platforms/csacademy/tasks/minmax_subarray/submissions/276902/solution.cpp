#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    int nums[N];
    int omax = -1;
    int omin = 2000000000;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        omax = max(omax, nums[i]);
        omin = min(omin, nums[i]);
    }
    int pmin =  -50001;
    int pmax = -50001;
    int ans = N;
    for (int i = 0; i < N; i++) {
        if (nums[i] == omax) {
            pmax = i;
            ans = min(ans, pmax-pmin + 1);
        }
        if (nums[i] == omin) {
            pmin = i;
            ans = min(ans, pmin-pmax + 1);
        }
    }
    cout << ans << endl;
    
}