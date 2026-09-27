#include <bits/stdc++.h>
using namespace std;

int N, a[100000];

void input()
{
    scanf("%d", &N);
    for( int i = 0; i < N; i++ )
        scanf("%d", &a[i]);
}

void solve()
{
    int i = 1;
    int b[100000];
    int k = 0;
    b[k++] = a[0];
    int min_el = a[0];
    while( i < N )
    {
        if( b[k-1] <= a[i] )
        {
            b[k++] = a[i];
            min_el = a[i];
        }
        else
        {
            if( min_el > a[i] )
                min_el = a[i];

            if( k > 1 && min_el < b[k-2] )
            {
                int x = b[k-1];
                while( k > 1 && min_el < b[k-2] )
                {
                    k--;
                }
                b[k-1] = x;
            }
        }

        i++;
    }

    printf("%d\n", k);
}

int main()
{
    input();
    solve();
    return 0;
}
