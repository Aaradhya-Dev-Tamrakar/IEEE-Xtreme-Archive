#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int A, B, T;

ll Ans(int x)
{
    int nr = 0;
    ll sol = 0;

    while(x >= 1) {
        nr = x / 2 + x % 2;
        sol += (ll)nr * nr;
        x >>= 1;
    }

    return sol;
}

int main()
{
    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> A >> B;
        cout << Ans(B) - Ans(A - 1) << '\n';
    }

    return 0;
}
