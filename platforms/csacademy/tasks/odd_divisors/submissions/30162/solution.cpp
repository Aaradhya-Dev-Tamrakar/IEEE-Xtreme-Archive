#include <stdio.h>
long long sumkee(long long from,long long to)
{
    if(from%2==0)
        from++;
    if(to%2==0)
        to--;
    if(from>to)
        return 0;
    long long num=(to-from)/2+1;
    long long sum=(from+to)*(num/2);
    if(num%2==1)
        sum+=(from+to)/2;
    return sum;
}
int main()
{
    long long ans=0;
    long long n,a,b,think;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
    {
        think=1;
        ans=0;
        scanf("%lld %lld",&a,&b);
        while(think<=b)
        {
            ans+=sumkee((a-1)/think+1,(b/think));            
            think*=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}