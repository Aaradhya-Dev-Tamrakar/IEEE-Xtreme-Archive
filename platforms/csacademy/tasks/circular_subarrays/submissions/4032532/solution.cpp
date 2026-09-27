#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second 
#define pb push_back
#define pp pop_back
#define debug(x) cout << #x << " is "<< x << "\n";
#define vi vector<int>
#define vll vector<long long>
#define vld vector<long double>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mk make_pair
#define read(v,n) for(int i=0;i<n;i++) cin >> v[i]
#define out(n); cout << n << '\n'
#define debugarray(v) cout << "DEBUG: ";for(int i=0;i<v.size();i++) cout << v[i] << " ";cout << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll binomialCoeff(ll n, ll r) {
    if (n < r) return 0;
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    ll i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
    return ans;
}
 
// A utility function to return
// minimum of two integers
ll min(ll a,ll b) { return (a < b) ? a : b; }
ll max(ll a,ll b) { return (a > b) ? a : b; }

ll pcm(ll a, ll b){
	return (a*b)/ __gcd(a,b);
}

void BFS(vll adjList[], vll v,ll m, ll x, vector<bool>& visited){
	queue<pair<ll, ll> > q;
	q.push(mk(x,v[x]));
	ll ans = 0;
	while(!q.empty()){
		pair<ll,ll> p = q.front();
		q.pop();
		visited[p.fi] = true;
		if(p.se>m) continue;
		bool test = true;
		for(int i=0;i<adjList[p.fi].size();i++){
			if(!visited[adjList[p.fi][i]])
			{
				test = false;
				q.push(mk(adjList[p.fi][i],(v[adjList[p.fi][i]])? p.se + v[adjList[p.fi][i]]:0));		
			}			
		}
		if(test) ans++;
	}
	cout << ans << "\n";
}

ll power(ll a, ll b){
	ll res = 1;
	while(b>0){
		if(b&1) res *= a;
		a *= a;
		b = b >> 1;
	}
	return res;
}

void DFS(vll adjList[], ll x, vector<bool>& visited){
	if(!visited[x]){
		visited[x] = true;
		for(int i=0;i<adjList[x].size();i++)
			DFS(adjList,adjList[x][i],visited);
	}
}

ll xPos[4] = {1,0,-1,0};
ll yPos[4] = {0,1,0,-1};

void BFS3(vector<ll> v, ll node,vector<bool>& visited,set<ll> s,bool& mul){
	queue<ll> q;
	q.push(node);
	while(!q.empty()){
		ll p = q.front();
		q.pop();
		visited[p] = true;
		if(s.count(p)) mul = false;
		if(!visited[v[p]]) q.push(v[p]);
	}	
}

void dfs(int v, ll depth,vector<ll> adj[], vector<ll> &array, vector<bool> &visited) {
    visited[v] = true;
    array[depth]++;
    for (int i = 0;i<adj[v].size();i++) {
        if (!visited[adj[v][i]])
            dfs(adj[v][i],depth+1,adj,array,visited);
    }
}


bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
	return (a.se < b.se);
}


const ll MAX=1e10+1;
const ll MOD=1e9+7;

ll fact(ll n){
	if(n==1) return 1;
	return fact(n-1) * n % MOD;
}

vector<ll> GetC(vector<ll> v1,vector<ll> v2){
	vll v(v1.size());
	for(int i=0;i<v1.size();i++){
		if(v1[i]==v2[i]) v[i] = v1[i];
		else v[i] = 3 - (v1[i]+v2[i]);
	}
	return v;
}

map<char,ll> m;

bool func(string a, string b){
	ll i = 0;
	while(a[i]==b[i]&&i<min(a.size(),b.size())) i++;
	if(i==min(a.size(),b.size())) return a.size()<b.size();
	else return m[a[i]] < m[b[i]];
}

const ll N = 1e6+5;

bool vis[N];

void solve(){
	ll n,k;
	cin >> n >> k;
	vll v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	ll ans = 0;
	for(int i=0;i<k;i++){
		if(vis[i]) continue;
		vll sorted;
		ll j = i;
		while(!vis[j]){
			sorted.pb(v[j]);
			vis[j] = true;
			j = (j + k) % n;
		}
		sort(sorted.begin(),sorted.end());
		ll pos = sorted.size()/2;
		for(auto item : sorted){
			ans += abs(item - sorted[pos]);
		}
	}
	cout << ans << '\n';
} 
int main(){
	fastio
	ll t=1;
	//cin >> t;
	while(t--) solve();
	return 0;
}