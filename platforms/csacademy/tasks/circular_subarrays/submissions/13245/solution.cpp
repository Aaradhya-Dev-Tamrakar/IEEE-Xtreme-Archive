#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <bitset>
using namespace std;
#define MOD 1000000007
int a[111111];
int b[111111];
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int main(void){
	std::ios::sync_with_stdio(false);cin.tie(0);
	int i,j,n,k;
	int g,m;
	long long re=0;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
	g=gcd(n,k);
	m=n/g;
	for(i=0;i<g;i++)
	{
		for(j=0;j<m;j++)
		{
			b[j]=a[j*g+i];
			//cout<<b[j]<<' ';
		}
		sort(b,b+m);
		for(j=0;j<m;j++)
			re+=abs(b[j]-b[(m-1)/2]);
		//cout<<re<<endl;
	}
	cout<<re<<endl;
	//system("pause");
	return 0;
} 