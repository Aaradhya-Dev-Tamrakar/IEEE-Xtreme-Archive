#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    int N;
    string S;
    cin >> N;
    cin >> S;
    int cnt = 0;
    for(int i = 0; i < N; i++)
        cnt += S[i] == 'A';
    if(cnt % 2 == 0) {
        cout << -1;
        return 0;
    }
    vector <int> tab;
    cnt = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == 'B') cnt++;
        else if(cnt > 0) {
            tab.push_back(cnt);
            cnt = 0;
        }
    }
    int nimber = 0;
    for(int i = 0; i < tab.size(); i++) {
        nimber ^= tab[i];
    }
    cout << (nimber == 0 ? "B" : "A");
}