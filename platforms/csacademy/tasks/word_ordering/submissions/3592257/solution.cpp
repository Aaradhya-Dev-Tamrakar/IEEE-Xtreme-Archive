#include <bits/stdc++.h>

using namespace std;

string order;
bool cmp(string& a, string& b){
  int i = 0, j = 0;
  int n = a.size(), m = b.size();
  for(;i < n && j < m && a[i] == b[j]; i++, j++);
  
  if(j == m) return false;
  if(i == n) return true;
  
  int p1 = find(order.begin(), order.end(), a[i]) - order.begin();
  int p2 = find(order.begin(), order.end(), b[j]) - order.begin();
  
  return p1 < p2;
}

int main() {
    cin >> order;
    int sz = order.size();
    for(int i=0;i<sz;i++){
      order += string(1, (order[i]-32));
    }
    
    int n;
    cin >> n;
    vector<string> a(n);
    for(string& x : a) cin >> x;
    
    sort(a.begin(), a.end(), cmp);
    
    for(string& x : a) cout << x << "\n";
    
    return 0;
}