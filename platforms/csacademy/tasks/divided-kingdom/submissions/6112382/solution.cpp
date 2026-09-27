#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e5+10,inf=1e18,mod=1e9+7;
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
struct edge{
	int u,v,w;
	bool operator < (const edge &X){
		return w<X.w;
	}
} e[maxn<<1];
int n,m,cntt,flag=0,stk[maxn],top,col[maxn],ans=inf,mn[maxn];
vector<int> E[maxn];
bool dfs(int u,int c)
{
	if(col[u]==c) return 1;
	if(col[u]!=-1) return 0;
	col[u]=c;
	for(auto v:E[u]) 
	{
		if(!dfs(v,c^1)) return 0;
	}
	return 1;
}
bool check(int x)
{
	for(int i=1;i<=n;i++) col[i]=-1,E[i].clear();
	for(int i=1;i<=x;i++)
	{
		E[e[i].u].push_back(e[i].v);
		E[e[i].v].push_back(e[i].u);
	}
	for(int i=1;i<=n;i++)
	{
		if(col[i]==-1 and !dfs(i,0)) return 0;
	}
	return 1;
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) mn[i]=inf;
	for(int i=1;i<=m;i++) 
	{
		e[i].u=read(),e[i].v=read(),e[i].w=read();
		ans=min(ans,mn[e[i].u]+e[i].w);
		ans=min(ans,mn[e[i].v]+e[i].w);
		mn[e[i].u]=min(mn[e[i].u],e[i].w);
		mn[e[i].v]=min(mn[e[i].v],e[i].w);
	}	
	sort(e+1,e+m+1);
	int l=0,r=m,pos=-1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(!check(mid)) pos=mid,r=mid-1;
		else l=mid+1;
	}
	if(pos!=-1) ans=min(ans,e[pos].w);
	if(ans==inf) cout<<-1<<'\n';
	else cout<<ans<<"\n";
	return 0;
} 