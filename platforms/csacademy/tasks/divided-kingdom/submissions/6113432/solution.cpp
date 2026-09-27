#include<bits/stdc++.h>

using namespace std;

int n = 0 , m = 0 , ans = 0 , cnt = 0 , flag = false;

array<int , 100100> head , col;

struct Node{
	int to;
	int nxt;
	int val;
}; 

array<Node , 500100> edge;

struct Line{
	int x;
	int y;
	int c;
};

array<Line , 500100> line;

bool operator < (const Line &x , const Line &y) {return x.c < y.c;}
bool operator > (const Line &x , const Line &y) {return x.c > y.c;}

void new_line(int a , int b , int c)
{
	edge[++ cnt].to = b;
	edge[cnt].nxt = head[a];
	edge[cnt].val = c;
	head[a] = cnt;
	return;
}

void dfs(int x)
{
	for(int e = head[x];e;e = edge[e].nxt)
	{
		if(edge[e].val >= ans) continue;
		
		int to = edge[e].to;
		if(col[to] == -1) col[to] = col[x] ^ 1 , dfs(to);
		else if (col[to] != (col[x] ^ 1)) flag = 1;
	}
}

bool check(int x)
{
	memset(head.data() , 0 , sizeof head);
	cnt = flag = 0;
	
	for(int i = 1;i <= x;++ i) new_line(line[i].x , line[i].y , line[i].c) , new_line(line[i].y , line[i].x , line[i].c);
	
	fill(col.data() + 1 , col.data() + n + 1 , -1);
	
	for(int i = 1;i <= n;++ i) if(col[i] == -1) col[i] = 0 , dfs(i);
	
	return flag;
}

signed main()
{
	cin >> n >> m;
	
	for(int i = 1;i <= m;++ i)
	{
		cin >> line[i].x >> line[i].y >> line[i].c;
		new_line(line[i].x , line[i].y , line[i].c);
		new_line(line[i].y , line[i].x , line[i].c);
	}
	
	ans = 1e9;
	
	if(n <= 2)
	{
		cout << "-1" << endl;
		return 0;
	}
	
	for(int x = 1;x <= n;++ x)
	{
		int minx1 = 1e9 , minx2 = 1e9;
		for(int e = head[x];e;e = edge[e].nxt)
		{
			if(edge[e].val < minx1) minx2 = minx1 , minx1 = edge[e].val;
			else if(edge[e].val <= minx2) minx2 = edge[e].val;
		}
		
		ans = min(ans , minx1 + minx2);
	}
	
	sort(line.data() + 1 , line.data() + m + 1);
	
	int l = 1 , r = m , res = 0;
	
	line[0].c = 1e9;
	
	while(l <= r)
	{
		int mid = l + ((r - l) >> 1);
		if(check(mid))
		{
			res = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	ans = min(line[res].c , ans);
	
	cout << (ans >= 1e9 ? -1 : ans) << endl;
	
	return 0;
}