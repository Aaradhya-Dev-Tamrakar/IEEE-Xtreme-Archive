#include <iostream>

using namespace std;
int n,m,lst,a;
int find_pos(int i,int l,int r)
{
   if(r - l < 2)
      return i;
   int ot = (r - l)/2 + (r - l)%2,et = (r - l)/2;
   if((i - l) & 1)
      return find_pos(l + (i - l)/2,l,l + et);
   else
      return find_pos(l + et + (i - l)/2 + (i - l)%2,l + et,r);
   
}
int main() {
    cin >> n >> m;
    bool ans = 1;
    cin >> a;
    lst = find_pos(a - 1,0,n);
    for(int i = 1;i < m && ans;i++)
    {
       cin >> a;
      if(find_pos(a - 1,0,n) != lst + i)
        ans = 0;
    }
   cout << ans;
    return 0;
}