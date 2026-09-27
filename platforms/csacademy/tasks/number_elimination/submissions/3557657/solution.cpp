#include <bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e6+5,mod=1e9+7;
inline int quick_pow(int a,int b){
	int ret=1;for(;b;b>>=1,a=1ll*a*a%mod)if(b&1)ret=1ll*ret*a%mod;
	return ret;
}
inline int Inv(int a){return quick_pow(a,mod-2);}
int fac[N],invfac[N],f[N];
inline int C(int n,int m){
	if(n<0||m<0||m>n)return 0;
	return 1ll*fac[n]*invfac[n-m]%mod*invfac[m]%mod;
}
inline void init(int n){
	fac[0]=1;for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=Inv(fac[n]);
	for(int i=n-1;i>=0;--i)invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	f[0]=f[1]=1;
	for(int i=2;i<=n;++i)
		f[i]=1ll*f[i-1]*(((1ll*i*(i-1))>>1)%mod)%mod;
}
int n,a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	sort(a+1,a+1+n);
	init(n);
	int ans=1;
	for(int i=1,r;i<=n;i=r+1){
		r=i;
		while(r<n&&a[r+1]==a[i])++r;
		int len=r-i+1,cur=1;
		if(i>1){
			cur=0;
			for(int j=0;j<len;++j)
				cur=(cur+1ll*C(i-2+j,j)*(len-j))%mod;
		}
		ans=1ll*ans*cur%mod*f[len]%mod;
	}
	printf("%d\n",ans);
	return 0;
}