#include <bits/stdc++.h>
#define N 100005

using namespace std;

char s[N];
int main() {
    
    int n;
    scanf("%d", &n);
    
    scanf("%s", s);
    int ct = 0;
    
    for(int i = 0; i < n; i++)
        if(s[i] == 'A')ct++;
        
    if(ct == n || ct == 0){
        
        if(ct == n){
            
            if(ct&1)puts("B");
            else puts("-1");
        }
        else puts("-1");
    }
    else{
        
  
        vector<int>v;
        int c = 0;
        
        for(int i = 0; i < n; i++){
            
            if(s[i] == 'B')c++;
            else{
                
                if(c > 0)v.push_back(c);
                c = 0;
            }
        }
         
         if(c > 0)v.push_back(c);  
         int ans = 0;
         
        for(int i = 0; i < v.size(); i++)ans ^= v[i];
        
        if(ct&1){
            
           if(ans != 0)puts("A");
           else puts("B");
            
        }
        else puts("-1");
   
        
    }
}