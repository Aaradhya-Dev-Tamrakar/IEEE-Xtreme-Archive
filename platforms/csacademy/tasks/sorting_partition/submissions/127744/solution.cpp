#include <cstdio>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int n, x, m;
stack <pair<int,int>> sp;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (sp.empty())
			sp.push(make_pair(x, x));
		else
			if (sp.top().second <= x)
				sp.push(make_pair(sp.top().second, x));
			else
			{
				m = sp.top().second;
				while (!sp.empty() && sp.top().first > x)
					sp.pop();
				if (sp.empty())
					sp.push(make_pair(x, m));
				else
					sp.top().second = m;
			}
	}

	cout << sp.size();
//	system("PAUSE");
	return 0;
}