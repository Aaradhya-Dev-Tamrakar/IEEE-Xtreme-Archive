#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        a-=1;
        ll ans = 0;
        for (int i=29;i>=0;i--) {
            ll na = a>>i;
            ll nb = b>>i;
            ans+=(nb+1)/2*((nb+1)/2)-(na+1)/2*((na+1)/2);
        }
        printf("%lld\n",ans);
    }
}