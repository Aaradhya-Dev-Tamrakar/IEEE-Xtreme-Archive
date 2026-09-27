#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn], b[Maxn];

ll Get(ll x)
{
    ll res = 0;
    for (int i = 0; i < n; i++)
        if (x < a[i]) res += a[i] - x;
        else if (x > b[i]) res += x - b[i];
    return res;
}

int main() 
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i], &b[i]);
    int lef = -1000000000, rig = 1000000000;
    while (lef <= rig) {
        int mid = lef + rig >> 1;
        if (Get(mid) < Get(mid + 1)) rig = mid - 1;
        else lef = mid + 1;
    }
    cout << Get(rig + 1) << endl;
    return 0;
}