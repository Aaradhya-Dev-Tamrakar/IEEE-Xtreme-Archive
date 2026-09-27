#include <bits/stdc++.h>
using namespace std;
int n,T,a[100010],b[100010],c[100010];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		int m=0;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		int p=-1;
		for (int i=1;i<=n;i++)
			if (p!=a[i])
			{
				p=a[i];
				b[++m]=a[i];
				c[m]=1;
			} else c[m]++;
			
		if (m==1)
		{
			if (b[1]==1)
				printf("%d\n",c[m]+1);
			else
			{
				c[1]--;
				if (c[1]%b[1]==0)
					printf("%d\n",c[1]+1);
				else printf("%d\n",(c[1]/b[1]+1)*b[1]+1);
			}
			continue;
		}
		bool f=true;
		long long ans=0;
		for (int i=1;i<=m;i++)
			if (c[i]%b[i]!=0)
			{
 				f=false;
				break;
			}
 		if (f) {
			for (int i=1;i<=m;i++)
				ans+=c[i];
			printf("%lld\n",ans+1);
			continue;
		}
		for (int i=m;i>=1;i--)
			if (c[i]%b[i]==1)
			{
				c[i]--;
				f=true;
				break;
			}
		if (f)
		{
			for (int i=1;i<=m;i++)
				if (c[i]%b[i]!=0)
				{
					f=false;
					break;
				}
			if (f) ans++;
			for (int i=1;i<=m;i++)
			{
				int t=c[i]/b[i];
				if (c[i]%b[i]!=0) t++;
				ans+=t*b[i];
			}
			printf("%lld\n",ans);
			continue;
		}
		int j;
		for (int i=m;i>=1;i--)
			if (c[i]%b[i]!=0)
			{
				j=i;
				f=false;
				break;
			}
		for (int i=1;i<=m;i++)
			if (i!=j&&c[i]%b[i]!=0)
			{
				f=true;
				break;
			}
		if (!f)
		{
			for (int i=1;i<=m;i++)
			{
				int t=c[i]/b[i];
				if (c[i]%b[i]!=0) t++;
				ans+=t*b[i];
			}
			ans++;
			long  long ans1=0;
			c[j]++;
			c[1]--;
			for (int i=1;i<=m;i++)
			{
				int t=c[i]/b[i];
				if (c[i]%b[i]!=0) t++;
				ans1+=t*b[i];
			}
			printf("%lld\n",min(ans,ans1));	
			continue;
		}
		for (int i=1;i<=m;i++)
			{
				int t=c[i]/b[i];
				if (c[i]%b[i]!=0) t++;
				ans+=t*b[i];
			}
		printf("%lld\n",ans);
	}
}