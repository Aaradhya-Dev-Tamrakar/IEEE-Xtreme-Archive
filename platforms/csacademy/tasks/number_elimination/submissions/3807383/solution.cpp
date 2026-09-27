#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int Pow(int n,int x,int r=1) { for(;x;n=1ll*n*n%mod,x>>=1) if(x&1) r=1ll*r*n%mod; return r; }
int n,fac[100005],finv[100005],a[100005];
int bin(int n,int m) { return 1ll*fac[n]*finv[m]%mod*finv[n-m]%mod; }
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i); sort(a+1,a+1+n);
	for(int i=fac[0]=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%mod;
	finv[n]=Pow(fac[n],mod-2); for(int i=n;i;i--) finv[i-1]=1ll*finv[i]*i%mod;
	int ans=1;
	for(int l=1,r;l<=n;l=r+1) {
		for(r=l;r<n&&a[l]==a[r+1];) r++;
		ans=1ll*ans*Pow(mod+1>>1,r-l,1ll*fac[r-l+1]%mod*fac[r-l]%mod)%mod;
		int sm=0;
		if(l==1) sm=1;
		else for(int i=1;i<=r-l+1;i++) sm=(sm+1ll*i*bin(r-i-1,l-2))%mod;
		ans=1ll*ans*sm%mod;
	} printf("%d\n",ans);
}