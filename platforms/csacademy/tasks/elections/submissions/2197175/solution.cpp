#include <bits/stdc++.h>
#define MAXN 500007
using namespace std;
string s;
int val[MAXN],t[2*MAXN],a[MAXN],ans[MAXN],seg[4*MAXN],bag[4*MAXN],n,bit[4*MAXN];
vector<pair<int,int> > u[MAXN];
vector<int> g[MAXN];
void updbit(int x,int val) {while(x<=n) {bit[x]+=val; x+=x&-x;} }
int calc(int x)
{
	int sol=0;
	while(x>0) {sol+=bit[x]; x-=x&-x;}
	return sol;
}
void relax(int ind)
{
	bag[2*ind]+=bag[ind];
	bag[2*ind+1]+=bag[ind];
	bag[ind]=0;
	seg[ind]=min(seg[2*ind]-bag[2*ind],seg[2*ind+1]-bag[2*ind+1]);
}
int nmin(int l,int r,int lt,int rt,int ind)
{
	if(l>rt || r<lt) return 1000000000;
	if(l>=lt && r<=rt) return seg[ind]-bag[ind];
	int s=(l+r)/2;
	relax(ind);
	return min(nmin(l,s,lt,rt,2*ind),nmin(s+1,r,lt,rt,2*ind+1));
}
void upd(int l,int r,int lt,int rt,int ind,int val)
{
	if(l>rt || r<lt) return;
	if(l>=lt && r<=rt) {bag[ind]+=val; return;}
	int s=(l+r)/2;
	upd(l,s,lt,rt,2*ind,val);
	upd(s+1,r,lt,rt,2*ind+1,val);
	relax(ind);
}
void napravi(int l,int r,int ind)
{
	if(l==r) {seg[ind]=val[l]; return;}
	int s=(l+r)/2;
	napravi(l,s,2*ind);
	napravi(s+1,r,2*ind+1);
	seg[ind]=min(seg[2*ind+1],seg[2*ind+1]);
}
void dfs(int s)
{
	if(s!=1) {upd(1,n+1,1,s-1,1,a[s-1]); updbit(s-1,1);}
	for(int i=0;i<g[s].size();i++) dfs(g[s][i]);
	for(int i=0;i<u[s].size();i++)
	{
		int r=u[s][i].first;
		ans[u[s][i].second]=max(0,nmin(1,n+1,r+1,r+1,1)-nmin(1,n+1,s,r,1))+calc(r)-calc(s-1);
	}
	if(s!=1) {upd(1,n+1,1,s-1,1,-a[s-1]); updbit(s-1,-1);}
}
int main()
{
	int q;
	cin>>n>>s>>q;
	for(int i=0;i<q;i++)
	{
		int l,r;
		cin>>l>>r;
		u[l].push_back(make_pair(r,i));
	}
	for(int i=0;i<n;i++) a[i+1]=s[i]=='T'?-1:1;
	int cur=MAXN;
	fill(t,t+2*MAXN,n+2);
	t[MAXN]=n+1;
	val[n+1]=MAXN;
	g[n+2].push_back(n+1);
	for(int i=n;i>0;i--)
	{
		cur+=a[i];
		val[i]=cur;
		g[t[cur+1]].push_back(i);
		t[cur]=i;
	}
	napravi(1,n+1,1);
	dfs(n+2);
	for(int i=0;i<q;i++) printf("%d\n",ans[i]);
}