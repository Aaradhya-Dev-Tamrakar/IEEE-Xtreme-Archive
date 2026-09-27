#include <cstdio>
#include <cmath>
using namespace std;

char c;
long long n,a[60],i,aux,p;

long long ppp (long k)
{
long long p=1;
for (long long i=1; i<=k; i++)
    p*=2;
return p;
}
long long stinge (long long n)
{
long long s=0;
if (n<=0) return 0;
while ((a[n]==0)&&(n>0)) n--;
if (n<=0) return 0;
if (n==1) return 1;
//
if (a[n-1]==1)
    {
    s=stinge(n-2);
    }
    else
    {
    if (a[n-2]==1) s = stinge(n-3) + ppp(n-2);
    if (a[n-2]==0) s = ppp(n-1) - 1 - stinge(n-2);
    }

//
return s+ppp(n-1);
}

int main()
{
//freopen("lightbulb.in","r",stdin);
//freopen("lightbulb.out","w",stdout);
do{
if (scanf("%c",&c)!=1) break;
if ((c=='0')||(c=='1'))
    {
    n++;
    a[n]=c-'0';
    }

}while ((c=='0')||(c=='1'));
for (i=1; i<=n/2; i++)
    {
    aux=a[i];
    a[i]=a[n-i+1];
    a[n-i+1]=aux;
    }

////
//for (i=1; i<=n; i++)
//        printf("%ld ",a[i]);
////
p=stinge(n);
printf("%lld",p);
return 0;
}
