#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, val[200];
string str;
vector<string> a;

bool Compare(const string &lhs, const string &rhs) {
    for (size_t i = 0; i < min(lhs.size(), rhs.size()); ++i) {
        if (val[lhs[i]] < val[rhs[i]]) {
            return true;
        } else if (val[lhs[i]] > val[rhs[i]]) {
            return false;
        }
    }
    return lhs.size() < rhs.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin >> str;
    for (int i = 0; i < 26; ++i) {
        val[str[i]] = i;
        val[str[i] + 'A' - 'a'] = i + 26;
    }

    cin >> N;
    a.resize(N);
    for (auto &str : a) {
        cin >> str;
    }
    sort(a.begin(), a.end(), Compare);
    for (const auto &str : a) {
        cout << str << "\n";
    }
    return 0;
}
