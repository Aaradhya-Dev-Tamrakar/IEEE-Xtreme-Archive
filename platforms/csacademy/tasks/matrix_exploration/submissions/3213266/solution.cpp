#include <bits/stdc++.h>
using namespace std;

int dis[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++){
            if(s[j - 1] == '#'){
                dis[i][j] = -1;
            }
            else{
                dis[i][j] = 0;
            }
        }
    }
    queue<pair<int,int> > q;
    for(int x, y, i = 0; i < k; i++){
        cin >> x >> y;
        q.push({x, y});
        dis[x][y] = -1;
    }
    int w[4][2] = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        int x = tmp.first, y = tmp.second;
        for(int i = 0; i < 4; i++){
            int xx = x + w[i][0], yy = y + w[i][1];
            if(xx > 0 && xx <= n && yy > 0 && yy <= m && dis[xx][yy] == 0){
                if(dis[x][y] == -1) 
                    dis[xx][yy] = 1;
                else
                    dis[xx][yy] = dis[x][y] + 1;
                q.push({xx, yy});
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            ans += dis[i][j] == -1 ? 0 : dis[i][j];
        }
    }
    cout << ans << endl;
    return 0;
}