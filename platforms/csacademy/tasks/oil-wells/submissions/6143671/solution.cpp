#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cmath>
#include <utility>

using namespace std;

typedef long long ll;

// 暴力方法：用于小规模数据 (N ≤ 1000)
void solve_small(int N, int K, vector<ll>& A, set<ll>& medians) {
    for (int l = 0; l < N; l++) {
        vector<ll> window;
        for (int r = l; r < N; r++) {
            window.push_back(A[r]);
            int len = r - l + 1;
            if (len >= K && len % 2 == 1) {
                vector<ll> tmp = window;
                nth_element(tmp.begin(), tmp.begin() + len/2, tmp.end());
                medians.insert(tmp[len/2]);
            }
        }
    }
}

// 基于滑动窗口和平衡检查的方法：用于中等规模数据
void solve_medium(int N, int K, vector<ll>& A, set<ll>& medians) {
    for (int i = 0; i < N; i++) {
        ll x = A[i];
        
        // 计算左右边界
        int left_bound = max(0, i - 2 * K);
        int right_bound = min(N - 1, i + 2 * K);
        int window_size = right_bound - left_bound + 1;
        
        // 创建转换数组和前缀和数组
        vector<int> C(window_size);
        vector<int> prefix(window_size + 1, 0);
        
        for (int j = left_bound; j <= right_bound; j++) {
            int idx = j - left_bound;
            if (A[j] < x) C[idx] = -1;
            else if (A[j] > x) C[idx] = 1;
            else C[idx] = 0;
            
            prefix[idx + 1] = prefix[idx] + C[idx];
        }
        
        // 构建哈希表存储前缀和位置
        unordered_map<int, vector<int>> even_map, odd_map;
        int i_idx = i - left_bound;
        
        for (int j = 0; j <= i_idx; j++) {
            if (j % 2 == 0) {
                even_map[prefix[j]].push_back(j + left_bound);
            } else {
                odd_map[prefix[j]].push_back(j + left_bound);
            }
        }
        
        // 排序以便二分查找
        for (auto& pair : even_map) {
            sort(pair.second.begin(), pair.second.end());
        }
        for (auto& pair : odd_map) {
            sort(pair.second.begin(), pair.second.end());
        }
        
        // 检查所有可能的右端点
        bool found = false;
        for (int r = i; r <= right_bound && !found; r++) {
            int r_idx = r - left_bound;
            int need = prefix[r_idx + 1];
            auto& map = (r % 2 == 0) ? even_map : odd_map;
            
            if (map.find(need) != map.end()) {
                const vector<int>& positions = map[need];
                // 二分查找满足条件的左端点
                auto it = lower_bound(positions.begin(), positions.end(), 
                                     max(0, r - 2 * K));
                if (it != positions.end() && *it <= i && r - *it + 1 >= K) {
                    medians.insert(x);
                    found = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    if (K > N) {
        cout << 0 << endl;
        return 0;
    }
    
    set<ll> medians;
    
    if (N <= 1000) {
        // 小规模数据：使用暴力方法
        solve_small(N, K, A, medians);
    } else {
        // 中等规模数据：使用基于滑动窗口和平衡检查的方法
        solve_medium(N, K, A, medians);
    }
    
    // 输出结果
    cout << medians.size() << endl;
    if (!medians.empty()) {
        for (auto it = medians.begin(); it != medians.end(); ++it) {
            if (it != medians.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }
    
    return 0;
}