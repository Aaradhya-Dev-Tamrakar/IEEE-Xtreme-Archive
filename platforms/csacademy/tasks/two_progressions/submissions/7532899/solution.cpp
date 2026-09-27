#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e5;
const int INF = 0x3f3f3f3f;

int t, n, a[MXN];
pair< int, int > ns;
vector< int > cnt[2];
vector< int > b;
bool vis[MXN];

int read(){
	int x = 0;
	char c = getchar();
	for(;c < '0' || c > '9';) c = getchar();
	for(;c >= '0' && c <= '9';c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	return x; 
}

void chck(int s, int e, int d){
//	printf("chck %d %d %d\n", s, e, d);
	if(d == 0 || (e - s) % d) return;
	int i;
	for(i = 0;i < n;++i) vis[i] = 0;
	int pre = s;
	for(i = 0;i < n;++i)
		if(pre < a[i]) break;
		else if(pre == a[i]){
			vis[i] = 1;
			if(pre == e) break;
			pre += d;
		}
	if(pre != e) return;
	b.clear();
	for(i = 0;i < n;++i)
		if(!vis[i]) b.push_back(a[i]);
//	printf("b : ");
//	for(auto x : b) printf("%d ", x);
//	putchar('\n');
	if(b.size() < 2) return;
	int dst = b[1] - b[0];
	if(dst == 0) return;
	for(i = 1;i < b.size();++i)
		if(b[i] - b[i - 1] != dst) return;
//	printf(":::OK %d %d %d\n", s, e, d);
	if(s == a[0]) ns = min(ns, {d, (e - s) / d + 1});
	if(b[0] == a[0]) ns = min(ns, {b[1] - b[0], b.size()});
}

void work(int x, int y){
	if(x == 0 || y == 0) return; 
	int i;
//	printf("work %d %d\n", x, y); 
	for(i = 0;i < n;++i) vis[i] = 0;
	int pre = a[n - 1];
	for(i = n - 1;i >= 0;--i)
		if(pre > a[i]) break;
		else if(pre == a[i]){
			vis[i] = 1;
			pre -= y;
		}
	for(i = n - 1;i > 1;--i)
		if(!vis[i]) break;
	chck(a[0], a[i], x);
}

int main(){
	int i, s;
	for(t = read();t;--t){
		n = read();
		for(i = 0;i < n;++i) a[i] = read();
		ns = {INF, INF};
		if(n == 4){
			chck(a[0], a[1], a[1] - a[0]);
			chck(a[0], a[2], a[2] - a[0]);
			chck(a[0], a[3], a[3] - a[0]);
		}
		else{
			for(s = 0;s < (1 << 4);++s){
//				printf("OK %d\n", s);
				for(i = 0;i < 2;++i) cnt[i].clear();
				cnt[0].push_back(0);
				cnt[s & 1].push_back(1);
				cnt[(s & 2) >> 1].push_back(2);
				cnt[(s & 4) >> 2].push_back(n - 2);
				cnt[(s & 8) >> 3].push_back(n - 1);
				if(cnt[0].size() > 2)
					if(cnt[0].back() == 2) work(a[1] - a[0], a[n - 1] - a[n - 2]);
					else if(cnt[0][1] < 3) chck(a[cnt[0][0]], a[cnt[0].back()], a[cnt[0][1]] - a[cnt[0][0]]);
					else chck(a[cnt[0][0]], a[cnt[0].back()], a[cnt[0].back()] - a[cnt[0][cnt[0].size() - 2]]);
				else if(cnt[1][1] < 3) chck(a[cnt[1][0]], a[cnt[1].back()], a[cnt[1][1]] - a[cnt[1][0]]);
				else chck(a[cnt[1][0]], a[cnt[1].back()], a[cnt[1].back()] - a[cnt[1][cnt[1].size() - 2]]);
			}
		}
		if(ns.first == INF) puts("-1");
		else printf("%d %d %d\n", a[0], ns.first, ns.second);
	}
	return 0;
}