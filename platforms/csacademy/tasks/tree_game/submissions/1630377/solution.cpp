#include<bits/stdc++.h>
#define N 100005
#define M 200005
using namespace std;
int i,j,k,l,s,n,m,last[N],to[M],Next[M],q[N],tot,fa[N],x,y,f[N][3];
inline void add(int x,int y) {
	Next[++tot]=last[x]; last[x]=tot; to[tot]=y;
}
inline void build(int x) {
	int l=0,r=1; q[1]=x;
	while (l<r) {
		int k=q[++l];
		for (int i=last[k];i;i=Next[i]) if (fa[k]!=to[i]) fa[q[++r]=to[i]]=k;
	}
}
int main() {
	scanf("%d",&n);
	for (i=1;i<n;i++) scanf("%d%d",&x,&y),add(x,y),add(y,x);
	build(1);
	for (i=1;i<=n;i++) f[i][1]=-n-1;
	for (i=n;i;i--) {
		s=0;
		int S=0,S1=0,ma=-n-1;
		for (j=last[q[i]];j;j=Next[j]) {
			if (fa[q[i]]==to[j]) continue;
			s+=f[to[j]][0];
			if (max(f[to[j]][1],f[to[j]][2])-f[to[j]][0]>=0) S+=max(f[to[j]][1],f[to[j]][2])-f[to[j]][0],S1++;
			else ma=max(ma,max(f[to[j]][1],f[to[j]][2])-f[to[j]][0]);
		}
		if (S1>=2) f[q[i]][0]=S+s+1;
		else if (S1==1) f[q[i]][0]=max(s,S+s+ma+1);
		else f[q[i]][0]=s;
		for (j=last[q[i]];j;j=Next[j]) {
			if (fa[q[i]]==to[j]) continue;
			f[q[i]][1]=max(f[q[i]][1],max(f[to[j]][2],f[to[j]][1])-f[to[j]][0]+s);
			f[q[i]][2]+=max(f[to[j]][0],f[to[j]][1]+1);
		}
	}
	printf("%d\n",max(max(f[1][0],f[1][1]),f[1][2]));
}