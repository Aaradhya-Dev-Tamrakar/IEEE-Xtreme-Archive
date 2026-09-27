#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end(), greater<int>());
        
        long long sum = 0;
        int liar = -1;
        int uncompleted = 0;
        bool has_ones = false;
        
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n && vec[j] == vec[j - 1]) {
                ++j;
            }
            
            if (vec[i] == 1) {
                has_ones = true;
            }
            
            int len = j - i;
            int groups = len / vec[i];
            sum += 1LL * groups * vec[i];
            
            if (len % vec[i] != 0) {
                ++uncompleted;
            }
            
            if (len % vec[i] == 1 && liar == -1) {
                liar = vec[i];
            } else if (len % vec[i] != 0) {
                sum += vec[i];
            }
            i = j - 1;
        }
        
        if (liar == -1 && has_ones && vec[0] != 1 && uncompleted >= 1) {
            --sum;
        } else if (liar == -1 && uncompleted <= 1) {
            ++sum;
        }
        cout << sum << "\n";
    }
    return 0;
}