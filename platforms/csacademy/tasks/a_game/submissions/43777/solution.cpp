#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.1415926535897932384626
#define LMAX 9223372036854775807
#define ll long long
#define fi first
#define sec second
#define pii pair<int, int>
int n, m, k, x, y, sum, ans, r;
char s[100005];
int main () {
	scanf("%d %s", &n, s);
	for (int i=0; i<n; i++) {
		if (s[i]=='B') {
			sum++;
		} else {
			r^=sum;
			sum=0;
			x++;
		}
	}
	if (sum) r^=sum;
	if (x%2==0) printf("-1\n");
	else if (r==0) printf("B\n");
	else printf("A\n");
	return 0;
}