#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a,int b){
    return b ? gcd(b,a%b) : a;
}

int main() {
    int N, K; cin >> N >> K;
    int g = gcd(N,K);
    vector<int> A(N);
    for (int&a:A) cin >> a;
    int ans = 0;
    for (int i = 0; i < g; ++i) {
        vector<int> X(N/g);
        for (int j = 0; j < N/g; ++j) X[j] = A[i+j*g];
        sort(X.begin(),X.end());
        int med = X[N/g/2];
        for (int x:X) ans += abs(x-med);
    }
    cout << ans << endl;
}