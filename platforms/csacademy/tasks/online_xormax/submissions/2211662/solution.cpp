#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MX 100005
#define mov(x) (1<<(x))

using namespace std;

template <typename T> void read(T& x)
{
	x = 0; char c = getchar(); bool f = 0;
	while(!isdigit(c) && c!='-') c = getchar();
	if(c == '-') f = 1, c = getchar();
	while(isdigit(c)) x = x*10+c-'0', c = getchar();
	if(f) x = -x;
}

struct TRIE
{
	int son[MX*32][2];
	int siz[MX*32];
	int cnt;
	
	void ins(int &a, int o, int x)
	{
		int t = a = ++cnt;
		memmove(son[a], son[o], sizeof(son[a]));
		siz[a] = siz[o]+1;
		for(int i=30; i>=0; i--)
		{
			son[a][(x>>i)&1] = ++cnt;
			a = son[a][(x>>i)&1];
			o = son[o][(x>>i)&1];
			memmove(son[a], son[o], sizeof(son[a]));
			siz[a] = siz[o]+1;
		}
		a = t;
	}
	
	int gmax(int a, int o, int x)
	{
		int ret = 0;
		for(int i=30; i>=0; i--)
		{
			if(siz[son[a][(x>>i)&1^1]] - siz[son[o][(x>>i)&1^1]] > 0) a = son[a][(x>>i)&1^1], o = son[o][(x>>i)&1^1], ret |= mov(i);
			else a = son[a][(x>>i)&1], o = son[o][(x>>i)&1];
		}
		return ret;
	}
} T;

int rot[MX];
int lft[MX], rgt[MX];
bool ok[MX];
int seq[MX], opr[MX];
int n;

void input()
{
	read(n);
	for(int i=1; i<=n; i++) read(seq[i]);
	for(int i=1; i<=n; i++) read(opr[i]);
}

int ans[MX];

void work()
{
	int mx = 0;
	T.ins(rot[0], 0, 0);
	for(int i=1; i<=n; i++) seq[i] ^= seq[i-1], T.ins(rot[i], rot[i-1], seq[i]);
	for(int i=n; i>=1; i--)
	{
		int x = opr[i];
		ok[x] = 1;
		if(ok[x-1]) lft[x] = lft[x-1];
		else lft[x] = x;
		if(ok[x+1]) rgt[x] = rgt[x+1];
		else rgt[x] = x;
		rgt[lft[x]] = rgt[x];
		lft[rgt[x]] = lft[x];
		if(x-lft[x] < rgt[x]-x)
			for(int i=lft[x]-1; i<x; i++)
				mx = max(mx, T.gmax(rot[rgt[x]], rot[x-1], seq[i]));
		else
			for(int i=x; i<=rgt[x]; i++)
				mx = max(mx, T.gmax(rot[x-1], rot[lft[x]-2], seq[i]));
		ans[i] = mx;
	}
	for(int i=1; i<=n; i++) printf("%d\n", ans[i]);
}

int main()
{
	input();
	work();
	return 0;
}