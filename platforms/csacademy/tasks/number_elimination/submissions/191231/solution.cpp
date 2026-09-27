#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int maxn = 100000 + 10;

const int mod = 1000000007;

int fak[ maxn ];
int inv[ maxn ];
int fun[ maxn ];
int ans[ maxn ];

int comb(int n, int k){
    return 1LL * fak[ n ] * inv[ k ] % mod * inv[ n - k ] % mod;
}

int modpow(int a, int n){
    int b = 1;
    while (n){
        if (n & 1)
            b = 1LL * a * b % mod;
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return b;
}

void add(int &a, int b){
    a += b;
    if (a >= mod)
        a -= mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    
    fak[0] = inv[0] = 1;
    
    for (int i = 1; i <= n; ++i){
        fak[i] = 1LL * fak[i - 1] * i % mod;
        inv[i] = modpow( fak[i], mod - 2 );
    }
    
    int t2 = 1;
    fun[1] = 1;
    
    for (int i = 2; i <= n; ++i){
        t2 = 1LL * t2 * inv[ 2 ] % mod;
        fun[i] = 1LL * fak[i] * fak[i - 1] % mod * t2 % mod;
    }
    
    // for (int i = 1; i <= n; ++i)
    //     cout << i << " " << fak[i] << " " << inv[i] << " " << fun[i] << endl;
    
    map<int,int> seq;
    
    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        seq[v]++;
    }
    
    vector<int> vec;
    
    for (auto p : seq)
        vec.push_back( p.second );
        
    int s = vec.size(), sum = vec[0];
    
    // for (auto vv : vec)
    //     cout << vv << " ";
    // cout << endl;
    
    ans[1] = fun[ vec[0] ];
    
    for (int i = 2; i <= s; ++i){
        int sz = vec[i - 1];
        
        for (int x = 0; x < sz; ++x){
            add( ans[i], 
                1LL * ans[i - 1] * fun[ sz ] % mod 
                * comb( sum + x - 1, x ) % mod
                * (sz - x) % mod
                );
                
            // cout << "here: " << x << " " << ans[i - 1] << " " << fun[ sz ] << " " << comb(sum + x - 1, x) << " " << sz - x << endl;
        }
        
        // cout << i << " " << ans[i] << " " << sum << endl;
        sum += sz;
    }
    
    cout << ans[ s ] << endl;
    
    return 0;
}