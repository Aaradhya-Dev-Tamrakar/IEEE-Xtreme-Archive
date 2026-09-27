#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
int head[MAXN],vis[MAXN],col[MAXN],ans,m,n,k,fl;
struct node{
	int u,v,w;
	friend bool operator <(node x,node y)
	{
		return x.w<y.w;
	}
}a[MAXN*5];
struct edge{
	int v,nxt,w;
}e[MAXN*5];
void dfs(int u)
{
	for(int i=head[u];i;i=e[i].nxt)
	{
		if(e[i].w>=ans) continue;
		int v=e[i].v;
		if(col[v]==-1) col[v]=col[u]^1,dfs(v);
		else if(col[v]!=(col[u]^1)) fl=1;
	}
}
bool check(int x)
{
	for(int i=1;i<=n;i++) head[i]=vis[i]=0,col[i]=-1;
	k=fl=0;
	for(int i=1;i<=x;i++)
	{
		e[++k]={a[i].v,head[a[i].u],a[i].w},head[a[i].u]=k;
		e[++k]={a[i].u,head[a[i].v],a[i].w},head[a[i].v]=k;
	}
	for(int i=1;i<=n;i++) 
	{
		if(col[i]==-1)
		{
			col[i]=0;
			dfs(i);
		}
	}
	return fl;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		e[++k]={a[i].v,head[a[i].u],a[i].w},head[a[i].u]=k;
		e[++k]={a[i].u,head[a[i].v],a[i].w},head[a[i].v]=k;
	}
	sort(a+1,a+m+1);
	ans=1e9;
	for(int u=1;u<=n;u++)
	{
		int mn1=1e9,mn2=1e9;
		for(int i=head[u];i;i=e[i].nxt)
		{
			if(e[i].w<mn1) mn2=mn1,mn1=e[i].w;
			else if(e[i].w<mn2) mn2=e[i].w;
		}
		ans=min(ans,mn1+mn2);
	}
	int l=1,r=m,mid,pos=0;
	while(l<=r) 
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,pos=mid;
		else l=mid+1;
	}
	if(pos) ans=min(ans,a[pos].w);
	if(ans>=1e9) ans=-1;
	cout<<ans;
}