#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n , m ;
    cin>>n>>m ;
    int a[n] ;
    for(int i =0 ; i < n ; i ++ )
    {
        cin>> a[i] ;
    }
    int gcd = a[0] ;
    for(int i =0 ;i < n;i ++)
    {
        gcd = __gcd( gcd , a[i ] );
    }
    for(int i =0 ; i < m ; i ++)
    {
        int index , val ;
        cin>> index >> val ;
        index -- ;
        a[ index ] /=  val ;
        if( a[ index ] % gcd != 0 )
        {
            gcd = __gcd( a[index ] , gcd ) ;
        }
        cout<< gcd<<"\n" ;
    }
}