#include <bits/stdc++.h>
//#include "../prettyprint.hpp"
#ifndef SS
typedef long long int ll;
typedef std::pair<int,int> ii;
int II(){int n;scanf("%d",&n);return n;}
void II(int n){printf("%d",n);}
void IIn(int n){printf("%d\n",n);}
void IIb(int n){printf("%d ",n);}
ll LL(){ll n;scanf("%lld",&n);return n;}
void LL(ll n){printf("%lld",n);}
void LLn(ll n){printf("%lld\n",n);}
void LLb(ll n){printf("%lld ",n);}
char CC(){return getchar();}
char CCa(){char c=getchar();while(c<=32)c=getchar();return c;}
void CC(char c){putchar(c);}
void CCn(char c){putchar(c);putchar(10);}
void CCb(char c){putchar(c);putchar(32);}
void CCn(){putchar(10);}
void CCb(){putchar(32);}
void SS(char *s){scanf("%s",s);}
void SSb(const char *s){printf("%s ",s);}
void SSn(const char *s){printf("%s\n",s);}
float FF(){float n;scanf("%f",&n);return n;}
void FF(float n){printf("%f",n);}
void FFn(float n){printf("%f\n",n);}
void FFb(float n){printf("%f ",n);}
void FF(double n,int prec){std::cout<<std::setprecision(prec)<<n;}
void FFn(double n,int prec){std::cout<<std::setprecision(prec)<<n;putchar(10);}
void FFb(double n,int prec){std::cout<<std::setprecision(prec)<<n;putchar(32);}
#endif
template <class T,class K>std::ostream &operator<<(std::ostream &os, std::pair<T,K> const &P)
{ 
    return os<<"("<<P.first<<","<<P.second<<")";
}

template <class T>std::ostream &operator<<(std::ostream &os, std::vector<T> const &V)
{ 
    os << "[";char pd[2]={0,0};for(auto x:V){os<<pd;os<<x;pd[0]=',';}os << "]";
    return os;
}

using namespace std;

int pos(int i,int N)
{
    if(N==1)return 0;
    if(i&1)return pos(i/2,N/2);
    return N/2+pos(i/2,(N+1)/2);
}

int who(int i,int N)
{
    if(i>=N)return -1;
    if(N==1)return 0;
    if(i<N/2)return 1+2*who(i,N/2);
    return 2*who(i-N/2,(N+1)/2);
}

int main()
{
    int N=II(),M=II();
    int actpos=pos(II()-1,N);
    for(int x=actpos+1;x<actpos+M;x++)if(who(x,N)!=II()-1){IIn(0);return 0;}
    IIn(1);
}

