#include<bits/stdc++.h>
typedef int LL;
typedef double dl;
#define opt operator
#define pb push_back
const LL maxn=1e6+9,mod=998244353,inf=0x3f3f3f3f;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3ll)+(x<<1ll)+c-'0'; c=getchar();
	}return x*f;
}
void Chkmin(LL &x,LL y){
	if(y<x) x=y;
}
void Chkmax(LL &x,LL y){
	if(y>x) x=y;
}
LL add(LL x,LL y){
	return x+=y,x>=mod?x-mod:x;
}
LL dec(LL x,LL y){
	return x-=y,x<0?x+mod:x;
}
LL mul(LL x,LL y){
	return 1ll*x*y%mod;
}
struct node{
	LL sum,mi,lt,rt,ans,tag;
}tree[30000009];
LL n,nod,top;
LL tr[maxn],a[maxn],sta[maxn];
char s[maxn];
void Update(LL nw){
	LL lt(tree[nw].lt),rt(tree[nw].rt);
	tree[nw].sum=tree[lt].sum+tree[rt].sum;
	tree[nw].mi=std::min(tree[rt].mi,tree[lt].mi+tree[rt].sum);
}
void Modify1(LL &nw,LL pre,LL l,LL r,LL x,LL v){
	nw=++nod;
	tree[nw]=tree[pre];
	if(l==r){
		tree[nw].sum=v;
		tree[nw].mi=(v==-1?-1:0);
		return;
	}
	LL mid(l+r>>1);
	if(x<=mid){
		Modify1(tree[nw].lt,tree[nw].lt,l,mid,x,v);
	}else{
		Modify1(tree[nw].rt,tree[nw].rt,mid+1,r,x,v);
	}
	Update(nw);
}
void Modify2(LL &nw,LL pre,LL l,LL r,LL x,LL v){
	nw=++nod;
	tree[nw]=tree[pre];
	if(x<=l){
		tree[nw].tag+=v; return;
	}
	LL mid(l+r>>1);
	if(x<=mid) Modify2(tree[nw].lt,tree[pre].lt,l,mid,x,v);
	Modify2(tree[nw].rt,tree[pre].rt,mid+1,r,x,v);
	Update(nw);
}
LL Query1(LL nw,LL l,LL r,LL x){
	if(!nw) return 0;
	if(l==r) return tree[nw].tag;
	LL mid(l+r>>1),ret(tree[nw].tag);
	if(x<=mid) return ret+=Query1(tree[nw].lt,l,mid,x);
	return ret+=Query1(tree[nw].rt,mid+1,r,x);
}
node Query2(LL nw,LL l,LL r,LL x){
	//printf("(%d,%d)(%d,%d)\n",l,r,tree[nw].sum,tree[nw].mi);
	if(r<=x) return tree[nw];
	LL mid(l+r>>1);
	if(x<=mid) return Query2(tree[nw].lt,l,mid,x);
	node Tmp1(Query2(tree[nw].lt,l,mid,x)),Tmp2(Query2(tree[nw].rt,mid+1,r,x)),Tmp3;
	Tmp3.sum=Tmp1.sum+Tmp2.sum;
	Tmp3.mi=std::min(Tmp2.mi,Tmp1.mi+Tmp2.sum);
	//printf("# (%d,%d)(%d,%d)\n",l,r,Tmp3.sum,Tmp3.mi);
	return Tmp3;
}
int main(){
    n=Read();
    scanf(" %s",s+1);
    for(LL i=1;i<=n;++i) if(s[i]=='C') a[i]=1;else a[i]=-1;
    for(LL i=n;i>=1;--i){
    	if(a[i]==1){
    		Modify1(tr[i],tr[i+1],1,n,i,1);
    		if(top){
    			LL x(sta[top--]);
    			//printf("%d ",x);
			    Modify1(tr[i],tr[i],1,n,x,-1);
			    Modify2(tr[i],tr[i],1,n,x,-1);
			}
		}else{
			sta[++top]=i;
			Modify1(tr[i],tr[i+1],1,n,i,0);
			Modify2(tr[i],tr[i],1,n,i,1);
		}
	}
	//puts("");
    LL q=Read();
    while(q--){
    	LL l(Read()),r(Read()),ret(Query1(tr[l],1,n,r));
    	node Tmp(Query2(tr[l],1,n,r));
    	//printf("# %d %d\n",ret,Tmp.sum);
    	ret+=(-Tmp.mi);
    	printf("%d\n",ret);
	}
	return 0;
}/*
11
CCCTTTTTTCC
1
4 9

*/

