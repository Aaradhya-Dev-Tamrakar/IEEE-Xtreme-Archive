#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAX=2e9;
const int N=100005;
const int MOD=1e9+7;
int n;
struct matrix
{
	int c[2][2];
	void print ()
	{
		printf("matrix:\n");
		for (int u=0;u<=1;u++)
		{
			for (int i=0;i<=1;i++)
				printf("%d ",c[u][i]);
			printf("\n");
		}
	}
};
matrix base;
int add (int x,int y)	{return ((LL)x+(LL)y)%MOD;}
int mul (int x,int y)	{return ((LL)x*(LL)y)%MOD;}
matrix operator * (matrix x,matrix y)
{
	matrix c;
    for (int u=0;u<=1;u++)
        for (int i=0;i<=1;i++)
        	{
				c.c[u][i]=0;
				for (int j=0;j<=1;j++) 
					c.c[u][i]=add(c.c[u][i],mul(x.c[u][j],y.c[j][i]));
			}
    return c;
}
struct qq
{
	int son[2],fa;
	matrix a,b;//他自己的矩阵    他子树的矩阵乘积 
	int c;//和上一个数的差值
	int c1;//子树的c的和 
	int cc;//在这个点的子树里面，c的最大值
}tr[N*2];int num=0;
int root;
int mymax (int x,int y)	{return x>y?x:y;}
void update (int x)
{
	if (x==0) return ;
	int s1=tr[x].son[0],s2=tr[x].son[1];
	tr[x].b=tr[s1].b*tr[x].a;
	tr[x].b=tr[x].b*tr[s2].b;
	tr[x].cc=mymax(tr[x].c,mymax(tr[s1].cc,tr[s2].cc));
	tr[x].c1=tr[s1].c1+tr[x].c+tr[s2].c1;
}
void rotate (int x)
{
	int y=tr[x].fa,z=tr[y].fa;
	int w,r,R;
	w=(tr[y].son[0]==x);
	
	r=tr[x].son[w];R=y;
	tr[R].son[1-w]=r;
	if (r!=0) tr[r].fa=R;
	
	r=x;R=z;
	if (tr[R].son[0]==y) tr[R].son[0]=x;
	else tr[R].son[1]=x;
	if (r!=0) tr[r].fa=R;
	
	r=y;R=x;
	tr[R].son[w]=r;
	if (r!=0) tr[r].fa=R;
	
	update(y);update(x);
}
void rebt (int now)//重构这个点的a数组 
{
	if (now==0) return ;
	if (now!=1&&now!=2)
	{
		tr[now].a.c[0][1]=1;tr[now].a.c[1][1]=1;
		tr[now].a.c[0][0]=tr[now].c/2;
		tr[now].a.c[1][0]=(tr[now].c-1)/2;
	}
	update(now);
}
void splay (int x,int rt)
{
	update(x);
	while (tr[x].fa!=rt)
	{
		int y=tr[x].fa,z=tr[y].fa;
		if (z==rt) rotate(x);
		else
		{
			if ((tr[y].son[0]==x)==(tr[z].son[0]==y)) rotate(y);
			else rotate(x);
			rotate(x);
		}
	}
	if (rt==0) root=x;
}
int calc (int x)//这个点的前缀和 
{
	splay(x,0);
	int s1=tr[x].son[0];
	return tr[s1].c1+tr[x].c;
}
int find_first ()//查询第一的点是哪一个 
{
	splay(1,0);
	int now=tr[1].son[1];
	while (tr[now].son[0]!=0) now=tr[now].son[0];
	return now;
}
int find1 (int x)//找到最接近x的一个数
{
	int now=root,sum=0;
	while (true)
	{
		int s1=tr[now].son[0],s2=tr[now].son[1];
		if (sum+tr[s1].c1+tr[now].c==x) break;
		else if (sum+tr[s1].c1+tr[now].c<x)
		{
			if (s2==0) break;
			sum=sum+tr[s1].c1+tr[now].c;
			now=s2;
		}
		else
		{
			if (s1==0) break;
			now=s1;
		}
	}
	splay(now,0);
	return now;
}
int qianqu (int now)
{
	splay(now,0);
	if (tr[now].son[0]==0) return now;
	now=tr[now].son[0];
	while (tr[now].son[1]!=0) now=tr[now].son[1];
	return now;
}
int houji (int now)
{
	splay(now,0);
	if (tr[now].son[1]==0) return now;
	now=tr[now].son[1];
	while (tr[now].son[0]!=0) now=tr[now].son[0];
	return now;
}
void Ins (int x,int c,int fa,int d)//加入一个点，差距的那个是c，父亲是fa（已知父亲的左儿子是他  父亲的值是d 
{
	int now=++num;
	tr[now].cc=tr[now].c=tr[now].c1=c;tr[now].fa=fa;
	tr[now].son[0]=tr[now].son[1]=0;
	rebt(now);
	
	tr[fa].son[0]=now;tr[fa].c=d-x;
	rebt(fa);
	
	splay(fa,0);
}
void del (int x)//删除这个节点 
{
	int now=qianqu(x),now1=houji(x);	
	int d=calc(now1),d1=calc(now);
	splay(now,0);splay(now1,now);
	tr[now1].son[0]=0;tr[now1].c=d-d1;
	rebt(now1);
	splay(now1,0);
}
int find2 (int x)//找到第一个差值大于2的，如果没有，则返回1 
{
	if (tr[x].c>2) return x;
	splay(x,0);
	int now=tr[x].son[0];
	if (tr[now].cc<=2) return 1;
	while (true)
	{
		int s1=tr[now].son[0],s2=tr[now].son[1];
		if (tr[s2].cc>2) now=s2;
		else if (tr[now].c>2) return now;
		else if (tr[s1].cc>2) now=s1;
		else break;
	}
	return now;
}
void add (int x)//在这个位置加1 
{
	int now=find1(x),now1;
	int d=calc(now),d1;
	if (d!=x)//如果本来就没有这个点 
	{
		if (d<x) now1=houji(now);
		else	{now1=qianqu(now);swap(now,now1);}
		//现在他在now和now1之间
		d=calc(now);d1=calc(now1);
		if (now==1) d=-1;
		if (d!=x-1&&d1!=x+1)//如果他刚好是独自一人
		{
			splay(now,0);splay(now1,now);
			if (now==1)	Ins(x,x,now1,d1);
			else Ins(x,x-d,now1,d1);
			return ;
		}
		if (d==x-1)//合成一个
		{
			del(now);add(x+1);
			return ;
		}
		if (d1==x+1)
		{
			del(now1);add(x+2);
			return ;
		}
	}
	else//本来就存在这个点 
	{
		/*del(now);//先把他删掉
		add(x+1);
		if (x==2) add(x-1);
		else if (x>2) add(x-2);*/
		int x1=find2(now);
		if (x1==1)//如果是1，那么肯定是挡住了 
			x1=houji(x1);
		if (x1==now)//就是他自己。。 
		{
			del(now);add(x+1);
			if (x==2) add(x-1);
			else if (x>2) add(x-2);
			return ;
		}
		int x2=houji(now);
		del(now);//先把他删掉再说。。 
		tr[x2].c--;rebt(x2);
		splay(x2,0);
		if (tr[x1].c==1)//如果这个是1的话
		{
			tr[x1].c=2;
			rebt(x1);
		}
		else if (tr[x1].c==2)//如果这个东西一开始是2的话 
		{
			tr[x1].c++;
			rebt(x1);
			add(1);
		}
		else//否则是一个正常的数 
		{
			int xx=calc(x1);
			tr[x1].c++;
			rebt(x1);
			add(xx-2);
		}
		splay(x1,0);
		add(x+1);
	}
}
void print ()
{
	for (int u=1;u<=num;u++)
	{
		printf("%d:fa:%d s0:%d s1:%d c:%d\n",u,tr[u].fa,tr[u].son[0],tr[u].son[1],tr[u].c);
		tr[u].b.print();
		printf("\n");
	}
}
int read ()
{
	char ch=getchar();int x=0;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9')	{x=x*10+ch-'0';ch=getchar();}
	return x;
}
int main()
{
	//freopen("fib5c.in","r",stdin);
	base.c[0][0]=1;base.c[1][1]=1;
	tr[0].b=base;
	num=2;root=1;
	tr[1].a=tr[1].b=base;tr[1].son[1]=2;tr[1].c=0;
	tr[2].a=tr[2].b=base;tr[2].fa=1;tr[2].c=MAX;
	tr[2].cc=MAX;tr[1].cc=MAX;tr[2].c1=MAX;
	update(2);update(1);
	n=read();
	for (int u=1;u<=n;u++)
	{
		int xx=read();
		add(xx);
		int x=find_first();
		int x1=1,x0=(tr[x].c-1)/2;
		int now=houji(x);
		splay(now,x);
		int ans=0;
		ans=add(ans,add(mul(x1,tr[now].b.c[1][0]),mul(x0,tr[now].b.c[0][0])));
		ans=add(ans,add(mul(x1,tr[now].b.c[1][1]),mul(x0,tr[now].b.c[0][1])));
	//	print();
		printf("%d\n",ans);
	}
	return 0;
}