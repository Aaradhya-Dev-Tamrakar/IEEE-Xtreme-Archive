//Challenge: Accepted
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define ll long long
#define maxn 500005
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int a[maxn], pref[maxn], seg[4 * maxn], sp[4 * maxn], tag[4 * maxn];
const int inf = 1<<30;
struct obj{
	int l, r, id;
	obj(int a, int b, int c) {
		l = a, r = b, id = c;
	}
	obj() {
		l = 0, r = 0, id = 0;
	}
};
vector<obj> que;
inline bool cmp(obj x, obj y) {
	return x.r< y.r;
}
vector<int> stk;
void init(int cur, int l, int r) {
	if (r <= l) return;
	if (r - l == 1) {
		seg[cur] = pref[l];
		sp[cur] = l;
		
	//	cout << l << " " << r << " " << seg[cur]  << " " << sp[cur] << endl;
		return;
	}
	int mid = (l + r) / 2;
	init(cur * 2, l, mid), init(cur * 2 + 1, mid, r);
	seg[cur] = min(seg[cur * 2], seg[cur * 2 + 1]);
	sp[cur] = seg[cur * 2] <= seg[cur * 2 + 1] ? sp[cur * 2] : sp[cur * 2 + 1];
	//cout << l << " " << r << " " << seg[cur]  << " " << sp[cur] << endl;
}
void modify(int cur, int l, int r, int ql, int qr, int val) {
	if (r <= l || qr <= l || ql >= r) return;
	if (ql <= l && qr >= r) {
		tag[cur] += val;
		return;
	}
	int mid = (l + r) / 2;
	modify(cur * 2, l, mid, ql, qr, val);
	modify(cur * 2 + 1, mid, r, ql, qr, val);
	seg[cur] = min(seg[cur * 2] + tag[cur * 2], seg[cur * 2 + 1] + tag[cur * 2 + 1]);
	sp[cur] = seg[cur * 2] + tag[cur * 2] <= seg[cur * 2 + 1] + tag[cur * 2 + 1] ? sp[cur * 2] : sp[cur * 2 + 1];
}

pii query(int cur, int l, int r, int ql, int qr) {
	if (r <= l || ql >= r || qr <= l) return make_pair(inf, -1);
	if (ql <= l && qr >= r) return make_pair(seg[cur] + tag[cur], sp[cur]);
	int mid = (l + r) / 2;
	pii ret = min(query(cur * 2, l, mid, ql, qr), query(cur * 2 + 1, mid, r, ql, qr));
	return make_pair(ret.ff + tag[cur], ret.ss);
}
int ans[maxn];

int main() {
	io
	int n;
	cin >> n;
	string s;
	cin >> s;
	int q;
	cin >> q;
	for (int i = 0;i < n;i++) {
		if (s[i] == 'C') a[i] = 1;
		else a[i] = -1;
		pref[i] = a[i] + (i ? pref[i - 1] : 0);
	}
	for (int i = 0;i < q;i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		que.push_back(obj(l, r, i));
	}
	sort(que.begin(), que.end(), cmp);
	int ind = 0;
	init(1, 0, n);
	for (int i = 0;i < n;i++) {
		if (a[i] == -1) {
			stk.push_back(i);
			modify(1, 0, n, i, n, 1);
		}
		while (stk.size() && pref[i] > pref[stk.back()]){
			modify(1, 0, n, stk.back(), n, -1);
			stk.pop_back();
		}
		
		while (ind < q && que[ind].r <= i) {
		//	cout << que[ind].l << " " << que[ind].r << endl;
		//	for (int i:stk) cout << i << " ";
		//	cout << endl;
			pii pos = query(1, 0, n, que[ind].l, que[ind].r + 1);
			int num = (lower_bound(stk.begin(), stk.end(), que[ind].l) - stk.begin());
			ans[que[ind].id] = stk.size() - num + max(0, (que[ind].l ? pref[que[ind].l - 1] + num: 0) - pos.ff);	
			ind++;
		}			
		
	}	
	for (int i = 0;i < q;i++) cout << ans[i] << "\n";
}
/*
13
TTTTCTTTCCTTT
2
1 13
5 13

*/