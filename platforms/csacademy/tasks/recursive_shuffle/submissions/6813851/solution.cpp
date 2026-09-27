#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int64 N;
    int M;
    if(!(cin>>N>>M)) return 0;
    vector<int64> u(M), p(M);
    for(int i=0;i<M;i++) cin>>u[i];
    for(int i=0;i<M;i++){
        int64 x = u[i];
        int64 n = N;
        int64 offset = 0;
        while(n>1){
            int64 k = n/2;
            if((x & 1LL) == 0){
                x = x/2;
                n = k;
            } else {
                x = (x+1)/2;
                offset += k;
                n = n - k;
            }
        }
        p[i] = offset + 1;
    }
    for(int i=1;i<M;i++){
        if(p[i] != p[i-1] + 1){
            cout<<0<<"\n";
            return 0;
        }
    }
    if(p[0] < 1 || p[0] > N - M + 1) {
        cout<<0<<"\n";
        return 0;
    }
    cout<<1<<"\n";
    return 0;
}