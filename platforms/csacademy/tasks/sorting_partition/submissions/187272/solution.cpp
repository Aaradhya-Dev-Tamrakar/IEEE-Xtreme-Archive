#include <cstdio>
#include <algorithm>
#define MaxN 100005
using namespace std;
int N,v[MaxN];
struct St
{
    int Min,Max;
}Stack[MaxN];
int Size=0;
int main() {
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=N;i++)
    {
        Stack[++Size].Min=Stack[Size].Max=v[i];
        while(Size>1&&Stack[Size-1].Max>Stack[Size].Min)
        {
            Stack[--Size].Min=min(Stack[Size].Min,Stack[Size+1].Min);
            Stack[Size].Max=max(Stack[Size].Max,Stack[Size+1].Max);
        }
    }
    printf("%d",Size);
    return 0;
}