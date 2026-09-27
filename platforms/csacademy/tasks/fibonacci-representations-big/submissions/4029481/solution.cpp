#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define ull unsigned ll
#define N 500010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
mt19937_64 rnd(std::chrono::system_clock::now().time_since_epoch().count());
struct Matrix{
	ll a[2][2];
	Matrix(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	Matrix(ll _x,ll _y,ll _z,ll _w){a[0][0]=_x,a[0][1]=_y,a[1][0]=_z,a[1][1]=_w;}
	Matrix operator * (const Matrix &x)const{
		ll i,j,k;
		Matrix ret;
		for(i=0;i<2;i++)
		{
			for(j=0;j<2;j++)
			{
				ret.a[i][j]=0;
				for(k=0;k<2;k++)
				{
					ret.a[i][j]=(ret.a[i][j]+a[i][k]*x.a[k][j])%mod;
				}
			}
		}
		return ret;
	}
};
struct Treap{
	ll val[N],ch[N][2],sumd[N],vald[N],pd[N],tot,rt;
	ull rd[N];
	Matrix mat[N],sum[N];
	void init()
	{
		tot=0,rt=0;
		memset(ch,0,sizeof(ch));
		memset(sumd,0,sizeof(sumd));
		memset(pd,0,sizeof(pd));
		return;
	}
	void pushup(ll x)
	{
		sumd[x]=sumd[ch[x][0]]+sumd[ch[x][1]]+vald[x];
		sum[x]=mat[x];
		if(ch[x][0])
		{
			sum[x]=sum[ch[x][0]]*sum[x];
		}
		if(ch[x][1])
		{
			sum[x]=sum[x]*sum[ch[x][1]];
		}
		return;
	}
	void pushdown(ll x)
	{
		if(ch[x][0])
		{
			val[ch[x][0]]+=pd[x];
			pd[ch[x][0]]+=pd[x];
		}
		if(ch[x][1])
		{
			val[ch[x][1]]+=pd[x];
			pd[ch[x][1]]+=pd[x];
		}
		pd[x]=0;
		return;
	}
	void Split(ll cur,ll v,ll &x,ll &y)
	{
		if(!cur)
		{
			x=y=0;
			return;
		}
		pushdown(cur);
		if(val[cur]<=v)
		{
			x=cur;
			Split(ch[cur][1],v,ch[cur][1],y);
		}
		else
		{
			y=cur;
			Split(ch[cur][0],v,x,ch[cur][0]);
		}
		pushup(cur);
		return;
	}
	ll Merge(ll x,ll y)
	{
		if((!x)||(!y))
		{
			return x|y;
		}
		if(rd[x]<=rd[y])
		{
			pushdown(x);
			ch[x][1]=Merge(ch[x][1],y);
			pushup(x);
			return x;
		}
		pushdown(y);
		ch[y][0]=Merge(x,ch[y][0]);
		pushup(y);
		return y;
	}
	void ins(ll x,ll d)
	{
		rd[++tot]=rnd();
		val[tot]=x;
		sumd[tot]=vald[tot]=d;
		sum[tot]=mat[tot]=Matrix(1,(d-1)/2,1,d/2);
		ll rt1,rt2;
		Split(rt,x,rt1,rt2);
		rt=Merge(Merge(rt1,tot),rt2);
		return;
	}
	void upd(ll x,ll d)
	{
		ll rt1,rt2,rt3,cur;
		Split(rt,x-1,rt1,rt2);
		for(cur=rt2;ch[cur][0];cur=ch[cur][0]);
		Split(rt2,val[cur],rt2,rt3);
		if(rt2)
		{
			sumd[rt2]+=d,vald[rt2]+=d;
			sum[rt2]=mat[rt2]=Matrix(1,(sumd[rt2]-1)/2,1,sumd[rt2]/2);
		}
		rt=Merge(rt1,Merge(rt2,rt3));
		return;
	}
	ll del(ll l,ll r)
	{
		ll rt1,rt2,rt3;
		Split(rt,r,rt1,rt3);
		Split(rt1,l-1,rt1,rt2);
		ll ret=sumd[rt2];
		rt=Merge(rt1,rt3);
		return ret;
	}
	void updv(ll l,ll r,ll v)
	{
		ll rt1,rt2,rt3;
		Split(rt,r,rt1,rt3);
		Split(rt1,l-1,rt1,rt2);
		pd[rt2]+=v,val[rt2]+=v;
		rt=Merge(Merge(rt1,rt2),rt3);
		return;
	}
}trp;
ll n,a[N];
set<pair<ll,ll> > alld;
void doins(ll l,ll r)
{
	set<pair<ll,ll> >::iterator it=alld.lower_bound(make_pair(r,0));
	if(it!=alld.end()&&it->F==r+2)
	{
		r=it->S;
		alld.erase(it);
	}
	it=alld.lower_bound(make_pair(l,0));
	if(it!=alld.begin())
	{
		it--;
		if(it->S==l-2)
		{
			l=it->F;
			alld.erase(it);
		}
	}
	alld.insert(make_pair(l,r));
	return;
}
void ins(ll x)
{
	if(alld.empty())
	{
		trp.ins(x,x);
		doins(x,x);
		return;
	}
	set<pair<ll,ll> >::iterator it=alld.lower_bound(make_pair(x,0));
	if(it!=alld.begin())
	{
		it--;
		if(it->S<x)
		{
			it++;
		}
	}
	if(it!=alld.end())
	{
		ll l=it->F,r=it->S;
		if(l<=x+1&&r>=x+1&&((x+1)%2==r%2))
		{
			ll s=trp.del(x+1,r);
			trp.upd(r+1,-1);
			trp.ins(r+1,s+1);
			alld.erase(make_pair(l,r));
			if(l<x)
			{
				doins(l,x-1);
			}
			doins(r+1,r+1);
			return;
		}
		if(l<=x&&r>=x&&(x%2==r%2))
		{
			ll v=trp.del(x,x);
			trp.upd(x+1,v);
			alld.erase(make_pair(l,r));
			if(l<=x-2)
			{
				doins(l,x-2);
			}
			if(x+2<=r)
			{
				doins(x+2,r);
			}
			ins(x+1);
			if(x>l)
			{
				trp.upd(x+1,-1);
				trp.upd(l,1);
				trp.updv(l,x-2,1);
				alld.erase(make_pair(l,x-2));
				doins(l+1,x-1);
			}
			if(l>1)
			{
				ins(l==2?1:l-2);
			}
			return;
		}
	}
	if(it==alld.begin())
	{
		trp.upd(x+1,-x);
		trp.ins(x,x);
		doins(x,x);
		return;
	}
	it--;
	ll l=it->F,r=it->S;
	if(r==x-1)
	{
		ll v=trp.del(r,r);
		trp.upd(x+1,v);
		alld.erase(make_pair(l,r));
		if(l<=r-2)
		{
			doins(l,r-2);
		}
		ins(x+1);
		return;
	}
	trp.upd(x+1,r-x);
	trp.ins(x,x-r);
	doins(x,x);
	return;
}
int main(){
	ll i;
	trp.init();
	n=rint();
	for(i=0;i<n;i++)
	{
		a[i]=rint();
	}
	for(i=0;i<n;i++)
	{
		ins(a[i]);
		Matrix ans=trp.sum[trp.rt];
		printf("%lld\n",(ans.a[0][0]+ans.a[0][1])%mod);
	}
	return 0;
}