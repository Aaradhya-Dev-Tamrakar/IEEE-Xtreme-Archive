#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define LL long long
#define MX 1000000000
using namespace std;

int n;

LL oddsum(int p)
{
    LL w = (p+1)/2;
    return w*w;
}

LL cumu(int p)
{
    if(p==0) return 0;
    if(p==1) return 1;
    if(p%2==0) return oddsum(p-1)+cumu(p/2);
    else return oddsum(p)+cumu(p/2);
}

LL quiz(int a,int b)
{
    return cumu(b)-cumu(a-1);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a1,a2; scanf("%d%d",&a1,&a2);
        printf("%lld\n",quiz(a1,a2));
    }
    return 0;
}
