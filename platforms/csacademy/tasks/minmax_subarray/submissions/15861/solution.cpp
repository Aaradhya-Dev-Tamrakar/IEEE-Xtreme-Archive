#include <cstdio>
#define N 5000
#define MULT 1000000000
using namespace std;

int v[N+1];

int mod(int a){
    return (a<0) ? -a : a;
}

int minim(int a,int b){
    return (a<b) ? a : b;
}

int main(){
    int n,i,min,max;
    
    scanf ("%d",&n);
    max=0;
    min=MULT;
    for(i=1;i<=n;i++){
        scanf ("%d",&v[i]);
        if (v[i]>max) max=v[i];
        if (v[i]<min) min=v[i];
    }
    
    int p,k,R;
    p=k=0;
    R=n;
    for(i=1;i<=n;i++){
        if (v[i]==min) p=i;
        if (v[i]==max) k=i;
        
        if (p!=0 &&k!=0) R=minim(R,mod(p-k)+1);
    }
    
    printf ("%d",R);
    return 0;
}