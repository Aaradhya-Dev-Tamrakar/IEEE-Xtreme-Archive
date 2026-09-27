#include <bits/stdc++.h>
#define FOREACH(it,c) for( __typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define FOR(a,b,c) for(int a=(b);a<=(c);++a)
#define ROF(a,b,c) for(int a=(b);a>=(c);--a)
#define dbg(x) cout<<#x<<" = "<<(x)<<"\n";
#define pii pair<int,int>
#define pll pair< ll, ll >
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ll long long
#define TATA NULL
using namespace std;
const int NMAX = 100004;
int a[NMAX], minn[NMAX];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("data.in","r",stdin);
        freopen("data.out","w",stdout);
    #endif // ONLINE_JUDGE
    cin.sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int sol = 0;
    FOR(i,1,n)
        cin >> a[i];
    minn[n+1] = 1e9;
    ROF(i,n,1)
        minn[i] = min(minn[i+1],a[i]);
    int maxx = -1;
    FOR(i,1,n)
    {
        maxx = max(maxx,a[i]);
        if(maxx <= minn[i+1])
        {
            maxx = 0;
            ++sol;
        }
    }
    cout<<sol<<"\n";
    return 0;
}
