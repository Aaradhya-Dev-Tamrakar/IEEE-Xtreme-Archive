#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],c,b,uoc,i;
int main() 
{
    cin>>n>>m>>a[1];
    uoc=a[1];
    for(i=2;i<=n;++i)
    {
        cin>>a[i];
        uoc=__gcd(uoc,a[i]);
    }
    for(i=1;i<=m;++i)
    {
        cin>>b>>c;
        a[b]/=c;
        uoc= __gcd(uoc,a[b]);
        cout<<uoc<<"\n";
    }
    return 0;
}