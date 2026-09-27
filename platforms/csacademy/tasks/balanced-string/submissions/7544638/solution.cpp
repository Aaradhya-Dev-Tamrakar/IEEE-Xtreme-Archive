#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define mkp make_pair
#define debug(x) cout << #x << " = " << x << "\n";
#define rep(i, l, r) for (int i = (l); i <= (r); ++i)
#define per(i, r, l) for (int i = (r); i >= (l); --i)
#define ull unsigned long long
#define vall(v) (v.begin(), v.end())
#define vsz(v) (int)v.size()
#define ll long long

bool MemoryST;

const int N=1e5+10;

string s; int a[N],b[N]; 

bool sol(int n) {
	rep(i,1,n) a[i+n]=a[i];
	int s0=0,s1=0;
	rep(i,1,n) if(a[i]) ++s1; else ++s0;
	if(s0<=1||s1<=1) return 1;
	if(s1<s0) {
		rep(i,1,n) if(a[i]) {
			rep(p,1,n) a[p]=a[i+p-1]; break ;
		}
	} else {
		rep(i,1,n) if(!a[i]) {
			rep(p,1,n) a[p]=!a[i+p-1]; break ;
		}
	}
	rep(i,1,n-1) if(a[i]&&a[i+1]) return 0;
	int ls=1,c=0;
	a[n+1]=1;
	rep(i,2,n+1) if(a[i]) b[++c]=i-ls-1,ls=i; 
	int Mn=b[1],Mx=b[1];
	rep(i,1,c) Mn=min(Mn,b[i]),Mx=max(Mx,b[i]);
	if(Mx-Mn>=2) return 0;
	rep(i,1,c) a[i]=b[i]-Mn;
	return sol(c);
}

void Mainsolve() {
	cin>>s;
	int n=s.size(); s=" "+s;
	rep(i,1,n) a[i]=s[i]-'A';
	cout<<sol(n)<<"\n";
}

bool MemoryED;
int main() {
//	freopen ("ts.in", "r", stdin);
//	freopen (".out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cerr << fixed << setprecision(6) << (&MemoryST - &MemoryED) / 1024.0 / 1024.0 << "MB\n";

	int T = 1; cin >> T;
	while (T--) Mainsolve();

	cerr << endl << 1e3 * clock() / CLOCKS_PER_SEC << "ms\n";

//	system("fc .out .out");
	return 0;
}