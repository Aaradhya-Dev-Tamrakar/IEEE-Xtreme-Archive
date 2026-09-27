#include <bits/stdc++.h>
using namespace std;
#define lp(i,n) for (int i = 0; i < int(n); ++i)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
typedef double dbl;
const int inf = 1e9+7;
const int llinf = 1e18+7;
const dbl eps = 1e-12;
const int N = 1e5+10;
char a[N];
int main() {
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    int As = 0;
    vector<int> lens;
    lp(i,n){
        if(a[i] == 'B'){
            lens.push_back(0);
            while(i < n && a[i] == 'B')lens.back()++,i++;
            --i;
        }else As++;
    }
//    eprintf("%d\n",As);
    if(As %2 == 0)puts("-1");
    else{
        int res = 0;    
        for (int x:lens)res ^= x;
        if(res == 0)puts("B");
        else puts("A");
    }
    
}