#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K, a, b, first = 1;

    cin >> N >> M >> K;
    vector<pair<int, int>> swaps;
    swaps.reserve(M);

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        swaps.push_back(pair(a, b));
    }

    pair<int, int> aux = swaps[0];
    int no = 0; // num of pair to be skipped

    swaps[0].first = swaps[0].second = 0;

    while (no < M)
    {
        for (pair p : swaps)
            if (p.first == first)
                first = p.second;
            else if (p.second == first)
                first = p.first;

        if (first == K)
            break;

        swaps[no++] = aux;

        first = 1;

        aux = swaps[no];
        swaps[no].first = swaps[no].second = 0;
    }

    cout << ++no << "\n";
    // if (!sols.empty())
    //     cout << *min_element(sols.begin(), sols.end()) << "\n";

    return 0;
}