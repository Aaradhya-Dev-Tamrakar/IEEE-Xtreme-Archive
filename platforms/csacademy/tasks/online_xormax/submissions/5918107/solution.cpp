#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define IL inline
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
IL LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
#define io read()
const int N=100008;
int n;
int a[N],b[N];
bool vis[N];
int ans[N];
int p[N],sz[N];
IL int find(int x)
{
	return x==p[x]?x:p[x]=find(p[x]);
}
int rt[N],tot;
struct Trie{
	int ls,rs,v;
}trie[N*50];
IL void update(int t,int val)
{
	for(int i=29;i>=0;--i){
		if((val>>i)&1){
			trie[++tot]=trie[trie[t].rs];
			++trie[tot].v;
			//新建点 
			trie[t].rs=tot;
			t=tot;
		}
		else{
			trie[++tot]=trie[trie[t].ls];
			++trie[tot].v;
			//新建点 
			trie[t].ls=tot;
			t=tot;
		}
	}
}
IL int query(int l,int r,int val)
{
//	cout<<l<<' '<<r<<' '<<val<<'\n';
	int tmp=0;
	for(int i=29;i>=0;--i){
		if((val>>i)&1){
			if(trie[trie[r].ls].v-trie[trie[l].ls].v>0){
				r=trie[r].ls;
				l=trie[l].ls;
				tmp+=1<<i;
			}
			else{
				r=trie[r].rs;
				l=trie[l].rs;
			}
		}
		else{
			if(trie[trie[r].rs].v-trie[trie[l].rs].v>0){
				r=trie[r].rs;
				l=trie[l].rs;
				tmp+=1<<i;
			}
			else{
				r=trie[r].ls;
				l=trie[l].ls;
			}
		}
	}
	return tmp;
}
int main()
{
	n=io;
	for(int i=1;i<=n;++i){
		a[i]=io^a[i-1];
	}
	for(int i=1;i<=n;++i){
		b[i]=io;
	}
	for(int i=1;i<=n;++i){
		p[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=n+1;++i){
		trie[++tot]=trie[rt[i-1]];
		rt[i]=tot;
		update(rt[i],a[i-1]);
	}
	for(int i=n;i;--i){
		//cout<<"!!!!!!!!"<<i<<' '<<b[i]<<'\n';
		vis[b[i]]=1;
		int L=0,R=0;
		if(vis[b[i]-1]){
			int p1=find(b[i]-1),p2=find(b[i]);
			L=sz[p1];
			p[p1]=p2;
			sz[p2]+=L;
		}
		if(vis[b[i]+1]){
			int p1=find(b[i]+1),p2=find(b[i]);
			R=sz[p1];
			p[p1]=p2;
			sz[p2]+=R;
		}
		//cout<<L<<' '<<R<<'\n';
		if(L>R){
			L=b[i]-L-1;
			for(int j=b[i];vis[j];++j){
				//cout<<"!"<<L<<' '<<j<<'\n';
				ans[i]=max(ans[i],query(rt[L],rt[j],a[j]));
			}
		}
		else{
			R=b[i]+1+R;
			for(int j=b[i];vis[j];--j){
				//cout<<"!!"<<j<<' '<<R<<'\n';
				ans[i]=max(ans[i],query(rt[j-1],rt[R],a[j-1]));
			}
		}
		ans[i]=max(ans[i],ans[i+1]);
	}
	for(int i=1;i<=n;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}
