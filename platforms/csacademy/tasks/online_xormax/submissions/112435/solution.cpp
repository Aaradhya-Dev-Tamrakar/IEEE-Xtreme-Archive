#include <bits/stdc++.h>
      
#define FOR(i,a,b) for( ll i = (a); i < (ll)(b); i++ )
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort( (x).begin(),(x).end() )
#define REVERSE(x) reverse( (x).begin(),(x).end() )
#define UNIQUE(x) (x).erase( unique( ALL( (x) ) ) , (x).end() )
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())
#define SHOW(x) cout << #x << " = " << x << endl
#define SHOWA(x,n) for( int yui = 0; yui < n; yui++ ){ cout << x[yui] << " "; } cout << endl

#define pb emplace_back
#define fi first
#define se second

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vpl> gr;
typedef vector<vl> ml;
typedef vector<vd> md;
typedef vector<vi> mi;
     
const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ld EPS = 1e-12;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> inline T sq( T a ){ return a * a; }

ll in(){ long long int x; scanf( "%lld" , &x ); return x; }
char yuyushiki[1000010]; string stin(){ scanf( "%s" , yuyushiki ); return yuyushiki; }

// head

int n;
int a[200010];

int id[200010];
set<int> en;

multiset<int> ss;

int tid[200010];

int l[200010];
int r[200010];

int q[200010];

int G[200010][2];

int dp[200010];

int sum[200010];

int trie[20000000][2];

int it;



void append( int t , int x ){
  REP( i , 30 ){
    int cx = 0;
    if( x & PW(29-i) ){
      cx = 1;
    }
    if( trie[t][cx] == 0 ){
      trie[t][cx] = it++;
    }
    t = trie[t][cx];
  }
}

int calc( int t , int x ){
  REP( i , 30 ){
    int cx = 0;
    if( x & PW(29-i) ){
      cx = 1;
    }
    if( trie[t][1-cx] != 0 ){
      t = trie[t][1-cx];
      if( cx == 0 ){
	x = x ^ PW(29-i) ;
      }
    } else {
      t = trie[t][cx];
      if( cx == 1 ){
	x = x ^ PW(29-i);
      }
    }
  }
  return x;
}

int cnt = 0;

void dfs( int x ){
  if( l[x] == r[x] ){
    dp[x] = 0;
    tid[x] = it++;
    append( tid[x] , sum[ l[x] ] );
    return;
  }

  int a = G[x][0];
  int b = G[x][1];
  
  //cout << x << " " << l[x] << " " << r[x] << " " << a << " " << b << endl;

  if( r[a] - l[a] > r[b] - l[b] ){
    swap( a , b );
  }

  dfs( b );  

  int st = it;
  
  dfs( a );

  FOR( i , st , it ){
    trie[i][0] = trie[i][1] = 0;
  }
  it = st;
  
  dp[x] = max( dp[a] , dp[b] );  

  tid[x] = tid[b];
  FOR( i , l[a] , r[a] + 1 ){
    chmax( dp[x] , calc( tid[x] , sum[i] ) );
  }

  FOR( i , l[a] , r[a] + 1 ){
    append( tid[x] , sum[i] );
  }
  
  // cout << x << " " << dp[x] << endl;
}

int main(){
  
  n = in();
  REP( i , n ){
    a[i] = in();
  }

  REP( i , n ){
    sum[i+1] = sum[i] ^ a[i];
  }

  en.insert( n );
  id[n] = 0;
  l[0] = 0;
  r[0] = n;


  it = 1;
  REP( i , n ){
    int p = in() - 1;
    int x = *en.lower_bound( p );

    q[i] = id[x];

    G[ id[x] ][0] = it;
    l[it] = l[ id[x] ];
    r[it] = p;
    id[p] = it;
    it++;
    
    G[ id[x] ][1] = it;
    l[it] = p + 1;
    r[it] = x;
    id[x] = it;
    it++;
    
    en.insert( p );
  }


  en.clear();
  
  it = 1;
  
  dfs( 0 );

  ss.insert( dp[0] );
  REP( i , n ){
    int ans = *ss.rbegin();
    printf( "%d\n" , ans );

    ss.erase( ss.find( dp[ q[i] ] ) );
    ss.insert( dp[ G[ q[i] ][0] ] );
    ss.insert( dp[ G[ q[i] ][1] ] );
  }

  return 0;
}
