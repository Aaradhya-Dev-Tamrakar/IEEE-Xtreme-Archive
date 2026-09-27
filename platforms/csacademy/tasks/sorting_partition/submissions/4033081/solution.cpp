#include<bits/stdc++.h>
using LL=long long;
#define INF 0x7fffffff

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin>>n;
    std::vector<int> a(n+1),minn(n+2);
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    minn[n+1]=INF;
    for(int i=n;i>=1;i--){
        minn[i]=std::min(minn[i+1],a[i]);
    }
    int maxx=0,ans=0;
    for(int i=1;i<=n;i++){
        maxx=std::max(maxx,a[i]);
        if(maxx<=minn[i+1]){
            maxx=0;
            ans++;
        }
    }
    std::cout<<ans;
    return 0;
}
