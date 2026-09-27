#include <bits/stdc++.h>
#define Nmax 100002
#define ll long long
using namespace std;

int t, n, v[Nmax], tp, td, pp, pd, i, nr, mn;
ll rez;

int main()
{
    cin>>t;
    while (t--){
        cin>>n;
        mn = 1e9;
        for (int i=1;i<=n;i++)
            cin>>v[i],mn = min(mn,v[i]);
        sort(v+1,v+n+1);
        rez = 0;
        i = n;
        td = pp = pd = 0;
        while (i>0){
            nr = 1;
            while (v[i-1]==v[i]) nr++,i--;
            rez += 1LL * nr / v[i] * v[i];
            nr %= v[i];
            if (nr!=0)
                rez += v[i];
            if (nr==1 && !td) td = v[i];
            else if (v[i]==1 && !td) td = 1;
            else if (nr!=0 && !pp) pp = v[i];
            else if (nr!=0 && !pd) pd = v[i];
            i--;
        }

        if (td && pp) rez-=td;
        else if (!pp && td>1 && mn==1) rez--;
        else if (!pp && !pd && td<=1) rez++;
        cout<<rez<<'\n';
    }

    return 0;
}

