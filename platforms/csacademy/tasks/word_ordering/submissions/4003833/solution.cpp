#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5, Smax = 1000;

char *S[N], *tmp[N];
int cnt[Smax + 1], ord[256], rpos;

void radix_reorder(char** S, size_t (*f)(const char*), int fMax, int n){
    memset( cnt, 0, fMax * sizeof(*cnt) );
    for (int i = 0; i < n; i++)
        cnt[ f(S[i]) ]++;
    for (int i = 0, a = 0; i < fMax; i++){
        a += cnt[i];
        cnt[i] = a - cnt[i];
    }
    for (int i = 0; i < n; i++)
        tmp[ cnt[ f(S[i]) ]++ ] = S[i];
    memcpy( S, tmp, n * sizeof(char*) );
}

void radix_sort(char** S, int n){
    int start[Smax + 1] = {0};
    for (int i = 0; i < n; i++)
        start[ strlen(S[i]) ]++;
    for (int i = 1; i < Smax; i++)
        start[i] += start[i - 1];
    radix_reorder(S, strlen, Smax + 1, n);
    
    for (rpos = Smax - 1; rpos >= 0; rpos--)
        radix_reorder(S + start[rpos], [](const char* s) -> size_t { return ord[ s[rpos] ]; }, 52, n - start[rpos]);
}

int main() {
    char tmp[Smax];
    int n, nr = 0;

    cin >> tmp;
    for (int i = 0; tmp[i]; i++)
        ord[ tmp[i] ] = nr++;
    for (int i = 0; tmp[i]; i++)
        ord[ tmp[i] - 'a' + 'A' ] = nr++;
    
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        S[i] = strdup(tmp);
    }
    radix_sort(S, n);
    for (int i = 0; i < n; i++)
        cout << S[i] << '\n';
    return 0;
}