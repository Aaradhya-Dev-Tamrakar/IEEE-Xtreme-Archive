#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=500005;
int Mn[N<<2],Mx[N<<2],S[N<<2],p[N][20],mx[N][20];
int sum[N],sum2[N],n,Q,x,y,pre,res;
char st[N];

void build(int o,int l,int r){
	if(l==r){
		S[o]=(st[l]=='T'?-1:1);
		Mn[o]=min(0,S[o]);
		Mx[o]=max(0,S[o]);
		return;
	}
	build(lc,l,mid),build(rc,mid+1,r);
	S[o]=S[lc]+S[rc];
	Mn[o]=min(Mn[lc],S[lc]+Mn[rc]);
	Mx[o]=max(Mx[lc],S[lc]+Mx[rc]);
//	printf("@ (%d,%d)   %d   %d   %d\n",l,r,S[o],Mn[o],Mx[o]);
}

int qry(int o,int l,int r,int x,int y){
	if(l==x&&y==r&&pre+Mn[o]>=0){
		pre+=S[o];
		return -1;
	}
	if(l==r) return l;
	if(y<=mid) return qry(lc,l,mid,x,y);
	if(mid<x) return qry(rc,mid+1,r,x,y);
	int ret=qry(lc,l,mid,x,mid);
	return ret!=-1?ret:qry(rc,mid+1,r,mid+1,y);
}

void ask(int o,int l,int r,int x,int y){
	if(l==x&&y==r){
		res=max(res,pre+Mx[o]);
		pre+=S[o];
		return;
	}
	if(x<=mid) ask(lc,l,mid,x,min(y,mid));
	if(mid<y) ask(rc,mid+1,r,max(mid+1,x),y);
}

int main(){
	read(n);
	assert(scanf("%s",st+1));
	rep(i,1,n){
		sum[i]=sum[i-1]+(st[i]=='C');
		sum2[i]=sum2[i-1]+(st[i]=='T');
	}
	build(1,1,n);
	rep(j,0,18){
		p[n+1][j]=n+1;
	}
	per(i,n,1){
		pre=0;
		int t=qry(1,1,n,i,n);
		if(t==-1) p[i][0]=n+1;
		else p[i][0]=t+1;
		pre=res=0;
		ask(1,1,n,i,p[i][0]-1);
		mx[i][0]=res;
		//printf("# %d  %d  %d\n",i,p[i][0],mx[i][0]);
		rep(j,1,18){
			p[i][j]=p[p[i][j-1]][j-1];
			mx[i][j]=max(mx[i][j-1],mx[p[i][j-1]][j-1]);
		}
	}
	read(Q);
	rep(i,1,Q){
		read(x),read(y);
		int tot=sum2[y]-sum2[x-1]-(sum[y]-sum[x-1]),ans=0;
		per(j,18,0){
			if(p[x][j]-1<=y){
				ans=max(ans,mx[x][j]);
				x=p[x][j];
			}
		}
		if(x<=y){
			pre=res=0;
			ask(1,1,n,x,y);
			ans=max(ans,res);
		}
		printf("%d\n",max(0,tot+ans));
	}
	return 0;
}