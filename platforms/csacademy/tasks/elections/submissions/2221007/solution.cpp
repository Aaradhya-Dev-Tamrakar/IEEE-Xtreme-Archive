#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
#include<assert.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
template <class T>
int upmin(T &a, const T &b){return (b<a?a=b,1:0);}
template <class T>
int upmax(T &a, const T &b){return (b>a?a=b,1:0);}
namespace io
{
	const int SIZE=(1<<20)+1;
	char ibuf[SIZE],*iS,*iT;
	char obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1;
	int getc()
	{
		(iS==iT?iS=ibuf,iT=ibuf+fread(ibuf,1,SIZE,stdin):0);
		return iS==iT?EOF:*(iS++);
	}
	int f;
	char c;
	template <class T>
	void get(T &x)
	{
		f=1;
		for(c=getc();(c<'0'||c>'9')&&c!='-';c=getc());
		(c=='-'?f=-1,c=getc():0);
		x=0;
		for(;c>='0'&&c<='9';c=getc())
			x=x*10+c-'0';
		x*=f;
	}
	void flush()
	{
		fwrite(obuf,1,oS-obuf,stdout);
		oS=obuf;
	}
	void putc(char x)
	{
		*(oS++)=x;
		if(oS==oT)
			flush();
	}
	int a[55],t;
	template <class T>
	void put(T x)
	{
		if(!x)
			putc('0');
		x<0?putc('-'),x=-x:0;
		while(x)
		{
			a[++t]=x%10;
			x/=10;
		}
		while(t)
			putc(a[t--]+'0');
	}
	void space()
	{
		putc(' ');
	}
	void enter()
	{
		putc('\n');
	}
	struct flusher
	{
		~flusher()
		{
			flush();
		}
	}
	io_flusher;
}
const int N=500010;
pii operator +(pii a,pii b)
{
	return pii(min(a.first,b.first+a.second),a.second+b.second);
}
namespace seg
{
	pii s[4*N];
	#define mid ((L+R)>>1)
	#define lc (cur<<1)
	#define rc ((cur<<1)|1)
	void modify(int cur,int x,int v,int L,int R)
	{
		if(L==R)
		{
			s[cur].first=min(0,v);
			s[cur].second=v;
			return;
		}
		if(x<=mid)
			modify(lc,x,v,L,mid);
		else
			modify(rc,x,v,mid+1,R);
		s[cur]=s[lc]+s[rc];
	}
	pii query(int cur,int l,int r,int L,int R)
	{
		if(l<=L&&r>=R)
			return s[cur];
		pii res(0,0);
		if(l<=mid)
			res=res+query(lc,l,r,L,mid);
		if(r>mid)
			res=res+query(rc,l,r,mid+1,R);
		return res;
	}
}
char str[N];
int n,q;
vector<pii> ques[N];
int e[N];
void add(int x,int v)
{
	for(;x<=n;x+=x&-x)
		e[x]+=v;
}
int query(int x)
{
	int res=0;
	for(;x;x-=x&-x)
		res+=e[x];
	return res;
}
int query(int l,int r)
{
	return query(r)-query(l-1);
}
int st[N],top;
int ans[N];
int main()
{
	scanf("%d",&n);
	scanf("%s",str+1);
	scanf("%d",&q);
	int l,r;
	for(int i=1;i<=q;i++)
	{
		io::get(l);
		io::get(r);
		ques[r].push_back(pii(l,i));
	}
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='C')
		{
			seg::modify(1,i,1,1,n);
			add(i,1);
			if(top)
			{
				add(st[top],1);
				seg::modify(1,st[top--],-1,1,n);
			}
		}
		else
			st[++top]=i;
		for(auto v:ques[i])
		{
			pii temp=seg::query(1,v.first,i,1,n);
			ans[v.second]=i-v.first+1-(query(v.first,i)+temp.first);
		}
	}
	for(int i=1;i<=q;i++)
//		printf("%d\n",ans[i]);
	{
		io::put(ans[i]);
		io::enter();
	}
	return 0;
}