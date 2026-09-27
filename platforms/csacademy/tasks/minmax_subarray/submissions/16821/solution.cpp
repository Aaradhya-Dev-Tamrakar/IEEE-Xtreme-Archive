#include <bits/stdc++.h>

#define PB          push_back
#define PF          push_front
#define MP          make_pair
#define FI          first
#define SE          second

using namespace std;

typedef long long           ll;
typedef unsigned long long  ull;
typedef long double         lf;
typedef pair< int, int >    pii;
typedef vector< int >       vi;
typedef vector< vi >        vvi;

const int MAX = int( 1e6 );
const int MOD = int( 1e9+7 );
const int oo  = INT_MAX;

int main() {
    
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 ); cout.tie( 0 );
    
    int n;
    cin >> n;
    int mn = oo, mx = -1;
    vi a( n );
    for( auto& e : a ) {
        cin >> e;
        mn = min( mn, e );
        mx = max( mx, e );
    }
    int lst_mn, lst_mx, ans = oo;
    lst_mn = lst_mx = -1;
    for( int i = 0; i < n; i++ ) {
        if( a[ i ] == mn ) {
            if( lst_mx != -1 )
                ans = min( ans, i-lst_mx+1 );
            lst_mn = i;
        }
        if( a[ i ] == mx ) {
            if( lst_mn != -1 )
                ans = min( ans, i-lst_mn+1 );
            lst_mx = i;
        }
    }
    cout << ans << "\n";
    
    return 0;
}