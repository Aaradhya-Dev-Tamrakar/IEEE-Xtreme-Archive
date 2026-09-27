#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;
char s[100005];
int n,sum,nra,nrb,i;
int main()
{
    cin>>n;
    cin>>s;
    sum=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='A')
        {
            nra++;
        }
        else
        {
            nrb=1;
            while(s[i+1]=='B')
            {
                nrb++;
                i++;
            }
            sum=sum^nrb;
        }
    }
    if(nra%2==0)
    {
        cout<<-1<<'\n';
        return 0;
    }
    if(sum!=0)
    {
        cout<<"A"<<'\n';
        return 0;
    }
    cout<<"B"<<'\n';
    return 0;
}
