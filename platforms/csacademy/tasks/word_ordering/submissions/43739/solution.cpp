#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <vector>
typedef std::string str;
const int MAXC = 1005;
const int MAXN = 1E5+5;
char buff[MAXC]{ };
str array[MAXN]{ };
char alph[60];
int N;

struct strCMP {
    const bool operator () (const str& lhs, const str& rhs) const {
        int min = std::min(lhs.size(), rhs.size());
        for(int i = 0; i < min; ++i) if(lhs[i] != rhs[i])
        {
            bool B[2] = { lhs[i] <= 'Z', rhs[i] <= 'Z' };
            if(B[0] ^ B[1])
                return B[1]; // Uppercase is GREATER
            return (strchr(alph, lhs[i])-alph) < (strchr(alph, rhs[i])-alph);
        }
        return lhs.size() < rhs.size();
    }
};

int main()
{
    scanf(" %s%d", &alph, &N);
    for(int i = 0; i < 26; ++i)
        alph[i+26] = alph[i]-' ';
    for(int i = 0; i < N; ++i)
    {
        scanf(" %s", &buff);
        array[i] = buff;
    }
    std::sort(array, array+N, strCMP());
    for(int i = 0; i < N; ++i)
        puts(array[i].c_str());
    return 0;
}