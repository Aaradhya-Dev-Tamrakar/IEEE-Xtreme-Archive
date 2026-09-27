#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

ll f(int n) {
    if (n<=1) return n;
    ll res = f(n/2);
    if (n%2==0) n--;
    res += 1LL * (n+1) * (n+1) / 4;
    return res;
}

void test() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", f(b) - f(a-1));
}

int main() {
	int ttn;
	scanf("%d", &ttn);
	while (ttn--) test();
	return 0;
}
