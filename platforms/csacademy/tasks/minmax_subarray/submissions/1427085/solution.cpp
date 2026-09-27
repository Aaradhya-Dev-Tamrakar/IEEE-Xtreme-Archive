#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vii vector<vi >
#define pp pair<int,int>
#define pb push_back
#define mp make_pair
#define ppl pair<ll,ll>
#define vl vector<ll>
#define vll vector<vl >
#define vb vector<bool>
#define llu unsigned ll
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define lt 1000000
#define sc scanf
#define pf printf
ll power(ll a,ll b)
{
	if(!b)
		return 1;
	if(b==1)
		return a;
	ll temp=power(a,b/2);
	temp=(temp*temp)%mod;
	if(b&1)
		temp=(temp*a)%mod;
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int i, n , j;
	int mini=1000000007 , maxi =-1 , ans;
	cin >> n;
	vi v(n);
	for( i=0;i<n;i++ )
	    {
	        cin >> v[i];
	        mini=min( mini, v[i]);
	        maxi=max(maxi,v[i]);
	    }
	  if( mini==maxi)
	  {
	      cout << "1";
	      return 0;
	  }
	int s1 , s2;
	s1=s2=0;
	i=j=0;
	ans=n;
	while( i < n)
	{
	    if( j==n )
	        break;
	    if( v[j]==mini)
	        s1++;
	    if( v[j]==maxi)
	        s2++;
	    if( s1 && s2)
	    {
	        ans = min( j-i+1 , ans);
	        while( s1 && s2)
	        {
	            if( v[i]==mini)
	                s1--;
	            if( v[i]==maxi)
	                s2--;
	            i++;
	            if( s1 && s2)
	                ans = min (ans, j-i+1);
	        }
	    }
	    j++;
	}
	cout << ans;
    return 0;
}