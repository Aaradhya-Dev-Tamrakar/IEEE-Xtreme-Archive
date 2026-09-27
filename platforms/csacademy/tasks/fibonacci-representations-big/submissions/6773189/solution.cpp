#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef map<int,int> mpii;
typedef set<pii> spii;
#define itr iterator
#define sa second
#define yuu first
template<typename T>
T ultimus(T x){return --x;}
template<typename T>
T proximus(T x){return ++x;}
set<pii>gauche;
struct Matrix
{
	int a[2][2];
	Matrix(){memset(a,0,sizeof(a));}
	Matrix(int d)
	{
		a[0][0]=1;
		a[1][0]=1;
		a[0][1]=(d-1)/2;
		a[1][1]=d/2;
	}
	/*void print()
	{
		puts("---");
		printf("%d %d\n%d %d\n",a[0][0],a[0][1],a[1][0],a[1][1]);
		puts("---");
	}*/
}uno,po[222222];
const int Ha=1000000007;
Matrix operator*(const Matrix&a,const Matrix&b)
{
	Matrix c;
	for(int i=0;i<2;++i)
		for(int k=0;k<2;++k)
			for(int j=0;j<2;++j)	
				c.a[i][j]=(c.a[i][j]+1ll*a.a[i][k]*b.a[k][j])%Ha;
	return c;
}
struct Splay
{
	struct st
	{
		st*ls,*rs;
		Matrix ans;
	}a[2333333],*rt,*ca;
	Splay(){ca=a;rt=a;}
	void modify(int val,Matrix qwq)
	{
		//printf("modify %d\n",val);
		//qwq.print();
		st*cur=rt;
		st*stk[33];
		int cs=0;
		int l=0,r=1073741823;
		for(;l<r;)
		{
			stk[++cs]=cur;
			int mid=(l+r)>>1;
			if(val>mid)
			{
				if(!cur->rs)cur->rs=++ca;
				cur=cur->rs;
				l=mid+1;
			}
			else
			{
				if(!cur->ls)cur->ls=++ca;
				cur=cur->ls;
				r=mid;
			}
		}
		cur->ans=qwq;
		for(;cs;--cs)
		{
			cur=stk[cs];
			if(!cur->ls)cur->ans=cur->rs->ans;
			if(!cur->rs)cur->ans=cur->ls->ans;
			if(cur->ls&&cur->rs)stk[cs]->ans=stk[cs]->ls->ans*stk[cs]->rs->ans;
		}
	}
	void insert(int val,Matrix qwq){modify(val,qwq);}
	void erase(int val){modify(val,uno);}
}splay;
void erase(spii::itr it)
{
	int x=it->sa;
	spii::itr jt=proximus(it);
	gauche.erase(it);
	//printf("erase %d\n",x);
	splay.erase(x);
	if(jt==gauche.end())//do nothing
		return;
	int qwq=jt->sa,z=0;
	if(jt!=gauche.begin())z=ultimus(jt)->yuu;
	//printf("modify %d %d&%d\n",qwq,qwq-z,jt->yuu-qwq);
	splay.modify(qwq,Matrix(qwq-z)*po[jt->yuu-qwq]);
}
void insert(int l,int r)
{
	spii::itr it=gauche.insert(pii(r,l)).first;
	spii::itr jt=proximus(it);
	int qwq=it->sa,z=0;
	if(it!=gauche.begin())z=ultimus(it)->yuu;
	//printf("insert %d %d&%d\n",l,qwq-z,r-l);
	splay.insert(l,Matrix(qwq-z)*po[r-l]);
	if(jt==gauche.end())//do nothing
		return;
	qwq=jt->sa;
	//printf("modify %d %d&%d\n",qwq,qwq-r,jt->yuu-qwq);
	splay.modify(qwq,Matrix(qwq-r)*po[jt->yuu-qwq]);
}
void tuckOut(int x)
{
	if(x==-1)return;
	//printf("tuckOut %d\n",x);
	if(x==0)x=1;
	spii::itr it=gauche.lower_bound(pii(x,0));
	if(it!=gauche.end()&&x==it->sa-1)
	{
		int qwq=it->yuu+1;
		erase(it);
		tuckOut(qwq);
		return;
	}
	if(it!=gauche.begin())
	{
		spii::itr jt=ultimus(it);
		if(x==jt->yuu+1)
		{
			int qaq=jt->sa,qwq=jt->yuu;
			erase(jt);
			if(qaq<=qwq-2)insert(qaq,qwq-2);
			tuckOut(x+1);
			return;
		}
		if(x==jt->yuu+2)
		{
			if(it!=gauche.end()&&x==it->sa-2)
			{
				int qaq=jt->sa,qwq=it->yuu;
				erase(it);
				erase(jt);
				insert(qaq,qwq);
				return;
			}
			int qaq=jt->sa,qwq=jt->yuu;
			erase(jt);
			insert(qaq,qwq+2);
			return;
		}
	}
	if(it!=gauche.end()&&x==it->sa-2)
	{
		int qaq=it->sa,qwq=it->yuu;
		erase(it);
		insert(qaq-2,qwq);
		return;
	}
	insert(x,x);
}
void tuck(int x)
{
	spii::itr it=gauche.lower_bound(pii(x,0));
	if(it==gauche.end())
	{
		tuckOut(x);
		return;
	}
	if(x<it->sa)
	{
		tuckOut(x);
		return;
	}
	if((x-it->sa)&1)
	{
		// 10101010101010101000
		//+           1
		// 10101010101110101000
		// 10101010101001101000
		// 10101010101000011000
		// 10101010101000000100
		int qaq=it->sa,qwq=it->yuu;
		erase(it);
		insert(qaq,x-1);
		tuckOut(qwq+1);
	}
	else
	{
		// 00001010101010101000
		//+          1
		// 00001010102010101000
		// 00001010200110101000
		// 00001020010001101000
		// 00002001010000011000
		// 00100101010000000100
		int qaq=it->sa,qwq=it->yuu;
		erase(it);
		if(qaq+1<=x-1)insert(qaq+1,x-1);
		tuckOut(qaq-2);
		tuckOut(qwq+1);
	}
}
int a[111111];
int main()
{
	int n;
	scanf("%d",&n);
	uno.a[0][0]=uno.a[1][1]=1;
	po[0]=uno;
	for(int i=1;i<=n;++i)
		po[2*i]=po[2*i-2]*Matrix(2);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		tuck(a[i]);
		//for(spii::itr it=gauche.begin();it!=gauche.end();++it)printf(">> %d %d\n",it->sa,it->yuu);
		//splay.rt->ans.print();
		printf("%d\n",(splay.rt->ans.a[0][0]+splay.rt->ans.a[0][1])%Ha);
	}
	return 0;
}