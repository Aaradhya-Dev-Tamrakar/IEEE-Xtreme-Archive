#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
#define MOD 1000000007
#define rint register int
inline int rf(){int r;int s=0,c;for(;!isdigit(c=getchar());s=c);for(r=c^48;isdigit(c=getchar());(r*=10)+=c^48);return s^45?r:-r;}
int n, a[MAXN+5], s[MAXN+5], fac[MAXN+5], efac[MAXN+5], f[MAXN+5]; map<int,int> S; inline int fxp(int s, int n=MOD-2){int a=1;for(;n;n&1?a=1ll*a*s%MOD:0,s=1ll*s*s%MOD,n>>=1);return a;}
inline int C(int n, int k){return 1ll*fac[n]*efac[k]%MOD*efac[n-k]%MOD;} inline int F(int a){return a>1?1ll*fac[a]*fac[a-1]%MOD*fxp(2,~-MOD-~-a)%MOD:1;}
int main()
{
	n = rf(); for(rint i = fac[0] = 1; i <= n; fac[i] = 1ll*i*fac[i-1]%MOD, i++); efac[n] = fxp(fac[n]); for(rint i = n; i; efac[i-1] = 1ll*i*efac[i]%MOD, i--);
	for(rint i = 1; i <= n; ++S[rf()], i++); n = 0; for(auto v:S) a[++n] = v.second; partial_sum(a+1,a+n+1,s+1); f[1] = F(a[1]);
	for(rint i = 2, j; i <= n; f[i] = 1ll*f[i]*f[i-1]%MOD*F(a[i])%MOD, i++) for(j = 0; j < a[i]; f[i] = (f[i]+1ll*(a[i]-j)*C(s[i-1]+j-1,j))%MOD, j++); return !printf("%d\n",f[n]);
}