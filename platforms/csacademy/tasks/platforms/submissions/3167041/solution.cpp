#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m;
struct platform{
    int l,r,res=0x3f3f3f3f;
    bool operator< (const platform &o) const {return r<o.r;}
}p[101010];
int b[101010];
pii sta[101010];int top=0;
inline void solve(){
    sort(p+1,p+1+n);
    sort(b+1,b+1+m);
    top=0;
    sta[++top]=make_pair(0x3f3f3f3f,b[1]);
    int cur=2;
    for(int i=1;i<=n;++i){
        while(cur<=m&&b[cur]<=p[i].r){
            while(top&&sta[top].first<=b[cur]-b[cur-1])--top;
            sta[++top]=make_pair(b[cur]-b[cur-1],b[cur]);
            cur++;
        }
        if(p[i].r<=b[1]||p[i].l>=b[m]||(cur<=m&&p[i].l>=b[cur-1]&&p[i].r<=b[cur])){ // in current gap or in begin and end
            p[i].res=0;
            continue;
        }
        int lenn=p[i].r-p[i].l;
        int l=1,r=top,ans=1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(sta[mid].first>=lenn)ans=mid,l=mid+1;
            else r=mid-1;
        }
        int tarrpos=sta[ans].second;
        p[i].res=min(p[i].res,abs(tarrpos-p[i].r));
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d%d",&p[i].l,&p[i].r);
    for(int i=1;i<=m;++i)scanf("%d",&b[i]);
    solve();
    for(int i=1;i<=n;++i)swap(p[i].l,p[i].r),p[i].l=-p[i].l,p[i].r=-p[i].r;
    for(int i=1;i<=m;++i)b[i]=-b[i];
    solve();
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=p[i].res;
    printf("%lld\n",ans);
}