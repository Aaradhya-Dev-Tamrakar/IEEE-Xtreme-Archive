#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	int n, q;
	cin>>n>>q;
	int a[n];
	int g;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i==0) {g=a[0];}
		else {
			g = __gcd(g, a[i]);
		}
	} 
	while(q--) {
		int u, val;
		cin>>u>>val;
		u--;
		a[u]/=val;
		g = __gcd(a[u], g);
		cout<<g<<"\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t = 1;
	// cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
