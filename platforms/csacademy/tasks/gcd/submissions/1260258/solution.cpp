#include <bits/stdc++.h>
using namespace std;
#define i64 long long
i64 gcd(i64 a,i64 b)
{
    return (b==0)?a:gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    i64 a,b;
    cin >>a>>b;
    cout <<(gcd(a,b))<<endl;
    return 0;
}
