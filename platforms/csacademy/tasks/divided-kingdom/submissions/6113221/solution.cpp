#include<bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 myrand(time(0));
inline ll read(){
	ll x=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*w;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	static int sta[35];
	int top=0;
	do{
		sta[top++]=x%10,x/=10;
	}while(x);
	while(top)putchar(sta[--top]+'0');
}
const int N=1e5+5;
const int M=2.5e5+5;
int n,m,ans=1e9;
struct edge{
	int u,v,w;
	bool operator <(const edge &x)const{
		return w<x.w;
	}
}E[M];
vector<int>e[N];
bitset<N>vis;
int color[N];
bool dfs(int u,int c,int val){
	vis[u]=1;
	color[u]=c;
	for(auto v:e[u]){
		if(v>val)continue;
		if(E[v].u==u)v=E[v].v;
		else v=E[v].u;
		if(vis[v]&&color[v]==c)return 0;
		else if(!vis[v]&&!dfs(v,-c,val))return 0;
	}
	return 1;
}
bool check(int x){
	vis.reset();
	memset(color,0,sizeof(color));
	for(int i=1;i<=n;i++){
		if(!vis[i]&&!dfs(i,1,x-1))return 0;
	}
	return 1;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;i++){
		E[i].u=read();
		E[i].v=read();
		E[i].w=read();
	}
	sort(E+1,E+m+1);
	for(int i=1;i<=m;i++){
		e[E[i].u].push_back(i);
		e[E[i].v].push_back(i);
	}
	for(int i=1;i<=n;i++){
		int mn1=1e9,mn2=1e9;
		for(auto j:e[i]){
			if(E[j].w<mn1)mn2=mn1,mn1=E[j].w;
			else if(E[j].w<mn2)mn2=E[j].w;
		}
		ans=min(ans,mn1+mn2);
	}
	E[m+1].w=1e9;
	int l=1,r=m+1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	ans=min(ans,E[l-1].w);
	write(ans==1e9?-1:ans);
	return 0;
}