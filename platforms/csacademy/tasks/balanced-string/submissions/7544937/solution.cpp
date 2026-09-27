#include<bits/stdc++.h>
using namespace std;
const int N=1e5+4;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int a[N],b[N];
char c[N];
vector<int> q[2];
bool check(int n)
{
    for(int i=n+1;i<=2*n;i++) a[i]=a[i-n];
    int pos=0;
    for(int i=2;i<=n+1;i++) if(a[i]!=a[i-1]){pos=i;break;}
    for(int i=1;i<=n;i++) b[i]=a[pos+i-1];

    q[0].clear(),q[1].clear();
    for(int i=1;i<=n;i++)
    {
        if(i==1||b[i]!=b[i-1]) q[b[i]].push_back(1);
        else q[b[i]][q[b[i]].size()-1]++;
    }

    int mx[2]={};
    for(int i=0;i<2;i++) for(auto x:q[i]) mx[i]=max(mx[i],x);
    if(mx[0]>1&&mx[1]>1) return false;
    if(mx[1]>1) swap(q[0],q[1]),swap(mx[0],mx[1]);
    int mn=1e9;
    for(auto x:q[0]) mn=min(mn,x);
    if(abs(mn-mx[0])>1) return false;
    if(mn==mx[0]) return true;

    n=0;
    for(auto x:q[0]) a[++n]=(x==mx[0]);
    return check(n);
}
void solve()
{
    scanf("%s",c+1);
    n=strlen(c+1);
    for(int i=1;i<=n;i++) a[i]=c[i]-'A';
    printf("%d\n",check(n));
}
int main()
{
    int T=read();
    while(T--) solve();
    return 0;
}