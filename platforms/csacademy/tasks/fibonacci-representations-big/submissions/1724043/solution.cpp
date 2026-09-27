/*
PROG: source
LANG: C++11
_____
.'     '.
/  0   0  \
|     ^     |
|  \     /  |
\  '---'  /
'._____.'
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

struct chash
{
	int operator()(int x) const
	{
		x ^= (x >> 20) ^ (x >> 12);
		return x ^ (x >> 7) ^ (x >> 4);
	}
	int operator()(long long x) const
	{
		return x ^ (x >> 32);
	}
};

template<typename T> using orderedset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename U> using hashtable = gp_hash_table<T, U, chash>;

template<class T>
void readi(T &x)
{
	T input = 0;
	bool negative = false;
	char c = ' ';
	while (c < '-')
	{
		c = getchar();
	}
	if (c == '-')
	{
		negative = true;
		c = getchar();
	}
	while (c >= '0')
	{
		input = input * 10 + (c - '0');
		c = getchar();
	}
	if (negative)
	{
		input = -input;
	}
	x = input;
}
template<class T>
void printi(T output)
{
	if (output == 0)
	{
		putchar('0');
		return;
	}
	if (output < 0)
	{
		putchar('-');
		output = -output;
	}
	int aout[20];
	int ilen = 0;
	while(output)
	{
		aout[ilen] = ((output % 10));
		output /= 10;
		ilen++;
	}
	for (int i = ilen - 1; i >= 0; i--)
	{
		putchar(aout[i] + '0');
	}
	return;
}
template<class T>
void ckmin(T &a, T b)
{
	a = min(a, b);
}
template<class T>
void ckmax(T &a, T b)
{
	a = max(a, b);
}
template<class T, class U>
T normalize(T x, U mod = 1000000007)
{
	return (((x % mod) + mod) % mod);
}
long long randomizell(long long mod)
{
	return ((1ll << 45) * rand() + (1ll << 30) * rand() + (1ll << 15) * rand() + rand()) % mod;
}
int randomize(int mod)
{
	return ((1ll << 15) * rand() + rand()) % mod;
}

#define y0 ___y0
#define y1 ___y1
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define debug(x) cerr << #x << " = " << x << endl;

const long double PI = 4.0 * atan(1.0);
const long double EPS = 1e-10;

#define MAGIC 347
#define SINF 10007
#define CO 1000007
#define INF 1000000007
#define BIG 1000000931
#define LARGE 1696969696967ll
#define GIANT 2564008813937411ll
#define LLINF 2696969696969696969ll
#define MAXN 100013

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, pii> ppp;
typedef pair<ld, ld> pdd;

int N;
int arr[MAXN];
ppp matpow[40];
set<pii> rep;

void debugset()
{
        cerr << "set contains:";
        for (auto p : rep)
        {
                for (int i = p.fi; i <= p.se; i += 2)
                {
                        cerr << ' ' << i;
                }
        }
        cerr << endl;
}
ppp get(int dif)
{
	int D = dif / 2;
	ppp res;
	if (dif % 2)
	{
		return {{D + 1, 1}, {0, 0}};
	}
	else
	{
		return {{D + 1, 1}, {INF - 1, 0}};
	}
}
ppp mul(ppp a, ppp b)
{
	ppp res;
	res.fi.fi = ((1ll * a.fi.fi * b.fi.fi + 1ll * a.fi.se * b.se.fi) % INF);
	res.fi.se = ((1ll * a.fi.fi * b.fi.se + 1ll * a.fi.se * b.se.se) % INF);
	res.se.fi = ((1ll * a.se.fi * b.fi.fi + 1ll * a.se.se * b.se.fi) % INF);
	res.se.se = ((1ll * a.se.fi * b.fi.se + 1ll * a.se.se * b.se.se) % INF);
	return res;
}
ppp mat_expo(int e)
{
	// cerr << "what's " << e << endl;
	e /= 2;
	ppp res = {{1, 0}, {0, 1}};
	if (e == 0) return res;
	for (int i = 0; i <= (31 - __builtin_clz(e)); i++)
	{
		if (e & (1 << i))
		{
			res = mul(res, matpow[i]);
		}
	}
	return res;
}
struct node
{
	node* ch[2];
	pii stor;
	ppp trans, subtrans;
	int pri;
	int subt;
	node(pii p)
	{
		pri = randomize(INF);
		ch[0] = ch[1] = nullptr;
		stor = p;
		subt = 1;
	}
	void recalc()
	{
		if (ch[0] && ch[1])
		{
			subt = ch[0] -> subt + 1 + ch[1] -> subt;
			subtrans = mul(mul(ch[0] -> subtrans, trans), ch[1] -> subtrans);
		}
		else if (ch[0])
		{
			subt = ch[0] -> subt + 1;
			subtrans = mul(ch[0] -> subtrans, trans);
		}
		else if (ch[1])
		{
			subt = 1 + ch[1] -> subt;
			subtrans = mul(trans, ch[1] -> subtrans);
		}
		else
		{
			subt = 1;
			subtrans = trans;
		}
	}
};

node *root;
ll occ;

typedef pair<node*, node*> pnn;

pnn split(node* t, int v)
{
	if (!t) return {t, t};
	t -> recalc();
	int cur = t -> stor.fi;
	if (v < cur)
	{
		pnn p = split(t -> ch[0], v);
		t -> ch[0] = p.se; t -> recalc();
		return {p.fi, t};
	}
	else
	{
		pnn p = split(t -> ch[1], v);
		t -> ch[1] = p.fi; t -> recalc();
		return {t, p.se};
	}
}
node* merge(node *l, node *r)
{
	if (!l) return r;
	if (!r) return l;
	if (l -> pri > r -> pri)
	{
		l -> ch[1] = merge(l -> ch[1], r);
		l -> recalc();
		return l;
	}
	else
	{
		r -> ch[0] = merge(l, r -> ch[0]);
		r -> recalc();
		return r;
	}
}
int lower_bound(node* t, pii p)
{
	if (!t)
	{
		return 0;
	}
	if (t -> stor >= p)
	{
		return lower_bound(t -> ch[0], p);
	}
	return (t -> ch[0] ? t -> ch[0] -> subt : 0) + 1 + lower_bound(t -> ch[1], p);
}
void terase(pii p)
{
	auto it = rep.UB(p);
	int was = prev(prev(it)) -> se;
	pnn t = split(root, p.fi - 1), t1 = split(t.se, p.fi);
	if (it == rep.end())
	{
		root = t.fi;
	}
	else
	{
		pnn t2 = split(t1.se, it -> fi);
		t2.fi -> trans = mul(get((t2.fi -> stor).fi - was), mat_expo(t2.fi -> stor.se - t2.fi -> stor.fi));
		t2.fi -> recalc();
		root = merge(t.fi, merge(t2.fi, t2.se));
	}
	return;
}
void tinsert(pii p)
{
	node* cur = new node(p);
	auto it = rep.UB(p);
	int was = prev(it) -> se;
	pnn t = split(root, p.fi);
	if (it == rep.end())
	{
		cur -> trans = mul(get(p.fi - was), mat_expo(p.se - p.fi));
		cur -> recalc();
		root = merge(t.fi, cur);
	}
	else
	{
		pnn t1 = split(t.se, it -> fi);
		t1.fi -> trans = mul(get(t1.fi -> stor.fi - p.se), mat_expo((t1.fi -> stor.se) - (t1.fi -> stor.fi)));
		t1.fi -> recalc();
		cur -> trans = mul(get(p.fi - was), mat_expo(p.se - p.fi));
		cur -> recalc();
		root = merge(merge(t.fi, cur), merge(t1.fi, t1.se));
	}
}
void smartinsert(int L, int R)
{
	if (L > R) return;
	int lt = L, rt = R;
	auto it = rep.LB({R + 2, -INF});
	if (it != rep.end() && it -> fi == R + 2)
	{
		rt = it -> se;
		rep.erase(it);
		terase({R + 2, rt});
	}
	it = prev(rep.LB({L - 1, -INF}));
	if (it -> se != 0 && it -> se == L - 2)
	{
		lt = it -> fi;
		rep.erase(it);
		terase({lt, L - 2});
	}
	tinsert({lt, rt});
	rep.insert({lt, rt});
	return;
}
void smartdelete(int L, int R)
{
	if (L > R) return;
	auto it = prev(rep.LB({L + 1, -INF}));
	int lt = it -> fi, rt = it -> se;
	rep.erase(it);
	terase({lt, rt});
	if (lt <= L - 2)
	{
		tinsert({lt, L - 2});
		rep.insert({lt, L - 2});
	}
	if (R + 2 <= rt)
	{
		tinsert({R + 2, rt});
		rep.insert({R + 2, rt});
	}
	return;
}
bool chk(int x)
{
	if (x == 0) return false;
	auto it = prev(rep.LB({x + 1, -INF}));
	return ((it -> se != 0) && (it -> fi <= x) && (it -> se >= x) && ((x + it -> fi) % 2 == 0));
}
void ins(int x)
{
	if (x < 0)
	{
		return;
	}
	if (x == 0)
	{
		x = 1;
	}
	if (chk(x + 1))
	{
		// cerr << "help insert " << x << " yep you have " << x + 1 << endl;
		// debugset();
		int rt = (prev(rep.LB({x + 2, -INF}))) -> se;
		smartdelete(x + 1, rt);
		smartinsert(rt + 1, rt + 1);
	}
	else if (chk(x - 1))
	{
		//delete x - 1, so it causes a chain reaction
		smartdelete(x - 1, x - 1);
		ins(x + 1);
	}
	else if (chk(x))
	{
		if (x == 1)
		{
			smartdelete(x, x);
			ins(2);
		}
		else if (x == 2)
		{
			smartdelete(x, x);
			ins(3);
			ins(1);
		}
		else
		{
			// cerr << "ins " << x + 1 << " ins " << x - 2 << endl;
			//u know x + 1 is safe right..., bc u cant have x + 1, x
			//
			// cerr << "ins " << x << endl;
			// debugset();
			int lt = (prev(rep.LB({x + 1, -INF}))) -> fi;
			smartdelete(lt, x);
			smartinsert(lt + 1, x - 1);
			//delete(x - 2); insert(x - 1); insert(x - 4);
			ins(lt - 2);
			ins(x + 1);
			//insert(x + 1); insert(x - 2);
		}
	}
	else
	{
		smartinsert(x, x);
	}
	return;
}

int32_t main()
{
	// ios_base::sync_with_stdio(0);
	srand(time(0));
	//     cout << fixed << setprecision(10);
	//     cerr << fixed << setprecision(10);
	if (fopen("input.in", "r"))
	{
		freopen ("input.in", "r", stdin);
		freopen ("output.out", "w", stdout);
	}
	rep.insert({0, 0});
	root = new node({0, 0});
	root -> trans = {{1, 0}, {0, 1}};
	root -> recalc();
	matpow[0] = {{2, 1}, {INF - 1, 0}};
	for (int i = 1; i <= 40; i++)
	{
		matpow[i] = mul(matpow[i - 1], matpow[i - 1]);
	}
	readi(N);
	for (int i = 0; i < N; i++)
	{
		readi(arr[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ins(arr[i]);
		// debugset();
		ppp cup = root -> subtrans;
		int ans = (cup.fi.fi + cup.se.fi) % INF;
		printi(ans); putchar('\n');
	}
	cerr << "time elapsed = " << (clock() / (CLOCKS_PER_SEC / 1000)) << " ms" << endl;
	return 0;
}
