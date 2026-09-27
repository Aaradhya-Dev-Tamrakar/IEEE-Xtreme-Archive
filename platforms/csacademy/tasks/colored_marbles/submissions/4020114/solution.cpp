#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int const N = 1e5 + 5;
LL a[N];
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        LL ans = 0;
        bool one = 0;
        int not_zro = 0;
        for(int i = 0; i < n; i++){
            int j = i;
            while(j + 1 < n && a[j + 1] == a[i]){
                j++;
            }
            LL len = j - i + 1;
            if(len % a[i] == 1 && !one){
                one = 1;
                ans -= a[i];
            }
            if(len % a[i] > 0){
                not_zro++;
            }
            ans += ((len + a[i] - 1) / a[i]) * a[i];
            i = j;
        }
        if(one && not_zro < 2)
            ans++;
        if(!not_zro)
            ans++;
        if(!one && a[n - 1] == 1 && not_zro){
            ans--;
        }
        cout << ans << '\n';
    }
}