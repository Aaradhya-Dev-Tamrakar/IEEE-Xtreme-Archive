#include <bits/stdc++.h>

using namespace std;

int mp[26];
bool cmp(string a, string b){
    for(int i = 0; i < min((int)a.size(), (int)b.size()); i++){
        int ch1 = tolower(a[i]) - 'a';
        int ch2 = tolower(b[i]) - 'a';
        if(isupper(a[i]) && isupper(b[i])){
            if(a[i] != b[i])
                return mp[ch1] < mp[ch2];
        }
        else if(isupper(a[i])){
            return 0;
        }
        else if(isupper(b[i])){
            return 1;
        }
        if(ch1 == ch2) continue;
        return mp[ch1] < mp[ch2];
    }
    return a.size() < b.size();
}

int main() {
    string s; int n; 
    cin >> s >> n;
    for(int i = 0; i < (int)s.size(); i++){
        mp[s[i] - 'a'] = i;
    }
    vector<string>arr(n);
    for(auto &it : arr) cin >> it;
    sort(arr.begin(), arr.end(), cmp);
    for(auto &it : arr) cout << it << endl;
    return 0;
}