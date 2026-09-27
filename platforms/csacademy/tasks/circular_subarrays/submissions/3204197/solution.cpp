#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k, g, res;
vector <vector <int>> v;
vector <int> ps;
int FindAndCalc(vector <int> &x){
    int s = x.size() - 1, r = 1LL << 40, val;
    sort(x.begin() + 1, x.end());
    for(int i=1;i<=s;i++) ps[i] = ps[i-1] + x[i];
    for(int i=1;i<=s;i++) val = x[i] * ((i << 1) - s) + ps[s] - (ps[i] << 1), r = min(r, val);
    return r;
}
void setup(){
    cin>>n>>k, g = __gcd(n, k);
    v.assign(g, vector <int> (1));
    vector <int> vec(n + 1);
    ps.assign(n / g + 1, 0);
    for(int i=1;i<=n;i++) cin>>vec[i];
    for(int i=0;i<g;i++) for(int j=i+1;j<=n;j+=g) v[i].emplace_back(vec[j]);
    vec.clear();
}
void solve(){
    for(int i=0;i<g;i++) res += FindAndCalc(v[i]);
    cout<<res;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef DEBUG
    freopen("Input.txt", "r", stdin);
#endif
    setup();
    int tc = 1;
    // cin>>tc;
    while(tc--) solve();
}