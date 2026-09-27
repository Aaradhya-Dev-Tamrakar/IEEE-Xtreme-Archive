
#include<bits/stdc++.h>
using namespace std;
#define D(x)        cout<<#x " = "<<(x)<<endl
#define un(x)       x.erase(unique(x.begin(),x.end()), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pb          push_back
#define mp          make_pair
#define xx          first
#define yy          second
#define hp          (LL) 999983
#define MAX         50
typedef long long int LL;

int n;
char bs[MAX+11];

LL go(LL st, LL ed, int pos, bool isLeft = true)
{
    if(pos < 0) return 0;

    LL mid = (st+ed)/2;

    if(isLeft)
    {
        if(bs[pos] == '0') return go(st, mid, pos-1, true);
        else return (mid - st + 1) + go(mid+1, ed, pos-1, false);
    }
    else
    {
        if(bs[pos] == '1') return go(st, mid, pos-1, true);
        else return (mid - st + 1) + go(mid+1, ed, pos-1, false);
    }
}

int main()
{
    //freopen("c:\\Users\\User\\Desktop\\in.txt", "r", stdin);
    //freopen("c:\\Users\\User\\Desktop\\out.txt", "w", stdout);

    int i, j, k;

    scanf("%s", bs);
    n = strlen(bs);
    reverse(bs, bs + n);

    cout << go(0, (1LL<<n)-1, n-1) << endl;

    return 0;
}




