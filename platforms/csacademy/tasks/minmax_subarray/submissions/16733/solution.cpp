#include <bits/stdc++.h>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

const int MAXN = 5003;

int N, A[MAXN], mini, maxi;


int main(){
	ri(N);
	FOR(i,0,N) ri(A[i]);
	mini = *min_element(A, A+N), maxi = *max_element(A, A+N);
	int maxi_i = -1e8, mini_i = 1e8, ans = 1e8;
	FOR(i,0,N){
	    if(A[i]==maxi) maxi_i = i;
	    if(A[i]==mini) mini_i = i;
	    ans = min(ans, 1 + max(mini_i, maxi_i) - min(mini_i, maxi_i));
	}
	printf("%d\n",ans);
}
