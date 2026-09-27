#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define ld long double
#define ll long long
#define int long long

using namespace std;

const int MAXN = 1001 * 1001  ;

vector < int > v ;

int32_t main()
{
    ios::sync_with_stdio(0);

    string s;
    int n , k = 0 , x = 0 , y = 0  ;
    cin >> n >> s ;
    for(int i = 0 ; i < n ; i ++ )
    {
        if(s[i]=='A')
        {
            x ++ ;
            continue ;
        }
        int j = i ;
        while(j<n&&s[j]=='B')
            j ++ ;
        k ^= j - i ;
        i = j - 1 ;

    }
    x %=  2;
    y %= 2 ;
    if(!x)
        return cout<<-1,0 ;
    if(!k)
        return cout<<"B",0;
    cout<<"A";


}
