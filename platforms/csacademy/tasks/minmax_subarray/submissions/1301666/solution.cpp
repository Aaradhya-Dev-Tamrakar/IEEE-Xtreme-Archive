#include <bits/stdc++.h>
using namespace std;


int solve(vector<int>& arr){
    int maxi=*max_element(arr.begin(),arr.end());
    int mini=*min_element(arr.begin(),arr.end());
    
    if(maxi==mini)
        return 1;
    
    vector<int> minpos; 
    for(int i=0;i<arr.size();i++){ if(arr[i]==mini) minpos.push_back(i); }
    vector<int> maxpos;
    for(int i=0;i<arr.size();i++){ if(arr[i]==maxi) maxpos.push_back(i); }
    
    int res=INT_MAX;
    for(int &g:minpos){
        for(int &h:maxpos){
            res = min(res,abs(g-h)+1);
        }
    }
    return res;
}
int main() {
    int n,tmp;
    cin >> n;
    vector<int> v;
    for(;n;--n){
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << solve(v);
    return 0;
}