#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int len = 55;
int n;
ll dp[len][2];
char str[len];

ll solve(int i, int t){
    if (i == n) return 0;
    if (dp[i][t] != -1) return dp[i][t];
    
    ll ans = 0;
    if (t == 0){
        if (str[i] == '0')
            ans = solve(i+1, 0);
        else
            ans = (1LL<<(n-i-1)) + solve(i+1, 1);
    }
    else{
        if (str[i] == '0')
            ans = (1LL<<(n-i-1)) + solve(i+1, 1);
        else
            ans = solve(i+1, 0);
    }
    
    //printf("(%d, %d) = %lld\n", i, t, ans);
    return dp[i][t] = ans;
}

int main() {
    scanf("%s", &str);
    n = strlen(str);
    
    for (int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = -1;
        
    printf("%lld\n", solve(0, 0));
    return 0;
}
