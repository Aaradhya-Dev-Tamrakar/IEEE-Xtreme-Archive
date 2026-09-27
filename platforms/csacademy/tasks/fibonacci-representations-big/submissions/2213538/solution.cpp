#include<bits/stdc++.h>

#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;

typedef double db;
typedef long long LL;
typedef pair<int,int> pir;
typedef unsigned int ui;

ui seed;
ui getrand(){seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;}

int get(){
	char ch;
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	if (ch=='-'){
		int s=0;
		while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
		return s;
	}
	int s=ch-'0';
	while(ch=getchar(),ch>='0'&&ch<='9')s=s*10+ch-'0';
	return s;
}

const int N = 5e5+5;
const int mo = 1e9+7;

int n;
struct matrix{
	LL v[2][2];
	LL * operator[](int x){return v[x];}
	friend matrix operator *(matrix a,matrix b){
		matrix c;
		fo(i,0,1)
			fo(j,0,1)
			c[i][j]=(a[i][0]*b[0][j]+a[i][1]*b[1][j])%mo;
		return c;
	}
};
struct node{
	ui key;
	int l,r;
	int x,ad;
	int delt,tot;
	matrix val;
}tree[N];
int rt,pt;

void down(int now){
	if (tree[now].ad!=0){
		if (tree[now].l)tree[tree[now].l].x+=tree[now].ad,tree[tree[now].l].ad+=tree[now].ad;
		if (tree[now].r)tree[tree[now].r].x+=tree[now].ad,tree[tree[now].r].ad+=tree[now].ad;
		tree[now].ad=0;
	}
}

matrix build_matrix(int d){
	if (d==-1){
		matrix c;
		c[0][0]=c[1][1]=1;
		c[0][1]=c[1][0]=0;
		return c;
	}
	matrix c;
	c[0][0]=c[1][0]=1;
	c[0][1]=d/2;
	c[1][1]=(d+1)/2;
	return c;
}

void update(int now){
	tree[now].tot=tree[tree[now].l].tot+tree[tree[now].r].tot+1;
	tree[now].val=tree[tree[now].l].val*build_matrix(tree[now].delt)*tree[tree[now].r].val;
}

bool exist(int now,int x){
	if (!now)return 0;
	down(now);
	if (tree[now].x==x)return 1;
	return tree[now].x<x?exist(tree[now].r,x):exist(tree[now].l,x);
}

bool exist(int x){return exist(rt,x);}

int sta[N];

