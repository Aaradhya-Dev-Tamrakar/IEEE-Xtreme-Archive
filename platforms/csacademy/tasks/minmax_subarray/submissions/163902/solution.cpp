#include<bits/stdc++.h>
#include<sstream>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
#define mod 1000000007
#define all(v) v.begin(),v.end()
#define loop(i,a,b) for(i=(ll)a;i<(ll)b;i++)
#define revloop(i,a,b) for(i=(ll)a;i>=(ll)b;i--)
#define stloop(it,v) for(it=v.begin();it!=v.end();++it)
#define ii pair<ll,ll>
#define MP make_pair
#define pb push_back
#define f first
#define s second
#define ll long long int
#define PI acos(-1.0)
#define rs resize
int main()
{  std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n,i,j,mi=mod,ma=-mod,ans=mod;
   cin>>n;
   int a[n];
   vector<int> v1,v2;
   loop(i,0,n){
    cin>>a[i];
    mi=min(mi,a[i]);
    ma=max(ma,a[i]);
   }
   loop(i,0,n)
   {
    if(a[i]==mi)
     v1.pb(i);
    if(a[i]==ma)
     v2.pb(i);
   }
   loop(i,0,v1.size())
   {
    j=upper_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
    ans=min(ans,abs(v2[j]-v1[i])+1);
    if(j!=0)
      ans=min(ans,abs(v2[j-1]-v1[i])+1);
   }
   cout<<ans;
   return 0;
}
