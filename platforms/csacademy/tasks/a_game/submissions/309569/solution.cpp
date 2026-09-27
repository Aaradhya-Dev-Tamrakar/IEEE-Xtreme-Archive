#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int n, a=0, b=0;
    cin>>n>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='A')a++;
    }
    if(a%2==0){
        cout<<-1<<endl; return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int c=0;
        while(i<n && str[i]=='B'){
            i++; c++;
        }
        ans^=c;
    }
    if(ans)cout<<"A"<<endl;
    else cout<<"B"<<endl;
}