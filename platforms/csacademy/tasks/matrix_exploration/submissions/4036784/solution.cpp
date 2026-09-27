#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> distances;

    queue<pair<int, int>> visitNext;

    for (int i = 0; i < N; ++i) {
        string line;
        cin >> line;
        distances.emplace_back();
        for (int j = 0; j < M; ++j) {
            bool empty = line[j] == '.';
            distances.back().push_back(empty ? -1 : 0);
        }
    }

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        distances[x-1][y-1] = 0;
        visitNext.emplace(x-1, y-1);
    }

    while (!visitNext.empty()) {
        int x = visitNext.front().first;
        int y = visitNext.front().second;
        int d = distances[x][y] + 1;
        visitNext.pop();
        for (int i = -1; i < 2; i += 2) {
            int yi = y + i;
            int xi = x + i;
            if (yi < M && yi >= 0 && distances[x][yi] == -1) {
                distances[x][yi] = d;
                visitNext.emplace(x, yi);
            }
            if (xi < N && xi >= 0 && distances[xi][y] == -1) {
                distances[xi][y] = d;
                visitNext.emplace(xi, y);
            }
        }
    }

    int distanceTot = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            distanceTot += distances[i][j];
        }
    }

    cout << distanceTot;
    return 0;
}