#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf ("%d", &n);
    
    int a[n];
    for (int i=0; i<n; i++) scanf ("%d", a + i);
    
    int mini = a[0];
    int maxi = a[0];
    
    for (int i=1; i<n; i++) 
        mini = min(mini, a[i]), maxi = max(maxi, a[i]);
    
    int l = 0;
    int r = -1;
    int cnt2, cnt1 = cnt2 = 0;
    
    int ans = 5555;
    while (r < n) {
        while (r < n && (!cnt1 || !cnt2)) {
            r++;
            cnt1 += a[r] == mini;
            cnt2 += a[r] == maxi;
        }
        
        while (l <= r && cnt1 && cnt2) {
            ans = min(ans, r - l + 1);
            cnt1 -= a[l] == mini;
            cnt2 -= a[l] == maxi;
            l++;
        }
    }
    
    return 0 * printf ("%d\n", ans);
}