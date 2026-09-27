#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string perm;
    cin >> perm;

    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    // Build rank map: lowercase a-z → 0–25, uppercase A-Z → 26–51
    int rank[128]; // ASCII size
    for (int i = 0; i < 26; ++i) {
        rank[perm[i]] = i;
        rank[toupper(perm[i])] = i + 26;
    }

    // Custom comparator using rank
    auto cmp = [&](const string &a, const string &b) {
        int len = min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (rank[a[i]] != rank[b[i]])
                return rank[a[i]] < rank[b[i]];
        }
        return a.size() < b.size();
    };

    sort(words.begin(), words.end(), cmp);

    for (const string &word : words)
        cout << word << '\n';

    return 0;
}