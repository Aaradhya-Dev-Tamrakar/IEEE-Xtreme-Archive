#include <bits/stdc++.h>
using namespace std;

int n;

int a[100005],b[100005];

long long solve (int x) {
    long long ret = 0;
    for (int i=0; i<n; i++) {
        if ( x < a[i] ) ret += a[i]-x;
        else if ( x > b[i] ) ret += x-b[i];
    }
    return ret;
}

int main() {

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }

    int s = -(1e9) , e = (1e9) , trd;

    while (s+2<e) {
        trd = (e-s)/3;
        if ( solve( s+trd ) < solve( e-trd ) ) e-=trd;
        else s+=trd;

    }

    long long ans = solve(s);
    for (int i=s; i<=e; i++) ans = min( ans , solve(i) );

    cout << ans << endl;
}
