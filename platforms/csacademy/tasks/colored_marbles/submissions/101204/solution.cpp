#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100000;
int a[N];

int Main () {
    int n;
    scanf ("%d", &n);

    for (int i=0; i<n; i++) scanf ("%d", a + i);
    
    long long ans = 0;
    
    int space = 0;
    int one = 0;
    int cnt = 0;
    
    sort (a, a + n);
    for (int i=0, nxt; i<n; i=nxt) {
        cnt++;
        nxt = upper_bound (a + i, a + n, a[i]) - a;
        
        int mod = (nxt - i) % a[i];
        if (mod) {
            if (mod > 1) space++;
            else {
                if (one) space++;
                one = a[i];
            }
            
            ans += a[i] - mod;
        }
        
        ans += nxt - i;
    }
    
    if (one && space) ans -= one;
    else if (one && !space) ans -= one - 1;
    else if (space && a[0] == 1) ans--;
    else if (space && cnt > 1);
    else ans++;
    
    printf ("%lld\n", ans);
    return 0;
}

int main() {
    int t;
    scanf ("%d", &t);
    while (t--) Main ();
    return 0;
}
