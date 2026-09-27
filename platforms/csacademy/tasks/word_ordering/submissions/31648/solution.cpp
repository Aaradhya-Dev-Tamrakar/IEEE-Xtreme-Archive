/// In the name of God

#include <bits/stdc++.h>

//#define int long long

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define X first
#define Y second
#define all(o) o.begin(), o.end()
const int maxn = 100;
int ord[maxn];
inline char tt(char x){
    if(x >= 'A' && x <= 'Z'){
        int t = x - 'A' + 'a';
        return char(t);
    }
    return x;
}
bool cmp(const char &f,const char &s){
    if(f >= 'A' && f <= 'Z' && s >= 'a' && s <= 'z') return 0;
    if(s >= 'A' && s <= 'Z' && f >= 'a' && f <= 'z') return 1;
    return (ord[tt(f) - 'a'] < ord[tt(s) - 'a']);
}
bool cm(const string &f,const string &s){
    int x = f.size(), y = s.size();
    for(int i=0; i<min(x, y); i++)
        if(s[i] != f[i])
            return cmp(f[i], s[i]);
    if(x < y) return 1;
    return 0;
}
main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for(int i=0; i<26; i++)
        ord[s[i] - 'a'] = i;
    vector<string>v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cm);
    for(auto i : v)
        cout << i << "\n";
}
