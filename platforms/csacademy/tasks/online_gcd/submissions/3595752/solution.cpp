#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define all(x)  x.begin(),x.end()
#define FAST ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
using namespace std;
const int N = 1e6 + 9;
const ll mod = int(1e9) + 9;
void solve(){
    int n , q; cin >> n >>  q;
    int a[n];
    for(auto &i:a) cin >> i;
    int GCD = a[0];
    for(auto &i:a) GCD = __gcd(i,GCD);
    int pos , x;
    while (q--){
        cin >> pos >> x;
        pos--;
        a[pos] /= x;
        GCD = __gcd(GCD, a[pos]);
        cout << GCD << endl;
        cout.flush();
    }
}
int main(){
    FAST
    int t = 1;
    //cin >> t;
    while (t--){
        solve();
    }
}