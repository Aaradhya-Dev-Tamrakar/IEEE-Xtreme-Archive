#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

int main() {
    int num1 ,  num2 ;
    cin >> num1 >> num2 ;
    int a[num1] , g=0 , ind , d ;
    for(int i=0 ; i<num1 ; i++)
    {
        cin >> a[i] ;
        g=__gcd(a[i],g) ;
    }
    for(int i=0 ; i<num2 ; i++)
    {
        cin >> ind >> d ;
        a[ind-1]/=d ;
        g=__gcd(a[ind-1],g) ;
        cout << g << "\n" ;
    }
    return 0;
}