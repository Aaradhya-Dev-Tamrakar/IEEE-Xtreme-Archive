#include <bits/stdc++.h>

using namespace std;
const int nmax = 100005;
int N,a[nmax],lvl[nmax];
long long ans,sol;
vector < int > L[nmax];

inline void Read()
{
      int i,n1,n2;
      char x;
      cin >> N;
      for(i = 1; i <= N; ++i)
      {
            cin >>x;
            if(x == 'B') a[i] = 1;
            else a[i] = 0;
      }
      for(i = 1; i < N; i++)
      {
            cin >> n1 >> n2;
            L[n1].push_back(n2);
            L[n2].push_back(n1);
      }
}

inline void DFS(int nod, int tata)
{
      lvl[nod] = 1 - lvl[tata];
      for(auto it : L[nod])
      {
            if(it == tata) continue;
            DFS(it,nod);
      }
}

inline pair < long long, long long > DFS2(int nod, int tata, int flag)
{
      pair < long long, long long > P,son;
      long long r,b;
      r = b = 0;
      if(flag == 1)
      {
            if(lvl[nod] && !a[nod]) r++;
            else if(!lvl[nod] && a[nod]) b++;
      }
      else 
      {
            if(lvl[nod] && a[nod]) r++;
            else if(!lvl[nod] && !a[nod]) b++;
      }
      for(auto it : L[nod])
      {
            if(it == tata) continue;
            son = DFS2(it,nod,flag);
            r += son.first;
            b += son.second;
      }
      if(r > b) 
      {
            r -= b;
            b = 0;
      }
      else 
      {
            b -= r;
            r = 0;
      }
      sol = sol + b + r;
      P.first = r; P.second = b;
      return P;
}

inline void Solve()
{
      ans = -1;
      pair < long long, long long> P,I;
      DFS(1,0);
      P = DFS2(1,0,1);
      if(P.first > 0 || P.second > 0);
      else ans = sol;
      sol = 0;
      I = DFS2(1,0,0);
      if(I.first > 0 || I.second > 0) ;
      else if(ans == -1) ans = sol;
      else ans = min(sol,ans);
      cout << ans << "\n";
}

int main() {
    Read();
    Solve();
    return 0;
}