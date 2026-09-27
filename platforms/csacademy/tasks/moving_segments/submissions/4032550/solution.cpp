#include <bits/stdc++.h>
using namespace std;
int n, l[111111], r[111111], s[222222];
int main(){
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d%d", l+i, r+i);
        s[i*2] = l[i];
        s[i*2+1] = r[i];
    }
    nth_element(s, s+n, s+2*n);
    int t = s[n];
    long long ans = 0;
    for(int i=0; i<n; ++i)
        if(r[i]<t) ans += (t-r[i]);
        else if(l[i]>t) ans += (l[i]-t);
    cout << ans << endl;
    return 0;
}