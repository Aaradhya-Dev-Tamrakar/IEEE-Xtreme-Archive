#include <bits/stdc++.h>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))
#define bits(a) __builtin_popcount(a)

using namespace std;

char s[100005];

int main()
{
  //freopen("game.in", "r", stdin);
  //freopen("game.out", "w", stdout);
  int n;
  cin >> n;
  scanf("%s", s);
  int c1 = 0, c2 = 0, tmp = 0;
  for(int i=0;i<n;i++)
    if(s[i] == 'A')
      c1++;
  for(int i=0;i<n;i++)
  {
    if(s[i] != s[i - 1])
    {
      if(s[i - 1] == 'B')
        tmp ^= c2;
      c2 = 0;
    }
    c2++;
  }
  if(s[n - 1] == 'B') tmp ^= c2;
  if(tmp == 0)
  {
    if(c1 % 2 == 0) cout << -1;
    else cout << "B";
  }
  else
  {
    if(c1 % 2 == 0) cout << -1;
    else cout << "A";
  }
  return 0;
}
