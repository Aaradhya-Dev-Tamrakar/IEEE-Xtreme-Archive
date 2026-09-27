#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <memory.h>
#include <deque>
typedef long long ll;
#define mp make_pair
const ll MOD=1000000007;
const int M=100005;
const int N=1000006;
using namespace std;
int n,a;
char temp[M];
vector<int>v;
string s;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    #endif
    cin>>n;
    scanf("%s",temp);
    s=temp;
    int ct=0;
    for(int i=0;i<s.size();i++)
    	if(s[i]=='B')
    		++ct;
    	else
    	{
    		v.push_back(ct);
    		ct=0;
    		a++;
    	}
    if(ct)
    	v.push_back(ct);
    int x=0;
    for(int i=0;i<v.size();i++)
    	x^=v[i];
    if(!x)
    {
    	if(a%2==1)
    		puts("B");
    	else
    		puts("-1");
    }
    else
    {
    	if(a%2==1)
    		puts("A");
    	else
    		puts("-1");
    }
}