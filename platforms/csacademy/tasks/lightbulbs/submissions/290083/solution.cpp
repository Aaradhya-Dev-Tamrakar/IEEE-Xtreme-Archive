#include <iostream>
#include <string>
#define Nmax 52
#define LL long long
using namespace std;


LL n,dp[2][Nmax];
string s;
int main()
{
    cin>>s;

    dp[0][s.length()-1] = s[s.length()-1]=='1';
    dp[1][s.length()-1] = s[s.length()-1]=='0';

    for (int i=s.length()-2;i>=0;i--)
    {
        if (s[i]=='1')
        {
            dp[1][i] = dp[0][i+1];
            dp[0][i] = dp[1][i+1] + (1LL<<(s.length()-i-1));
        }
        else
        {
            dp[1][i] = dp[1][i+1] + (1LL<<(s.length()-i-1));
            dp[0][i] = dp[0][i+1];
        }
    }

    cout<<dp[0][0];

    return 0;
}