pir split(int now,int x){
	if (!now)return make_pair(0,0);
	down(now);
	if (tree[now].x<=x){
		pir u=split(tree[now].r,x);
		tree[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split(tree[now].l,x);
	tree[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

pir Split(int now,int x){
	pir u=split(now,x);
	if (u.se){
		int top=0;
		int p=u.se;
		for(;tree[p].l;p=tree[p].l){
			sta[++top]=p;
			down(p);
		}
		tree[p].delt=0;
		update(p);
		for(;top;top--)update(sta[top]);
	}
	return u;
}

pir split_L(int now,int x){
	if (!now)return make_pair(0,0);
	down(now);
	if (tree[now].x<x-tree[tree[now].r].tot*2||tree[now].x==0){
		pir u=split_L(tree[now].r,x);
		tree[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split_L(tree[now].l,x-(tree[tree[now].r].tot+1)*2);
	tree[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

pir Split_L(int now,int x){
	pir u=split_L(now,x);
	if (u.se){
		int top=0;
		int p=u.se;
		for(;tree[p].l;p=tree[p].l){
			sta[++top]=p;
			down(p);
		}
		tree[p].delt=0;
		update(p);
		for(;top;top--)update(sta[top]);
	}
	return u;
}

pir split_R(int now,int x){
	if (!now)return make_pair(0,0);
	down(now);
	if (tree[now].x==x+tree[tree[now].l].tot*2+1){
		pir u=split_R(tree[now].r,x+(tree[tree[now].l].tot+1)*2);
		tree[now].r=u.fi;
		update(now);
		return make_pair(now,u.se);
	}
	pir u=split_R(tree[now].l,x);
	tree[now].l=u.se;
	update(now);
	return make_pair(u.fi,now);
}

pir Split_R(int now,int x){
	pir u=split_R(now,x);
	if (u.se){
		int top=0;
		int p=u.se;
		for(;tree[p].l;p=tree[p].l){
			sta[++top]=p;
			down(p);
		}
		tree[p].delt=0;
		update(p);
		for(;top;top--)update(sta[top]);
	}
	return u;
}

int merge(int x,int y){
	if (!x||!y)return x^y;
	down(x),down(y);
	if (tree[x].key<tree[y].key){
		tree[x].r=merge(tree[x].r,y);
		update(x);
		return x;
	}
	tree[y].l=merge(x,tree[y].l);
	update(y);
	return y;
}

int Merge(int x,int y){
	if (!x||!y)return x^y;
	int p=x;
	for(;tree[p].r;p=tree[p].r)down(p);
	int lst=tree[p].x;
	int top=0;
	p=y;
	for(;tree[p].l;p=tree[p].l){
		sta[++top]=p;
		down(p);
	}
	tree[p].delt=tree[p].x-lst-1;
	update(p);
	for(;top;top--)update(sta[top]);
	return merge(x,y);
}

void push(int x){
	if (exist(x)){
		if (x==1){
			pir u=Split(rt,1);
			pir v=Split(u.fi,0);
			rt=Merge(v.fi,u.se);
			push(2);
			return;
		}
		pir u=Split(rt,x);
		pir v=Split_L(u.fi,x);
		int y=v.se;
		for(;tree[y].l;y=tree[y].l)down(y);
		int w=tree[y].x;
		if (w==0){
			pir t=Split(u.fi,0);
			if (t.se)tree[t.se].x--,tree[t.se].ad--;
			rt=Merge(t.fi,Merge(t.se,u.se));
			push(x+1);
		}
		else{
			pir t=Split(v.se,x-1);
			if (t.fi)tree[t.fi].x++,tree[t.fi].ad++;
			rt=Merge(v.fi,Merge(t.fi,u.se));
			push(x+1);
			if (w>1)push(max(1,w-2));
		}
		return;
	}
	if (exist(x+1)){
		pir u=Split(rt,x);
		pir v=Split_R(u.se,x);
		int y=v.fi;
		for(;tree[y].r;y=tree[y].r)down(y);
		tree[++pt].key=getrand();
		tree[pt].x=tree[y].x+1;
		tree[pt].tot=1;
		rt=Merge(u.fi,Merge(pt,v.se));
	}
	else
		if (x>1&&exist(x-1)){
			pir u=Split(rt,x-2);
			pir v=Split_R(Split(u.se,x).se,x+1);
			tree[++pt].key=getrand();
			tree[pt].tot=1;
			if (v.fi){
				int y=v.fi;
				for(;tree[y].r;y=tree[y].r)down(y);
				tree[pt].x=tree[y].x+1;
			}
			else tree[pt].x=x+1;
			rt=Merge(u.fi,Merge(pt,v.se));
		}
		else{
			tree[++pt].key=getrand();
			tree[pt].tot=1;
			tree[pt].x=x;
			pir u=Split(rt,x);
			rt=Merge(u.fi,Merge(pt,u.se));
		}
}

void getall(int x,int d){
	if(!x)return;
	getall(tree[x].l,d+tree[x].ad);
	printf("%d ",tree[x].x+d);
	getall(tree[x].r,d+tree[x].ad);
}

int main(){
	seed=845125485;
	n=get();
	rt=pt=1;
	tree[1].key=getrand();
	tree[1].x=0;tree[1].delt=-1;tree[1].tot=1;
	tree[0].val[0][0]=tree[0].val[1][1]=1;
	tree[0].val[0][1]=tree[0].val[1][0]=0;
	tree[1].val=tree[0].val;
	fo(i,1,n){
		int x=get();
		push(x);
		//printf("<%d> Add %d\n",i,x);
		//getall(rt,0);putchar('\n');
		printf("%lld\n",(tree[rt].val[0][0]+tree[rt].val[0][1])%mo);
	}
	return 0;
}