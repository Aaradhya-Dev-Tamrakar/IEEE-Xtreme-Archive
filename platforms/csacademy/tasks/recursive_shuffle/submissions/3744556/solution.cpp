#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int v[100005];

bool legit(int l, int r, int k) {
    if ((1<<(k)) > 2*n)
        return 0;
        
    if (l == r)
        return 1;

    int m = -1;
    bool zeros = false;
    for (int i = l; i <= r; i++) {
        if ((v[i] & (1<<k)) > 0) {
            m = i;
            if (zeros)
                return false;
        }
        if ((v[i] & (1<<k)) == 0) {
            zeros = true;
        }
    }
    
    if (m == -1)
        return legit(l, r, k + 1);
    if (m == r)
        return legit(l, r, k + 1);

    return legit(l, m, k + 1) && legit(m + 1, r, k + 1);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &v[i]);
        v[i]--;
    }
    
    printf("%d\n", legit(1, m, 0));
    return 0;
}