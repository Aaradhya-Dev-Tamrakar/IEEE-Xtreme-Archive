#include <bits/stdc++.h>
using namespace std;


map<char,char> mp,rev;

int main(){
    string s;
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(char i = 'a';i<='z';i++){
        char k;
        cin>>k;
        mp[k] = i-'a'+'A';
        mp['A'+(k-'a')] = i;
    }
    for(auto &i:mp){
        rev[i.second] = i.first;
    }
    int n;
    cin>>n;
    string arr[n];
    for(auto &i:arr){
        cin>>i;
        for(auto &j:i)j = mp[j];
    }
    sort(arr,arr+n);
    for(auto &i:arr){
        for(auto &j:i){
            cout<<rev[j];
        }
        cout<<'\n';
    }
    return 0;
}