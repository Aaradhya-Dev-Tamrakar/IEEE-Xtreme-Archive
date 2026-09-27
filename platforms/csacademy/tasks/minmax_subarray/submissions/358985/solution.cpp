#include <bits/stdc++.h>
using namespace std;

const int ac = 5e3 + 1;
int A[ac];
vector<int> B, C;

int main()
{
	int n; cin >> n;
	int l = 1e9, h = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		l = min(l, A[i]);
		h = max(h, A[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (A[i] == l) B.push_back(i);
		if (A[i] == h) C.push_back(i);
	}
	
	int m = 1e9, j = 0;
	for (int i = 0; i < B.size(); i++)
	{
		while (C[j] < B[i] && j < C.size() - 1) j++;
		if (j != 0) m = min(m, abs(C[j - 1] - B[i]));
		m = min(m, abs(C[j] - B[i]));
	}
	cout << m + 1 << '\n';
}
