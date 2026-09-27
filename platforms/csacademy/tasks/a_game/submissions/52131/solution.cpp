#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//#include <sys/resource.h>
using namespace std;
using namespace __gnu_pbds;
 
#define mod 1000000007
 
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<pair<int,int> > > vvpii;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

 
#ifdef amit
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T,U>& a){out<<"["<<a.first<<" "<<a.second<<"]";return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a){out<<"[ ";for(auto &it:a)out<<it<<" ";out<<"]";return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a){out<<"[ ";for(auto &it:a)out<<it<<" ";out<<"]";return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a){out<<"[ ";for(auto &it:a)out<<it<<" ";out<<"]";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const map<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
template<class T,class U>
ostream& operator<<(ostream& out, const multimap<T,U>& a){for(auto &it:a)out<<it.first<<" -> "<<it.second<<" | ";return out;}
#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<=n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<=n;++i){for(int j=0;j<=m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define prl() cerr<<__LINE__ << ": "<<__PRETTY_FUNCTION__<<endl;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
} 
#define gc getchar
#else
#define pr(...)
#define pra(a,n)
#define praa(a,n,m)
#define prl()
#define gc getchar_unlocked
#endif

#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define sz(a) int((a).size()) 
#define all(a) (a).begin(),(a).end()
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define rev(i,n,s)  for(int i=(n);i>=s;--i)
#define fore(x,a) for(auto&& x: a)
#define fill(a,x) memset((a),(x),sizeof(a))
const double eps = 1e-6;
#define tcase int __T;cin>>__T;rep(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)
#define endl '\n'
inline int add(int a,int b, int m=mod){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=mod){return (int)(((ll)a*(ll)b)%m);}
#define N 100005

int main() {
	boost;
  int tot = 0;
  int n;
  cin>>n;
  string s;
  cin>>s;
  rep(i,0,n-1) {
    if(s[i]=='A') tot++;
  }
  if(tot&1) {
    int cur = 0;
    tot = 0;
    rep(i,0,n-1) {
      if(s[i]=='B') {
        tot++;
      }
      else {
        cur ^= tot;
        tot = 0;
      }
    }
    cur ^= tot;
    if(cur) cout<<"A"<<endl;
    else cout<<"B"<<endl;
  }
  else {
    cout<<-1<<endl;
  }
  
	return 0;
}