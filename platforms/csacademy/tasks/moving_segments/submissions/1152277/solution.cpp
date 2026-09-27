#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;
const ll oo = 1e18;
const int N = 100005;

int n;
int x[N], y[N];

ll f(int e){
    ll ans = 0;
    forn(i, n){
        if(x[i] <= e && e <= y[i]) continue;
        ans += min(abs(x[i] - e), abs(y[i] - e));
    }
    return ans;
}

int main(){
    scanf("%d", &n);
    
    forn(i, n) scanf("%d %d", x+i, y+i);
    
    int L = -MOD, R = MOD;
    
    while(R - L > 20){
        int t = (R - L)/3;
        int m1 = L + t;
        int m2 = R - t;
        if(f(m1) < f(m2)) R = m2;
        else L = m1;
    }
    
    ll ans = 1e18;
    fore(i, L, R)
        ans = min(ans, f(i));

    
    printf("%lld\n", ans);

    
    
    return 0;
}