#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    string alphabet;
    cin >> alphabet;

    // build custom order mapping
    unordered_map<char, int> permutation;
    for (size_t i = 0; i < alphabet.size(); i++) {
        permutation[alphabet[i]] = i;
        permutation[toupper(alphabet[i])] = i + 26; // optional uppercase
    }

    int len;
    cin >> len;
    vector<string> words(len);

    for (int i = 0; i < len; i++) {
        cin >> words[i];
    }

    // sort words according to custom alphabet
    sort(words.begin(), words.end(), [&](const string &a, const string &b) {
        size_t n = min(a.size(), b.size());
        for (size_t i = 0; i < n; i++) {
            if (permutation[a[i]] != permutation[b[i]])
                return permutation[a[i]] < permutation[b[i]];
        }
        return a.size() < b.size(); // shorter word first if all letters equal
    });

    // print sorted words
    for (const auto &w : words) {
        cout << w << "\n";
    }

    return 0;
}
