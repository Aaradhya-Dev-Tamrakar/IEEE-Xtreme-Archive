#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;

ll dp[100][2] ; 

int main()
{

    ios::sync_with_stdio(false);
    
    string s ; cin >> s ; 
    
    int n = s.size() ; 
    
    reverse(s.begin() , s.end()) ; 
    
    if(s[0] == '0'){
        
        dp[0][0] = 0 ;
        dp[0][1] = 1 ; 
        
    } else { 
         
         dp[0][0] = 1 ; 
         dp[0][1] = 0 ; 
        
    }
    
    for(ll i = 1 ; i < n ; i++){
        
         
         if(s[i] == '0'){
             
             dp[i][0] = dp[i - 1][0] ; 
             dp[i][1] = dp[i - 1][1] + (1LL << i) ; 
             
         } else { 
             
             dp[i][0] = dp[i - 1][1] + (1LL << i); 
             dp[i][1] = dp[i - 1][0] ; 
             
         }
         
    } 
    
    
    cout << dp[n - 1][0] << endl ;


    return 0;
}
