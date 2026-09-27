#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define pld pair<ld,ld>
typedef long long ll;
typedef long double ld;
typedef int praise_long_long;
namespace io {
    using namespace std;
    inline ll read() {
        ll f=1,ans=0;
        char x=getchar();
        while(x<'0'||x>'9') {
        	if(x=='-') {
            	f=-1;
			}
            x=getchar();
        }
        while(x>='0'&&x<='9') {
            ans=ans*10+x-'0';
            x=getchar();
        }
        return ans*f;
    }
    inline void print(ll x) {
        if(!x) {
            putchar('0');
            return ;
        }
        if(x<0) {
			putchar('-');
			x=-x;
		}
        ll cnt=0;
        char a[45];
        while(x) {
            a[cnt++]=x%10+'0';
            x/=10;
        }
        while(cnt--) {
            putchar(a[cnt]);
        }
    }
}
using namespace io;
const ll inf=2e18;
const ll mod=1e9+7;
const ll N=2e5+5;
struct node {
	ll vl,wl;
};
ll n,m,w,cnt=inf,dis[N];
vector<node> g[N];
vector<ll> v[N];
bool dfs(ll x) {
	for(auto it : v[x]) {
		if(dis[it]==-1) {
			dis[it]=dis[x]^1;
			if(!dfs(it)) {
				return false;
			}
		}
		else {
			if(dis[it]==dis[x]) {
				return false;
			}
		}
	}
	return true;
}
bool ck(ll x) {
	memset(dis,-1,sizeof(dis));
	for(ll i=1;i<=n;i++) {
		v[i].clear();
	}
	for(ll i=1;i<=n;i++) {
		for(auto it : g[i]) {
			if(it.wl<x) {
				v[i].push_back(it.vl);
			}
		}
	}
	for(ll i=1;i<=n;i++) {
		if(dis[i]==-1) {
			dis[i]=0;
			if(!dfs(i)) {
				return false;
			}
		}
	}
	return true;
}
inline void solve() {
	n=read();
	m=read();
	for(ll i=1;i<=m;i++) {
		ll ul,vl,wl;
		ul=read(),vl=read(),wl=read();
		g[ul].push_back({vl,wl});
		g[vl].push_back({ul,wl});
	}
	for(ll i=1;i<=n;i++) {
		ll k=inf,cntt=1,fl=inf;
		for(auto it : g[i]) {
			k=min(k,it.wl);
		}
		for(auto it : g[i]) {
			if(k==it.wl) {
				cntt--;
				if(cntt==0) {
					continue;
				}
			}
			fl=min(fl,it.wl);
		}
		cnt=min(cnt,k+fl);
	}
	if(cnt==inf) {
		cnt=0;
	}
	ll l=1,r=cnt,ans=-1;
	while(l<=r) {
		ll mid=(l+r)/2;
		if(ck(mid)) {
			ans=mid;
			l=mid+1;
		}
		else {
			r=mid-1;
		}
	}
	print(ans);
}
praise_long_long main() {
//	freopen("tour.in","r",stdin);
//	freopen("tour.out","w",stdout);
    ll T=1;
//	cin>>T;
    while(T--) {
        solve();
    }
    return 0;
}