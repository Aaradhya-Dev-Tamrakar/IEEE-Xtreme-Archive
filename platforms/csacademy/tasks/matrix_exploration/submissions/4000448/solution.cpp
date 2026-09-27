#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

int main() {

  int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int M, N, K;

  cin >> M >> N >> K;

  vector<vector<bool>> save(M, vector<bool>(N, false));

  vector<vector<bool>> visited(M, vector<bool>(N, false));

  for (int i = 0; i < M; ++i) {

    string temp;

    cin >> temp;

    for (int j = 0; j < N; ++j) {

      if (temp[j] == '.')
        save[i][j] = true;
    }
  }

  queue<pair<int, int>> qu;

  for (int k = 0; k < K; ++k) {

    int x, y;

    cin >> x >> y;

    qu.push({x - 1, y - 1});

    visited[x - 1][y - 1] = true;
  }

  int res = 0, cur = 0;

  while (!qu.empty()) {

    int sz = qu.size();

    for (int i = 0; i < sz; ++i) {

      res += cur;

      pair<int, int> t = qu.front();

      qu.pop();

      for (int d = 0; d < 4; ++d) {

        int nx = t.first + dir[d][0], ny = t.second + dir[d][1];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] &&
            save[nx][ny]) {

          qu.push({nx, ny});

          visited[nx][ny] = true;
        }
      }
    }

    cur++;
  }

  cout << res;

  return 0;
}