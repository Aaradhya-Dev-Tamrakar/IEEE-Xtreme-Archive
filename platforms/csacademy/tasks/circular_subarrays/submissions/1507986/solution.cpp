//Dile a la jardinera que traigo flores
#include <bits/stdc++.h>

#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define trace(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = int(a); i < int(b); i++)
#define iFR(i,a) for(int i = int(a-1); i >= int(0); i--)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;



int main(){
	int n,k;cin>>n>>k;
	int num=__gcd(n,k);
	vector<int>v[num+5];
	FOR(i,0,n){
		int k;cin>>k;
		v[i%num].pb(k);
	}
	ll c=0;
	FOR(i,0,num){
		int ma=INT_MIN,mi=INT_MAX;ll res=0;
		sort(v[i].begin(),v[i].end());
		FOR(j,0,sz(v[i]))res+=ll(abs(v[i][sz(v[i])/2]-v[i][j]));
		c+=res;
	}
	cout<<c<<endl;

	return 0;
}