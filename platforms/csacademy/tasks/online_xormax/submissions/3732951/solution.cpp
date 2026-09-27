#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
#include <list>
#include <map>
#include <iostream>
#include <iomanip>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <time.h>
#include <unordered_map>
#include <utility>
#include <vector>

 
#define F first
#define S second
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define mem(x,i) memset((x),(i),sizeof((x)))
 
using namespace std;
//using namespace __gnu_pbds;
using pii = pair<long long,long long>;
using ld = long double;
using ll = long long;
 
const int N = 1e5+10;

int mx;
int cnt;
int node[350*N][2];

int n;
int a[N], q[N], ans[N];
bitset<N>ok;

struct Trie{
	int l,r,rt;
	void init(int _p){
		l = r = _p;
		node[cnt][0] = node[cnt][1] = -1;
		rt = cnt++;
		ins(a[_p]);
		ins(a[_p-1]);
		query(a[_p-1]);
	}
	void ins(int val){
		int now = rt;
		for(int i=30;i>=0;i--){
			int v = (val>>i)&1;
			if(node[now][v]==-1){
				if(i){
					node[cnt][0] = node[cnt][1] = -1;
					node[now][v] = cnt;
					cnt++;
				}
				else
					node[now][v] = 0;
			}
			now = node[now][v];
		}
	}
	void query(int val){
		int now = rt, res = 0;
		for(int i=30;i>=0;i--){
			int v = (val>>i)&1;
			if(node[now][v^1]!=-1){
				res += (1<<i);
				now = node[now][v^1];
			}
			else
				now = node[now][v];
		}
		mx = max(mx, res);
	}
}tr[N];

struct DSU{
	vector<int>p, sz;
	void init(int n){
		p.resize(n+1,-1);
		sz.resize(n+1,1);
	}
	int fp(int x){
		return (p[x]==-1 ? x : p[x]=fp(p[x]));
	}
	void U(int x,int y){
		x = fp(x);
		y = fp(y);
		if(x==y)
			return;
		if(sz[x]>sz[y])
			swap(x,y);
		p[x] = y;
		for(int i=tr[x].l-1;i<=tr[x].r;i++)
			tr[y].ins(a[i]), tr[y].query(a[i]);
		sz[y] += sz[x];
		tr[y].l = min(tr[y].l, tr[x].l);
		tr[y].r = max(tr[y].r, tr[x].r);
	}
}dsu;

void solve(){
	cin >> n;
	dsu.init(n);
	for(int i=1;i<=n;i++)
		cin >> a[i], a[i] ^= a[i-1];
	for(int i=0;i<n;i++)
		cin >> q[i];
	for(int i=n-1;i>=0;i--){
		int x = q[i];
		tr[x].init(x);
		for(auto j:{x-1, x+1})
			if(ok[j])
				dsu.U(j,x);
		ans[i] = mx;
		ok[x] = 1;
	}
	for(int i=0;i<n;i++)
		cout << ans[i] << '\n';
	assert(cnt<N*350);
}	
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin >> t;
	while(t--)
		solve();
}

