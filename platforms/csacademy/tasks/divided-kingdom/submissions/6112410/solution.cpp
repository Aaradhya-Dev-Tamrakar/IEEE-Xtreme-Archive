#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxm=2.5e5+10,inf=0x3f3f3f3f;
int n,m,cnte,ans;
int head[maxn],col[maxn];
bool flag;
struct EDGE{
	int v,nxt,w;
}e[maxm<<1],E[maxm];
void adde(int u,int v,int w)
{
	e[cnte]={v,head[u],w};
	head[u]=cnte++;
}
bool cmp(EDGE x,EDGE y) {return x.w<y.w;}
int read()
{
	int ret=0,w=1;char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {ret=(ret<<3)+(ret<<1)+(ch^48);ch=getchar();}
	return ret*w;
}
void dfs(int u)
{
	for(int i=head[u],to;i!=-1;i=e[i].nxt) if(e[i].w<ans)
	{
		to=e[i].v;
		if(col[to]==-1) {col[to]=col[u]^1;dfs(to);}
		else if((col[to]^1)!=col[u]) flag=1;
	}
}
bool check(int mid)
{
	cnte=flag=0;
	for(int i=1;i<=n;i++) head[i]=col[i]=-1;
	for(int i=1;i<=mid;i++) {adde(E[i].nxt,E[i].v,E[i].w);adde(E[i].v,E[i].nxt,E[i].w);}
	for(int i=1;i<=n;i++) if(col[i]==-1)
	{
		col[i]=0;
		dfs(i);
	}
	return flag;
}
void inpu()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) head[i]=-1;
	for(int i=1,u,v,w;i<=m;i++)
	{
		u=read(),v=read(),w=read();
		E[i]={u,v,w};adde(u,v,w);adde(v,u,w);
	}
}
void deal()
{
	ans=E[0].w=inf;
	for(int u=1;u<=n;u++)
	{
		int mn=inf,cmn=inf;
		for(int i=head[u];i!=-1;i=e[i].nxt)
		{
			if(mn>e[i].w) {cmn=mn;mn=e[i].w;}
			else if(cmn>e[i].w) cmn=e[i].w;
		}
		ans=min(ans,mn+cmn);
	}
	sort(E+1,E+m+1,cmp);
	int l=1,r=m,mid,res=0;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,res=mid;
		else l=mid+1;
	//	cout<<"l="<<l<<" r="<<r<<'\n';
	}
	ans=min(ans,E[res].w);
}
void solve()
{
	inpu();
	deal();
	printf("%d",ans==inf?-1:ans);
}
int main()
{
	int t=1;
	while(t--) solve();
	return 0;
}