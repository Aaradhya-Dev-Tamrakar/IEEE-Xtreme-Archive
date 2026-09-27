#include <bits/stdc++.h>
using namespace std;
const int limit=1e5+10;
int perm[limit][2];
int N,M,K;
int testpath(int index)
{
    int pt=1;
    for(int i=0;i<M;i++)
    {
        if(i!=index-1)
        {
            if(pt==perm[i][0])pt=perm[i][1];
            else if(pt==perm[i][1])pt=perm[i][0];
          
        }
        if(pt==K && i==M-1)return 1;
    }
    return 0;
    
}
int main() {

    cin>>N>>M>>K;
    for(int i=0;i<M;i++)
    cin>>perm[i][0]>>perm[i][1];
    for(int i=1;i<M;i++)
    if(testpath(i)==1){cout<<i;break;}
    return 0;
}