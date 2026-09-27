#include<bits/stdc++.h>
// typedef
using i32 = std::int32_t;
using i64 = std::int64_t;
using i128 = __int128_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using u128 = __uint128_t;
using f32 = float_t;
using f64 = double_t;
using f128 = __float128;
// trans base
template<typename T> T base1_to_base0(T x){ return x - 1; }
template<typename T> T base0_to_base1(T x){ return x + 1; }
//
template<typename T> void let(T(*func)(T), T& x){ x = func(x); }
template<typename T> void check(const T&(*func)(const T&, const T&), T& lhs, T rhs){ lhs = func(lhs, rhs); }
// bitwise
template<typename T> T getbit(T x, i32 b){ return (x >> b) & 1; }

#define multitests

bool calc(std::string s){
	i32 n = s.size();
	if(std::count(s.begin(), s.end(), 'A') == n or std::count(s.begin(), s.end(), 'B') == n){
		return true;
	}
	if(std::count(s.begin(), s.end(), 'A') > std::count(s.begin(), s.end(), 'B')){
		for(auto& x : s) x ^= 'A' ^ 'B';
	}
	i32 i = 0; while(s[i] == 'B') i++;
	s = s.substr(i) + s.substr(0, i);
	
	i32 maxa = -1e9, mina = 1e9, maxb = -1e9, minb = 1e9;
	for(i32 i = 0; i < n; i++){
		if(s[(i + n - 1) % n] == 'B'){
			i32 cnt = 0;
			i32 p = i; while(s[p] == 'A') p = (p + 1) % n, cnt++;
			check(std::max, maxa, cnt);
			check(std::min, mina, cnt);
		}
		if(s[(i + n - 1) % n] == 'A'){
			i32 cnt = 0;
			i32 p = i; while(s[p] == 'B') p = (p + 1) % n, cnt++;
			check(std::max, maxb, cnt);
			check(std::min, minb, cnt);
		}
	}

	if(maxa - mina >= 2 or maxb - minb >= 2){
		return false;
	}

	std::string v;
	for(i32 i = 0; i < s.size(); i++) if(s[(n + i - 1) % n] == 'A') {
		i32 cnt = 0;
		i32 p = i; while(s[p] == 'B') p = (p + 1) % n, cnt++;
		v.push_back(cnt == maxb ? 'A' : 'B');
	}
	return calc(v);
}

void single_test(i32 test_id){
	std::string s;
	std::cin >> s;
	std::cout << calc(s) << '\n';
}

signed main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	i32 test_id = 0;
	#ifdef multitests
	i32 T = 1;
	std::cin >> T;
	for(test_id = 0; test_id < T; test_id++)
	#endif
	{
		single_test(test_id);
	}

	return 0;
}