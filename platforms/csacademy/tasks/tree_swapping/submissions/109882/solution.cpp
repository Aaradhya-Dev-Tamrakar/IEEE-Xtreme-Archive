//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const long long INFLL = (1LL << 62);

char color[1 + MAXN], good[1 + MAXN];
vector<int> g[1 + MAXN];

void FixColors(int node, int father) {
    good[node] = 'R' + 'B' - good[father];
    for (auto &son : g[node])
        if (son != father)
            FixColors(son, node);
}

int notGood[1 + MAXN];
long long dp[1 + MAXN];

void DFS(int node, int father) {
    for (auto &son : g[node])
        if (son != father) {
            DFS(son, node);
            dp[node] = dp[node] + dp[son] + abs(notGood[son]);
            notGood[node] += notGood[son];
        }
    if (color[node] == 'R' && good[node] == 'B')
        notGood[node]++;
    if (color[node] == 'B' && good[node] == 'R')
        notGood[node]--;
}

long long Try() {
    DFS(1, 0);
    if (notGood[1])
        return INFLL;
    return dp[1];
}

int main() {
    int n;
    cin >> n >> color + 1;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    good[0] = 'B';
    FixColors(1, 0);
    long long first = Try();
    for (int i = 1; i <= n; i++)
        good[i] = 'B' + 'R' - good[i];
    memset(dp, 0, sizeof(dp));
    memset(notGood, 0, sizeof(notGood));
    long long second = Try();
    long long answer = min(first, second);
    if (answer == INFLL) {
        cout << "-1\n";
        return 0;
    }
    cout << answer << "\n";
    return 0;
}
