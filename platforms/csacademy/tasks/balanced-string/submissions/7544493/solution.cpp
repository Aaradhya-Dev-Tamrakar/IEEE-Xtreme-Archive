#include <bits/stdc++.h>
using namespace std;

int t;
string s;
vector< int > ip;
vector< int > len;

bool chck(string s){
	if(s.size() < 2) return 1;
	int i;
	bool oka = 0, okb = 0;
	for(i = 0;i < s.size();++i)
		if(s[i] == s[(i + 1) % s.size()])
			if(s[i] == 'A') oka = 1;
			else okb = 1;
	if(oka && okb) return 0;
	int cnta = 0, cntb = 0;
	for(i = 0;i < s.size();++i)
		if(s[i] == 'A') ++cnta;
		else ++cntb;
	if(cnta < cntb){
		for(i = 0;i < s.size();++i)
			if(s[i] == 'A') s[i] = 'B';
			else s[i] = 'A';
		swap(cnta, cntb);
	}
	if(cntb == 0) return 1;
	int mn = s.size(), mx = 0;
	ip.clear();
	for(i = 0;i < s.size();++i)
		if(s[i] == 'B') ip.push_back(i);
	len.clear();
	for(i = 1;i < ip.size();++i) len.push_back(ip[i] - ip[i - 1] - 1);
	len.push_back(s.size() - ip.back() + ip[0] - 1);
	for(auto x : len){
		mn = min(mn, x);
		mx = max(mx, x);
	}
	if(mn == mx) return 1;
	if(mx - mn > 1) return 0;
	string t = "";
	for(auto x : len)
		if(x == mn) t += 'A';
		else t += 'B';
	return chck(t);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(cin >> t;t;--t){
		cin >> s;
		cout << chck(s) << '\n';
	}
	return 0;
}//3498069083469034