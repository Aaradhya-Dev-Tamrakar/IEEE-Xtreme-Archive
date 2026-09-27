#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define _ 0
const long long maxn=1e5+5;
const long long inf=0x3f3f3f3f;
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
struct node{
	long long x,y,ca;
	bool operator<(const node &o){
		return o.ca<ca;
	}
}a[maxn],pca[maxn];
long long p[maxn];
set<long long> l,r;
long long ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].ca=a[i].y-a[i].x;
	}
	for(long long i=1;i<=m;i++)
		cin>>p[i];
	sort(p+1,p+m+1);
	for(long long i=1;i<=m-1;i++)
	{
		pca[i].x=p[i];
		pca[i].y=p[i+1];
		pca[i].ca=p[i+1]-p[i];
	}
	sort(a+1,a+n+1);
	sort(pca+1,pca+m);
// 	for(long long i=1;i<=n;i++)
// 		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].ca<<endl;
// 	cout<<endl;
// 	for(long long i=1;i<=n;i++)
// 		cout<<pca[i].x<<" "<<pca[i].y<<" "<<pca[i].ca<<endl;
// 	cout<<endl;
	long long j=1;
	for(long long i=1;i<=n;i++)
	{
		long long minv=inf;
		for(j=j;j<m;j++)
		{
			if(a[i].ca>pca[j].ca)
				break;
			l.insert(pca[j].x);
			r.insert(pca[j].y);
		}
		auto x=l.lower_bound(a[i].x),y=r.upper_bound(a[i].y);
		minv=min(p[m]-a[i].x,a[i].y-p[1]);
		if(x!=l.end())
			minv=min(minv,abs(a[i].x-(*x)));
		if(y!=r.begin())
		{
			y--;
			minv=min(minv,abs(a[i].y-(*y)));
		}
		ans+=minv;
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return ~~(0^_^0);
}
//看所有题目
