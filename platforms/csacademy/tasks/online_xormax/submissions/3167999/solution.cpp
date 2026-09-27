// Knapsack DP is harder than FFT.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int,int> pii; typedef pair<ll,ll> pll;
#define ff first
#define ss second
#define pb emplace_back
#define AI(x) begin(x),end(x)
template<class I>bool chmax(I&a,I b){return a<b?(a=b,true):false;}
template<class I>bool chmin(I&a,I b){return b<a?(a=b,true):false;} 
#ifdef OWO
#define debug(args...) SDF(#args, args)
#define OIU(args...) ostream& operator<<(ostream&O,args)
#define LKJ(S,B,E,F) template<class...T>OIU(S<T...>s){O<<B;int c=0;for(auto i:s)O<<(c++?", ":"")<<F;return O<<E;}
LKJ(vector,'[',']',i)LKJ(deque,'[',']',i)LKJ(set,'{','}',i)LKJ(multiset,'{','}',i)LKJ(unordered_set,'{','}',i)LKJ(map,'{','}',i.ff<<':'<<i.ss)LKJ(unordered_map,'{','}',i.ff<<':'<<i.ss)
template<class...T>void SDF(const char* s,T...a){int c=sizeof...(T);if(!c){cerr<<"\033[1;32mvoid\033[0m\n";return;}(cerr<<"\033[1;32m("<<s<<") = (",...,(cerr<<a<<(--c?", ":")\033[0m\n")));}
template<class T,size_t N>OIU(array<T,N>a){return O<<vector<T>(AI(a));}template<class...T>OIU(pair<T...>p){return O<<'('<<p.ff<<','<<p.ss<<')';}template<class...T>OIU(tuple<T...>t){return O<<'(',apply([&O](T...s){int c=0;(...,(O<<(c++?", ":"")<<s));},t),O<<')';}
#else
#pragma GCC optimize("Ofast")
#define debug(...) ((void)0)
#endif

const int kN = 100005;
const int kL = 30;
const int kM = kN * kL * 17;

int N, a[kN], b[kN];
int nd[kM][2], tot;
int ok[kN], ans[kN], mxv;

struct TRI {
	int rt, l, r;
	TRI(int p = 0): rt(0), l(kN), r(0) { if(p != 0){ rt = ++tot; ins(p, p); } }
	void M(TRI &oth){ ins(oth.l, oth.r); }
	void ins(int ql, int qr){
		for(int i = ql-1; i <= qr; ++i) ins(a[i]);
		chmin(l, ql); chmax(r, qr);
	}
	void ins(int v){
		int u = rt;
		for(int i, l = kL - 1; l >= 0; --l){
			i = (v >> l) & 1;
			if(nd[u][i] == 0) nd[u][i] = ++tot;
			u = nd[u][i];
		}
		int res = 0; u = rt;
		for(int i, l = kL - 1; l >= 0; --l){
			i = (v >> l) & 1;
			if(nd[u][i^1] == 0) u = nd[u][i];
			else res |= (1<<l), u = nd[u][i^1];
		}
		chmax(mxv, res);
	}
};

struct DSU {
	int n; vector<int> f, s; vector<TRI> t;
	void init(int nn){
		n = nn;
		f.resize(n + 1); iota(AI(f), 0);
		s.assign(n + 1, 1);
		t.resize(n + 1);
	}
	void A(int p){ t[p] = TRI(p); }
	int F(int a){ return a == f[a] ? a : f[a] = F(f[a]); }
	int M(int a, int b){
		a = F(a), b = F(b);
		if(a == b) return false;
		if(s[a] < s[b]) swap(a, b);
		f[b] = a;
		s[a] += s[b];
		t[a].M(t[b]);
		return true;
	}
} dsu;

signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	for(int i = 1; i <= N; ++i) cin >> a[i];
	for(int i = N; i >= 1; --i) cin >> b[i];
	for(int i = 1; i <= N; ++i) a[i] xor_eq a[i-1];

	dsu.init(N);
	for(int u, i = 1; i <= N; ++i){
		u = b[i]; ok[u] = true;
		dsu.A(u);
		for(int v: {u-1, u+1})
			if(ok[v]) dsu.M(u, v);
		ans[i] = mxv;
	}

	for(int i = N; i >= 1; --i) cout << ans[i] << '\n';
	
	return 0;
}
