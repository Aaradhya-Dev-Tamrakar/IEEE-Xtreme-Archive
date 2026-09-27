#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char sir[55];

long long grayToBinary64(long long num);

int main() {
    cin >> sir;

    long long put = 1;
    long long nr = 0;

    int lg = strlen(sir);

    for(int i = lg - 1; i >= 0; --i) {
        nr += (sir[i] == '1' ? put : 0);
        put <<= 1;
    }

    cout << grayToBinary64(nr) << '\n';

    return 0;
}

long long grayToBinary64(long long num)
{
    num = num ^ (num >> 32);
    num = num ^ (num >> 16);
    num = num ^ (num >> 8);
    num = num ^ (num >> 4);
    num = num ^ (num >> 2);
    num = num ^ (num >> 1);
    return num;
}
