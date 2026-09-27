#include <bits/stdc++.h>
#include <iostream>
#define Nmax 100005
#define INF (1LL<<62)
#define pb push_back

using namespace std;

vector <int> L[Nmax];
char s[Nmax];
bool color[Nmax],expected[Nmax];
long long cnt;
int lvl[Nmax],cnt_red[Nmax],cnt_blue[Nmax],nr,n;

inline void Mark(int nod, int tata, int c)
{
    expected[nod]=c;
    for(auto it : L[nod])
        if(it!=tata)
        {
            lvl[it]=lvl[nod]+1;
            Mark(it,nod,1-c);
        }
}

inline void Solve(int nod, int tata)
{
    cnt_red[nod]=cnt_blue[nod]=0;
    if(color[nod]!=expected[nod])
    {
        if(color[nod]) ++cnt_red[nod];
        else ++cnt_blue[nod];
        cnt+=lvl[nod]; ++nr;
    }
    for(auto it : L[nod])
        if(it!=tata)
        {
            Solve(it,nod);
            cnt_red[nod]+=cnt_red[it];
            cnt_blue[nod]+=cnt_blue[it];
        }

    int x = min(cnt_red[nod],cnt_blue[nod]);

    cnt-=2LL*lvl[nod]*x;
    cnt_red[nod]-=x; cnt_blue[nod]-=x;

    if(!tata && cnt_red[nod]+cnt_blue[nod]>0)
    {
        cnt=-1; return;
    }
}

int main() {
    int i,x,y;
    long long sol=INF;

    #ifndef ONLINE_JUDGE
        freopen ("date.in","r",stdin);
        freopen ("date.out","w",stdout);
    #endif

    cin>>n>>(s+1);
    for(i=1;i<n;++i)
    {
        cin>>x>>y;
        L[x].pb(y); L[y].pb(x);
    }
   for(i=1;i<=n;++i) color[i]=(s[i]=='B');

   cnt=nr=0;
   Mark(1,0,0);
   Solve(1,0);
   if(cnt!=-1) sol=min(sol,cnt);

   cnt=nr=0;
   Mark(1,0,1);
   Solve(1,0);
   if(cnt!=-1) sol=min(sol,cnt);

   if(sol==INF) cout<<"-1\n";
   else cout<<sol<<"\n";
}
