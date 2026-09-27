
#include <bits/stdc++.h>

using namespace std;

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
	inline void scanword(string& xxx){
		do	{ ccc = getchar_unlocked(); } while ((ccc < 'A') || (ccc > 'Z'));	xxx = "";
		do	{ xxx = xxx + ccc; ccc = getchar_unlocked(); } while ((ccc >= 'A') && (ccc <= 'Z'));
	}
// In codeforces getchar_unlocked is compilation error, comment this block */

int n;
string s;
int u;
int v;
vector<int> e[100001];
int redch[100001];
int bluech[100001];
int t1ch[100001];
int t[100001];
int redt1bej[100001];
int bluet1bej[100001];
int apa[100001];
int q[100001];


/*void dfs1(int p)
{
	if (s[p - 1] == 'R')
	{
		redch[p] = 1;
	}
	else
	{
		bluech[p] = 1;
	}
	if (t[p] == 1)
	{
		t1ch[p] = 1;
	}
	for (int q:e[p])
	{
		if (!t[q])
		{
			t[q] = 3 - t[p];
			dfs1(q);
			redch[p] += redch[q];
			bluech[p] += bluech[q];
			t1ch[p] += t1ch[q];
			redt1bej[p] += redt1bej[q] + abs(t1ch[q] - redch[q]);
			bluet1bej[p] += bluet1bej[q] + abs(t1ch[q] - bluech[q]);
		}
	}
}
*/
inline int abs(int x)
{
	return (x > 0) ? x : -x;
}

int sv;

int main()
{
	scan(n);
	scanword(s);
	for (int i = 1; i < n; ++i)
	{
		scan(u); scan(v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	t[1] = 1;
	q[1] = 1;
	sv = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (s[q[i] - 1] == 'R')
		{
			redch[q[i]] = 1;
		}
		else
		{
			bluech[q[i]] = 1;
		}
		if (t[q[i]] == 1)
		{
			t1ch[q[i]] = 1;
		}
		for (int r:e[q[i]])
		{
			if (r != apa[q[i]])
			{
				apa[r] = q[i];
				t[r] = 3 - t[q[i]];
				q[++sv] = r;
			}
		}
	}
	for (int i = n; i >= 1; --i)
	{
		for (int r:e[q[i]])
		{
			if (r != apa[q[i]])
			{
				redch[q[i]] += redch[r];
				bluech[q[i]] += bluech[r];
				t1ch[q[i]] += t1ch[r];
				redt1bej[q[i]] += redt1bej[r] + abs(t1ch[r] - redch[r]);
				bluet1bej[q[i]] += bluet1bej[r] + abs(t1ch[r] - bluech[r]);
			}
		}
	}
	if (t1ch[1] == redch[1])
	{
		if (t1ch[1] == bluech[1])
		{
			cout << min(redt1bej[1], bluet1bej[1]) << endl;
		}
		else
		{
			cout << redt1bej[1] << endl;
		}
	}
	else
	{
		if (t1ch[1] == bluech[1])
		{
			cout << bluet1bej[1] << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
