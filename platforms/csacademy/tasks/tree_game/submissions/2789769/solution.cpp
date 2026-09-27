#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5 + 5;
int n, hd[mxn], nex[mxn << 1], to[mxn << 1], tot;

void add_edge(int u, int v) {
	nex[++ tot] = hd[u];
	hd[u] = tot;
	to[tot] = v;
}

int dp[mxn][3];

void dfs(int u, int p) {
	vector <int> son;
	for (int e = hd[u]; e; e = nex[e]) {
		int v = to[e];
		if (v == p) continue;
		dfs(v, u);
		son.pb(v);
	}
	rep(i, son.size()) {
		int v = son[i];
		dp[u][0] += dp[v][0];
		dp[u][1] += max(dp[v][0], 1 + dp[v][2]);
	}
	int temp[2][3];
	memset(temp, -0x3f, sizeof(temp));
	int P = 0, Q = 1;
	temp[P][0] = 0;
	rep(i, son.size()) {
		int v = son[i];
		rep(j, 3) {
			temp[Q][j] = max(temp[Q][j], temp[P][j] + dp[v][0]);
			temp[Q][min(2, j + 1)] = max(temp[Q][min(2, j + 1)], temp[P][j] + max(dp[v][1], dp[v][2]));
		}
		swap(P, Q);
		memset(temp[Q], -0x3f, sizeof(temp[Q]));
	}
	dp[u][0] = max(dp[u][0], max(temp[P][0], 1 + temp[P][2]));
	dp[u][2] = temp[P][1];
}

int main() {
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u; -- v;
		add_edge(u, v);
		add_edge(v, u);
	}
	dfs(0, -1);
	printf("%d\n", max(dp[0][0], dp[0][1]));
	return 0;
}
