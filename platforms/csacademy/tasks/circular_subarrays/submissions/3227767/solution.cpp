#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int a[N];
int b[N];
bool vis[N];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ll cost = 0;
    for (int ik = 0; ik < k; ik++)
    {
        //取中位数
        ll sum = 0;
        int lb = 0;
        for (int i = ik; !vis[i]; i = (i + k) % n)
        {
            vis[i] = true;
            b[lb++] = a[i];
        }
        sort(b, b + lb);
        int mid = lb >> 1;
        for (int i = 0; i < mid; i++)
        {
            sum += b[mid] - b[i];
        }
        for (int i = mid + 1; i < lb; i++)
        {
            sum += b[i] - b[mid];
        }
        cost += sum;
    }
    cout << cost << endl;
    return 0;
}