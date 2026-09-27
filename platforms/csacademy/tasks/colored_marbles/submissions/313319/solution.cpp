#include<cstdio>
#include<algorithm>
#define N 100000
using namespace std;

int v[N+1];
int cnt[N+1];

int main(){
    int n,i,j,t;
    long long s;
    bool flag;

    scanf ("%d",&t);
    for(;t>0;t--){
        scanf ("%d",&n);
        for(i=1;i<=n;i++)
            scanf ("%d",&v[i]);

        sort(v+1,v+n+1);
    
        flag=(v[1]==1);
        
        j=1;
        cnt[j]=1;
        s=0;
        for(i=2;i<=n;i++){
            if (v[i]==v[i-1]) cnt[j]++;
            else {
                s=s+(cnt[j]/v[j])*v[j];
                cnt[j]%=v[j];
                if (cnt[j]==0) j--;
                else s+=v[j];
                j++;
                v[j]=v[i];
                cnt[j]=1;
            }
        }

        n=j;
        s=s+(cnt[n]/v[n])*v[n];
        cnt[n]%=v[n];
        if (cnt[n]==0) n--;
        else s+=v[n];

        if (n==0) s++;
        else
        if (n==1){
            if (cnt[n]==1) s=s-v[n]+1;
            else
            if (flag==true) s--;
            else s++;
        }
        else {
            i=n;
            while(i>0 &&cnt[i]!=1) i--;

            if (i!=0) s-=v[i];
            else
            if (flag==true) s--;
        }

        printf ("%lld\n",s);
    }

    return 0;
}
