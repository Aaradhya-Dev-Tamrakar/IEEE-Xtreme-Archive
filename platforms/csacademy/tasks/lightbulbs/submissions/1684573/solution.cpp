#include <iostream>
#include <string>

using namespace std;

long long decimal(long long N)
{
    long long ans = 0;
    while(N)
    {
        ans ^= N;
        N >>= 1;
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    int len = s.length();
    long long N = 0;
    for(int i=0; i<len; i++)
    {
        if(s[i] == '1')
            N += (1LL << (len - i - 1));
    }
    cout << decimal(N) << endl;
    return 0;
}