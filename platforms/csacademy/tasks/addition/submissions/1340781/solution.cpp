#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    long long temp=0;
    
    srand(time(NULL));
    
    while(temp!=a+b){
        
        temp++;
    }
    cout<<temp<<endl;
    return 0;
}