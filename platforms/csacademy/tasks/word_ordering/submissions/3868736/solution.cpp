#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
string s;
map<char,int>mp;
bool comp(string a,string b)
{
    string aa=a,bb=b;
    aa+='$';
    bb+='@';
    while(aa[0]==bb[0])
    {
        aa.erase(aa.begin());
        bb.erase(bb.begin());
    }
    return mp[aa[0]]<mp[bb[0]];
}
int main()
{
    cin>>s;
    int k=0;
    for(char&c:s)
    {
        c-=32;
        mp[c]=k;
        k++;
    }
    for(char&c:s)
    {
        c+=32;
        mp[c]=k;
        k++;
    }
    mp['$']=-1;
    mp['@']=-1;
    int n;
    cin>>n;
    string a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        for(char&c:a[i])
        {
            if(c>='a'&&c<='z')
            {
                c-=32;
            }
            else
            {
                c+=32;
            }
        }
    }
    sort(a,a+n,comp);
    for(auto&i:a)
    {
        for(char&c:i)
        {
            if(c>='a'&&c<='z')
            {
                c-=32;
            }
            else
            {
                c+=32;
            }
        }
        cout<<i<<endl;
    }
}