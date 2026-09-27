#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;

const int maxn = 0;
int n;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	cin >> n;
	int a = 0 , b = 0;
	string z;
	cin >> z;
	for(int i=0;i<n;i++)
	{
		if(z[i] == 'A') a++;
		else b++;
	}
	if(a % 2 == 0)
	{
		cout << -1;
		return 0;
	}
	vector < int > v;
	int ct = 0;
	bool in = false;
	for(int i=0;i<n;i++)
	{
		if(z[i] == 'B')
		{
			in = true;
			ct++;
		}
		else
		{
			if(in)
			{
				v.push_back(ct);
				ct = 0;
				in = false;
			}
		}
	}
	if(in) v.push_back(ct);
	if(v.size() == 0) cout << "B" << endl;
	else
	{
		int lol = v[0];
		for(int i=1;i<v.size();i++) lol ^= v[i];
		if(!lol) cout << "B" << endl;
		else cout << "A" << endl;
	}
}