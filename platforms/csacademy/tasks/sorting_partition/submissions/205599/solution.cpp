#include <iostream>

using namespace std;
int a[100005];
int main() {
    int n, b,i,j,mx,c=0;
    cin>>n;
    
    for(i=1;i<=n;i++)
        cin>>a[i];
    mx=0;
    for(i=1;i<=n;i++){
        bool ch=1;
        mx=max(mx,a[i]);
        for(j=i+1;j<=n;j++){
            if(mx>a[j]){
                ch=0;break;}
        }
        if(ch){
            c++;mx=0;
        }
            
    }
    cout<<c<<endl;
    
    return 0;
}