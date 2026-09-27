#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define rep(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
string s;
void solve()
{
    cin>>s;
    int A=0,B=0;
    for(auto c:s) A+=(c=='A'),B+=(c=='B');
    if(!A||!B) return cout<<"1\n",void();
    int smax=-inf,smin=inf,sum=0;
    for(auto c:s)
    {
        if(c=='A') sum+=B;
        else sum-=A;
        smax=max(smax,sum),smin=min(smin,sum);
    }
    cout<<(smax-smin<s.size())<<"\n";
}
signed main()
{
    int T; cin>>T;
    while(T--) solve();
    return 0;
}