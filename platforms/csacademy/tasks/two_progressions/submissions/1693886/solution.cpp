#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int n;
int arr[N];

bool check(int p1r, int c)
{
    int p1s = arr[0], p1c = 1;
    int p2s = 0, p2c = 0, p2r = 0;
    bool ok = true;
    for (int j = 1; j < n; ++j) {
        if (p1c < c && arr[j] == p1s+p1c*p1r) {
            ++p1c;
        } else if (p2c == 0) {
            p2s = arr[j];
            p2c = 1;
        } else if (p2r == 0) {
            p2r = arr[j]-p2s;
            p2c = 2;
            if (p2r == 0) {
                ok = false;
                break;
            }
        } else if (arr[j] == p2s+p2c*p2r) {
            ++p2c;
        } else {
            ok = false;
            break;
        }
    }
    return ok;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        bool done = false;
        for (int i = 1; i < n; ++i) {
            int p1s = arr[0], p1c = 1, p1r = arr[i]-arr[0];
            int p2s = 0, p2c = 0, p2r = 0;
            bool ok = true;
            for (int j = 1; j < n; ++j) {
                if (arr[j] == p1s+p1c*p1r) {
                    ++p1c;
                } else if (p2c == 0) {
                    p2s = arr[j];
                    p2c = 1;
                } else if (p2r == 0) {
                    p2r = arr[j]-p2s;
                    p2c = 2;
                    if (p2r == 0) {
                        ok = false;
                        break;
                    }
                } else if (arr[j] == p2s+p2c*p2r) {
                    ++p2c;
                } else {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            int b = 2, e = n-2;
            while (b < e) {
                int m = (b+e)/2;
                if (check(p1r, m))
                    e = m;
                else
                    b = m+1;
            };
            printf("%d %d %d\n", p1s, p1r, b);
            done = true;
            break;
        }
        if (!done) printf("-1\n");
    }

    return 0;
}
