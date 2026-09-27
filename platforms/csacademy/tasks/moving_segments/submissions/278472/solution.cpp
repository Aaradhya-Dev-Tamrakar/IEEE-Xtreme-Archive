#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return v; }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

typedef long long LL;
#define MAXN 100013
int N;
int A[MAXN], B[MAXN];

LL solve(int pos) {
    LL ans = 0;
    for (int i = 0; i < N; i++) {
        if (pos < A[i]) {
            ans += A[i] - pos;
        }
        else if (pos > B[i]) {
            ans += pos - B[i];
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }
    
    int lo = -1e9;
    int hi = 1e9;
    while (lo != hi) {
        int mid = (lo + hi) / 2;
        int a1 = solve(mid), a2 = solve(mid + 1);
        if (a1 < a2) {
            hi = mid;
        }
        else if (a1 > a2) {
            lo = mid + 1;
        }
        else {
            lo = hi = mid;
        }
    }

    cout << solve(lo) << endl;
    return 0;
}
