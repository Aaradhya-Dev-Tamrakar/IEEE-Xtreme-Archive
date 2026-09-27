# include <iostream>
# include <cmath>
# include <algorithm>
# include <map>
# include <unordered_set>
# include <memory.h>
# include <vector>
using namespace std;
 
 
const int MD = 1000000000 + 7;
const int MAX_E = 500333;
const int MAX_N = 1047;

#define time ez_contest
#define rank ez_timus

int priority[256];

bool cmp(const string& a, const string& b) {
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        if (priority[a[i]] <priority[b[i]]) {
            return true;
        } else if (priority[a[i]] > priority[b[i]]) {
            return false;
        }
    }
    return (a.size() < b.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    string perm;
    cin >> perm;
    for (int i = 0; i < perm.size(); i++) {
        priority[perm[i]] = i;
        priority[perm[i] + 'A' - 'a'] = i + 26;
        //cerr << perm[i] << " " << i << endl;
    }
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    sort(a.begin(), a.end(), &cmp);
    for (string& s : a) {
        cout << s << "\n";
    }
    return 0;
}

