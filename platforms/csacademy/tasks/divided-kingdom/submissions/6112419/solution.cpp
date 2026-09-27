#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> P;

const int N = 2.5e5 + 5;
int flag[N];
int l, r, mid;
int bj, n, m, ans;
vector <int> edge[N];
int cmax[N], maxx[N];
struct node{ int u, v, w; } arr[N];

void dfs(int u)
{
	int i;
	
	for(i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if(flag[v] == flag[u]) bj = 1;
		if(flag[v] != -1) continue;
		flag[v] = flag[u] ^ 1;
		dfs(v);
	}
}

bool check()
{
	int i;
	memset(flag, -1, sizeof flag);
	
	for(i = 1; i <= n; i++)
		edge[i].clear();
	
	for(i = 1; i <= m; i++)
	{
		if(arr[i].w < mid)
		{
			edge[arr[i].u].push_back(arr[i].v);
			edge[arr[i].v].push_back(arr[i].u);
		}
		else
			break;
	}
	
	for(i = 1; i <= n; i++)
	{
		if(flag[i] == -1)
		{
			bj = 0;
			flag[i] = 0;
			dfs(i);
			if(bj == 1) return 0; 
		} 
	}
	
	return 1;
}

bool cmp(node X, node Y)
{
	return X.w < Y.w;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	int i;
	cin >> n >> m;
	
	if(n <= 2)
	{
		cout << -1;
		return 0;
	}
	
	for(i = 1; i <= m; i++)
		cin >> arr[i].u >> arr[i].v >> arr[i].w;
	
	sort(arr + 1, arr + m + 1, cmp);
	ans = 1e18;
	l = 1, r = 1e6 + 1;
	
	while(l <= r)
	{
		mid = (l + r) >> 1;
		
		if(check())
		{
			l = mid + 1;
			ans = mid;
		}
		else
			r = mid - 1;
	}
	
	for(i = 1; i <= n; i++)
		cmax[i] = maxx[i] = 1e18;
	
	for(i = 1; i <= m; i++)
	{
		int w = arr[i].w, u;

		u = arr[i].u;
		if(maxx[u] > w)
		{
			cmax[u] = maxx[u];
			maxx[u] = w;
		}
		else if(cmax[u] > w)
			cmax[u] = w;
		u = arr[i].v;
		if(maxx[u] > w)
		{
			cmax[u] = maxx[u];
			maxx[u] = w;
		}
		else if(cmax[u] > w)
			cmax[u] = w;
	}
	
	for(i = 1; i <= n; i++)
		ans = min(ans, cmax[i] + maxx[i]);
	
	if(ans >= 1e6 + 1)
		cout << -1;
	else
		cout << ans;
	return 0;
}/////////////////