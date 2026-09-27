#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

int main() {
    std::string perm;
    int k;
    std::cin >> perm >> k;

    
    std::unordered_map<char, int> priority;
    int size_perm = perm.size();
    for (int i = 0; i < size_perm; i++) {
        char lower = perm[i];
        char upper = lower - 32;
        priority[lower] = i;
        priority[upper] = size_perm+i; 
    }


    std::vector<std::string> words(k);
    for (int i = 0; i < k; i++) {
        std::cin >> words[i];
    }

    std::sort(words.begin(), words.end(), [&](const std::string& a, const std::string& b) {
        int len = std::min(a.size(), b.size());
        for (int i = 0; i < len; ++i) {
            if (priority[a[i]] != priority[b[i]])
                return priority[a[i]] < priority[b[i]];
        }
        return a.size() < b.size(); 
    });

    for (const auto& word : words) {
        std::cout << word << '\n';
    }

    return 0;
}