
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int a[5004];

int main()
{
	ios_base::sync_with_stdio(false);
	
	int n; cin>>n;
	
	int mx = -21 , mn = 1e9 + 54;
	for (int i=0 ; i<n ; i++)
	{
		cin>>a[i];
		mx = max( mx , a[i] );
		mn = min( mn , a[i] );
	}
	
	int ans = 1e9;
	
	int l = -2e9;
	for (int i=0 ; i<n ; i++)
	{
		if ( a[i] == mn ) l = i;
		if ( a[i] == mx ) ans = min( ans , i - l + 1 );
	}
	
	l = 2e9;
	for (int i=n-1 ; i>=0 ; i--)
	{
		if ( a[i] == mn ) l = i;
		if ( a[i] == mx ) ans = min( ans , l - i + 1 );
	}
	
	cout<<ans<<"\n";
	
	return 0;
}