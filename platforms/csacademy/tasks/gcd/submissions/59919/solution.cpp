#include <bits/stdc++.h>

#define endl '\n'
#define Int long long
#define Double long double
#define SZ(a) (int) a.size()
#define ALL(a) a.begin(), a.end()
#define CLR(a, b) memset(a, b, sizeof a)
#define debug(x) cerr << #x << " " << x << '\n';
#define MOD 1e9+7
#define MAXN 1001

using namespace std;

Int gcd(Int a, Int b) {
    if(a < b)   swap(a, b);
    if(b == 0)  return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    Int a, b;
    cin >> a >> b;
    cout << gcd(b, a) << endl;
    return 0;
}