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

const int N=55;
bool st[N];
ll dp[N][3];
ll pw[N];

int main(){
	string s;cin>>s;
	FOR(i,0,sz(s))st[i]=(s[i]=='1');
	int n=sz(s)-1;
	dp[n][st[n]]=0;
	dp[n][!st[n]]=1;
	pw[0]=1;
	FOR(i,1,N)pw[i]=2*pw[i-1];
	iFR(i,n){
		dp[i][st[i]]=dp[i+1][0];
		dp[i][!st[i]]=dp[i+1][1]+pw[n-i];
	}
	cout<<dp[0][0]<<endl;

	return 0;
}