#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100010;
int a[N];
int n, m;

int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}

int main(void)
{
	scanf("%d%d", &n, &m);
	int g = 0;	
	for(int i = 1; i <= n; i ++ )
	{
		scanf("%d", &a[i]);
		g = gcd(g, a[i]);
	}
	while(m -- )
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x] /= y;
		g = gcd(g, a[x]);
		printf("%d\n", g);
	}
	return 0;
}