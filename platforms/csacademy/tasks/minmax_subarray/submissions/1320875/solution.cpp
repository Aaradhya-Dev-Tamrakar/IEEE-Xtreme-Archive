#include <bits/stdc++.h>
#define fto(i, x, y) for (int i=(x); i <= (y); ++i)
#define fdto(i, x, y) for (int i=(x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define vi vector<int>
#define fi first
#define se second
#define ll long long
#define oo 1000000007
#define maxN 10005

using namespace std;

int a[maxN];

int main(){
    int n, ans = oo;
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    int _max = *max_element(a+1, a+n+1);
    int _min = *min_element(a+1, a+n+1);
    fto(i, 1, n){
        int k = -1;
        if (a[i] == _min) k = _max;
        else if (a[i] == _max) k = _min;
        
        fto(j, 1, n){
            if (a[j] == k) ans = min(ans, abs(j-i)+1);
        }
    }
    cout << ans;
    return 0;
}
