#include <bits/stdc++.h>
#define nmax 100000

using namespace std;
int calc(int x,int n)
{
    if(n==1)
    {
        return 1;
    }
    if(x%2==0)
    {
        return calc(x/2,n/2);
    }
    return n/2+calc(x/2+1,(n+1)/2);
}
int main()
{
    int n,m,x,ant,act,i;
    cin>>n>>m;
    cin>>x;
    ant=calc(x,n);
    for(i=2;i<=m;i++)
    {
        cin>>x;
        act=calc(x,n);
        if(ant+1!=act)
        {
            cout<<0<<'\n';
            return 0;
        }
        ant++;
    }
    cout<<1<<'\n';
    return 0;
}
