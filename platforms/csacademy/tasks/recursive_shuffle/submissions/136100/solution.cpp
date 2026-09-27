#include <iostream>

using namespace std;
int n,m,lst,a;
/*int a[1000];

void rec(int l,int r)
{
   if(r - l < 2)
      return;
   //cerr << l << " " << r << endl;
   int e[100],o[100],et = 0,ot = 0;
   for(int i = 0;i < r - l;i++)
      if(i % 2)
      {
         e[et] = a[l + i];
         et++;
      }
      else
      {
         o[ot] = a[l + i];
         ot++;
      }
   //cout << et << " " << o[0] << endl;
   for(int i = 0;i < et;i++)
      a[l + i] = e[i];
   for(int i = 0;i < ot;i++)
      a[l + et + i] = o[i];
   rec(l,l + et);
   rec(l + et,l + et + ot);
}*/
int find_pos(int i,int l,int r)
{
   //cout <<i << " " << l << " " << r << endl;
   if(r - l < 2)
      return i;
   int ot = (r - l)/2 + (r - l)%2,et = (r - l)/2;
   //cout << et << " " << ot << endl;
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
   // for(int i = 0;i < n;i++)
   //   a[i] = i + 1;
  // rec(0,n);
 //  for(int i = 0;i < n;i++)
   //   cout << a[i] << " ";
    //  cout <<endl;
   //cout << endl << find_pos(5,0,10);
    return 0;
}