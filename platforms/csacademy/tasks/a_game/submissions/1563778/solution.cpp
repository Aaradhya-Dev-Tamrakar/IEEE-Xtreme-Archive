#include <bits/stdc++.h>
#define INF (1e9)+5
#define eps 1e-6

using namespace std;

typedef long long ll;

int n, ok, a;
string s;

int main()
{
    cin>>n;
    cin>>s;
    int nr=0, xs=0;
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]=='B')
            nr++;
        else
        {
            a++;
            if (nr)
            {
                xs ^= nr;
                nr=0;
                ok=1;
            }
        }
    }
    if (nr)
    {
        xs ^= nr;
        nr=0;
        ok=1;
    }
    if (a%2==0)
    {
        cout<<-1;
        return 0;
    }
    if (!ok)
    {
        if (n%2==0)
            cout<<-1;
        else
            cout<<'B';
    }
    else
        if (xs)
            cout<<'A';
        else
            cout<<'B';
    return 0;
}
