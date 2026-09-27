#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

//*Fast input
	char ccc; bool is_reading_negative_number;
	inline int mul10(int& xxx)
	{
		return (xxx << 3) + (xxx << 1);
	}
	inline void scan(int& xxx){
		do	{ ccc = getchar_unlocked(); } while ((ccc < '0') || (ccc > '9'));	xxx = 0;
		do	{ xxx = mul10(xxx) + (ccc - '0'); ccc = getchar_unlocked(); } while ((ccc >= '0') && (ccc <= '9'));
	}
// In codeforces getchar_unlocked is compilation error, comment this block */

int n;
int a;
int minx;
int maxx;
int lastmin;
int lastmax;
int best;

inline int abs(int x)
{
	return (x < 0) ? -x : x;
}

int main()
{
	scan(n);
	best = n;
	minx = 1000000001;
	maxx = 0;
	for (int i = 1; i <= n; i++)
	{
		scan(a);
		if (a > maxx)
		{
			maxx = a;
			lastmax = i;
			best = n;
		}
		else if (a == maxx)
		{
			lastmax = i;
		}
		if (a < minx)
		{
			minx = a;
			lastmin = i;
			best = n;
		}
	   	else if (a == minx)
		{
			lastmin = i;
		}
		best = min(best, abs(lastmin - lastmax) + 1);
	}
	cout << best << endl;
	return 0;
}
