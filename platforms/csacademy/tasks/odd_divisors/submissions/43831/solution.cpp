#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int T;

ll solve(int l, int r) {
  if(l > r)
    return 0;
  ll i = l%2? l : l+1, j = r%2? r : r-1;
  i = (i+1)/2 - 1, j = (j+1)/2;
  return j*j - i*i + solve((l+1)/2, r/2);
}

int main() {
  //freopen("A.in", "r", stdin);
  scanf("%d", &T);
  for(int l, r; T--; ) {
    scanf("%d%d", &l, &r);
    printf("%lld\n", solve(l, r));
  }
}