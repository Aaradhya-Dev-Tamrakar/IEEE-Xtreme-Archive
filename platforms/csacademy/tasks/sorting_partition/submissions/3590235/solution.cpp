#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int arr[n];
    int pre[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int mini;
    pre[n-1]=mini=arr[n-1];
    for(int i=n-2;i>0;i--){
        mini = min(mini, arr[i]);
        pre[i]=mini;
    }
    int partition = 1;
    int maxo = 0;
    for(int i=1;i<n;i++){
        maxo=max(maxo, arr[i-1]);
        if(maxo<=pre[i]){
            partition++;
            maxo = 0;
        }
    }
    cout << partition << "\n";
    return 0;
}