#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define all(a) a.begin(),a.end()
#define HEAP(...) priority_queue<__VA_ARGS__ >
#define heap(...) priority_queue<__VA_ARGS__,vector<__VA_ARGS__ >,greater<__VA_ARGS__ > > 
#define pii pair<int,int> 
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define dprintf(...) fprintf(stderr,__VA_ARGS__)
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define clr(a,x) memset(a,x,sizeof(a))
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define SZ(x) ((int)x.size())
using namespace std;
template<class T> inline void gmin(T &x,const T &y){x=x>y?y:x;}
template<class T> inline void gmax(T &x,const T &y){x=x<y?y:x;}
template<class T> inline bool Gmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T> inline bool Gmax(T &x,const T &y){return x<y?x=y,1:0;}
const int BufferSize=1<<16;
char buffer[BufferSize],*Bufferhead,*Buffertail;
bool Terminal;
inline char Getchar(){
	if(Bufferhead==Buffertail){
		int l=fread(buffer,1,BufferSize,stdin);
		if(!l){Terminal=1;return 0;}
		Buffertail=(Bufferhead=buffer)+l;
	}
	return *Bufferhead++;
}
template<class T>inline bool read(T &x){
	x=0;char c=Getchar(),rev=0;
	while(c<'0'||c>'9'){rev|=c=='-';c=Getchar();if(Terminal)return 0;}
	while(c>='0'&&c<='9') x=x*10+c-'0',c=Getchar();
	if(c=='.'){
		c=Getchar();double t=0.1;
		while(c>='0'&&c<='9') x=x+(c-'0')*t,c=Getchar(),t=t/10;
	}
	x=rev?-x:x;
	return 1;
}
template<class T1,class T2> inline bool read(T1 &x,T2 &y){return read(x)&read(y);}
template<class T1,class T2,class T3> inline bool read(T1 &x,T2 &y,T3 &z){return read(x)&read(y)&read(z);}
template<class T1,class T2,class T3,class T4> inline bool read(T1 &x,T2 &y,T3 &z,T4 &w){return read(x)&read(y)&read(z)&read(w);}
inline bool reads(char *x){
	char c=Getchar();
	while(c<33||c>126){c=Getchar();if(Terminal)return 0;}
	while(c>=33&&c<=126) (*x++)=c,c=Getchar();
	*x=0;return 1;
}
template<class T>inline void print(T x,const char c='\n'){
	if(!x){putchar('0');putchar(c);return;}
	if(x<0) putchar('-'),x=-x;
	int m=0,a[20];
	while(x) a[m++]=x%10,x/=10;
	while(m--) putchar(a[m]+'0');
	putchar(c);
}
//--------------------------------head---------------------------------------------

const int inf=0x3f3f3f3f;
const int N=500005,M=100005,mod=1e9+7;
template<class T,class S> inline void ch(T &x,const S y){x=(x+y)%mod;}
inline int exp(int x,int y,const int mod=::mod){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

int n,Q,sum[N],ans[N],p[N<<2],flag[N<<2];
struct node{int l,r,num;}q[N];

inline void build(int l,int r,int k){
	if(l==r){p[k]=sum[l];return;}
	int mid=l+r>>1;
	build(l,mid,ls);build(mid+1,r,rs);
	p[k]=max(p[ls],p[rs]);
}
inline void add(int k,int b){flag[k]+=b;p[k]+=b;}
inline void push(int k){
	if(!flag[k]) return;
	add(ls,flag[k]);add(rs,flag[k]);
	flag[k]=0;
}
inline void add(int l,int r,int x,int y,int k,int b){
	if(x<=l&&r<=y){add(k,b);return;}
	push(k);
	int mid=l+r>>1;
	if(x<=mid) add(l,mid,x,y,ls,b);
	if(y>mid) add(mid+1,r,x,y,rs,b);
	p[k]=max(p[ls],p[rs]);
}
inline int get(int l,int r,int x,int y,int k){
	if(x<=l&&r<=y)return p[k];
	push(k);
	int mid=l+r>>1,res=-inf;
	if(x<=mid) gmax(res,get(l,mid,x,y,ls));
	if(y>mid) gmax(res,get(mid+1,r,x,y,rs));
	return res;
}
inline int find(int *a,int n,int r){
	int L=1,R=n+1;
	while(L<R){
		int mid=L+R>>1;
		if(a[mid]<=r) R=mid; else L=mid+1;
	}
	return n+1-R;
}

int main(){
#ifdef rqgao2014
	assert(freopen("input.txt","r",stdin));
#endif
	static char s[N];
	scanf("%d",&n);
	scanf("%s",s+1);
	scanf("%d",&Q);
	for(int i=1;i<=n;i++)
		if(s[i]=='C') sum[i]=sum[i-1]+1; else sum[i]=sum[i-1]-1;
	for(int i=1;i<=Q;i++)
		scanf("%d%d",&q[i].l,&q[i].r),q[i].num=i;
	build(0,n,1);
	sort(q+1,q+Q+1,[&](node x,node y){return x.l>y.l;});
	static int sta[N],top;
	for(int i=n,j=1;~i;i--){
		while(top&&sum[i]<=sum[sta[top]]){
			add(0,n,sta[top],n,1,-1);
			top--;
		}
		while(j<=Q&&q[j].l-1==i){
			int r=q[j].r,num=q[j].num;
			ans[num]=find(sta,top,r)+get(0,n,i,r,1)-get(0,n,r,r,1);
			j++;
		}
		sta[++top]=i;
		add(0,n,i,n,1,1);
	}
	for(int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
	return 0;
}