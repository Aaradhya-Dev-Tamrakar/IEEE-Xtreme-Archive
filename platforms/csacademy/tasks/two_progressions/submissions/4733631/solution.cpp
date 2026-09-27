/**
 _  _   __  _ _ _  _  _ _
 |a  ||t  ||o    d | |o  |
| __    _| | _ | __|  _ |
| __ |/_  | __  /__\ / _\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100000;

int N;
int A[N_MAX + 2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        int suff = 2;
        while (suff < N && A[N - suff + 1] - A[N - suff] == A[N] - A[N - 1]) {
            suff++;
        }
        tuple <int, int, int> answer = make_tuple(INT_MAX, INT_MAX, INT_MAX);
        vector <pair <int, int>> vp = {{A[1], A[2]}, {A[1], A[3]}, {A[2], A[3]}};
        for (pair <int, int> p : vp) {
            int first = p.first, rat = p.second - p.first;
            if (rat == 0) {
                continue;
            }
            vector <int> out;
            int cnt = 0;
            for (int i = 1; i <= N; i++) {
                if (A[i] == first + rat * cnt) {
                    cnt++;
                } else {
                    if ((int) out.size() > 1 && A[i] - out.back() != out[1] - out[0]) {
                        break;
                    }
                    out.push_back(A[i]);
                }
                if (N - suff <= i) {
                    if ((int) out.size() + (N - i) < 2 || cnt < 2) {
                        continue;
                    }
                    int rat2 = ((int) out.size() > 1 ? out[1] - out[0] :
                               ((int) out.size() > 0 ? A[i + 1] - out.back() :
                                A[i + 2] - A[i + 1]));
                    if (i + 1 <= N && (int) out.size() > 1 && A[i + 1] - out.back() != rat2) {
                        continue;
                    }
                    if (i + 2 <= N && A[i + 2] - A[i + 1] != rat2) {
                        continue;
                    }
                    if (rat2 > 0) {
                        answer = min(answer, make_tuple(first, rat, cnt));
                        answer = min(answer, make_tuple((out.empty() == false ? out[0] : A[i + 1]),
                                                        rat2, N - cnt));
                    }
                }
            }
        }
        if (answer != make_tuple(INT_MAX, INT_MAX, INT_MAX)) {
            int first, rat, len; tie(first, rat, len) = answer;
            cout << first << " " << rat << " " << len << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
