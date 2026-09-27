#include <bits/stdc++.h>
#define forn(i,n) for(int i = 0; i < (n); i++)
#define vec vector
using namespace std;

using ll  = long long; 
using pii = pair<int,int>;

int main() {
    int n,m; cin >> n >> m; 
    vec<int> as = vec<int>(n);
    int g = 0; 
    forn(i,n){ cin >> as[i]; g = __gcd(g,as[i]); }
    //cerr << g << endl; 
    forn(q,m){
        int i, dv; 
        cin >> i; i--;
        cin >> dv; 
        //cerr << idx << "idx"<< as[i] << " d" << dv << endl; 
        as[i] = as[i] / dv; 
        //cerr << idx << "idx"<< as[i] << " d" << dv << endl; 
        g = __gcd(g,as[i]);
        cout << g << endl; 
    }
}