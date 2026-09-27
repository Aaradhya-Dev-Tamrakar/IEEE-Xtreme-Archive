#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#include "bits/stdc++.h" // define macro "/D__MAI"

using namespace std;
typedef long long int ll;

#define xprintf(fmt,...) fprintf(stderr,fmt,__VA_ARGS__)
#define debugv(v) {printf("L%d %s > ",__LINE__,#v);for(auto e:v){cout<<e<<" ";}cout<<endl;}
#define debuga(m,w) {printf("L%d %s > ",__LINE__,#m);for(int x=0;x<(w);x++){cout<<(m)[x]<<" ";}cout<<endl;}
#define debugaa(m,h,w) {printf("L%d %s >\n",__LINE__,#m);for(int y=0;y<(h);y++){for(int x=0;x<(w);x++){cout<<(m)[y][x]<<" ";}cout<<endl;}}
#define ALL(v) (v).begin(),(v).end()
#define repeat(cnt,l) for(auto cnt=0ll;(cnt)<(l);++(cnt))
#define iterate(cnt,b,e) for(auto cnt=(b);(cnt)!=(e);++(cnt))
#define MD 1000000007ll
#define PI 3.1415926535897932384626433832795
#define EPS 1e-12
template<typename T1, typename T2> ostream& operator <<(ostream &o, const pair<T1, T2> p) { o << "(" << p.first << ":" << p.second << ")"; return o; }
template<typename iterator> inline size_t argmin(iterator begin, iterator end) { return distance(begin, min_element(begin, end)); }
template<typename iterator> inline size_t argmax(iterator begin, iterator end) { return distance(begin, max_element(begin, end)); }
template<typename T> T& maxset(T& to, const T& val) { return to = max(to, val); }
template<typename T> T& minset(T& to, const T& val) { return to = min(to, val); }
void bye(string s, int code = 0) { cout << s << endl; exit(0); }
mt19937_64 randdev(8901016);
inline ll rand_range(ll l, ll h) {
    return uniform_int_distribution<ll>(l, h)(randdev);
}

#ifdef __MAI
#define getchar_unlocked getchar
#define putchar_unlocked putchar
#endif
#ifdef __VSCC
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
#endif
namespace {
#define isvisiblechar(c) (0x21<=(c)&&(c)<=0x7E)
    class MaiScanner {
    public:
        template<typename T> void input_integer(T& var) {
            var = 0;
            T sign = 1;
            int cc = getchar_unlocked();
            for (; cc<'0' || '9'<cc; cc = getchar_unlocked())
                if (cc == '-') sign = -1;
            for (; '0' <= cc&&cc <= '9'; cc = getchar_unlocked())
                var = (var << 3) + (var << 1) + cc - '0';
            var = var*sign;
        }
        inline int c() { return getchar_unlocked(); }
        inline MaiScanner& operator>>(int& var) {
            input_integer<int>(var);
            return *this;
        }
        inline MaiScanner& operator>>(long long& var) {
            input_integer<long long>(var);
            return *this;
        }
        inline MaiScanner& operator>>(string& var) {
            int cc = getchar_unlocked();
            for (; !isvisiblechar(cc); cc = getchar_unlocked());
            for (; isvisiblechar(cc); cc = getchar_unlocked())
                var.push_back(cc);
            return *this;
        }
        template<typename IT> void in(IT begin, IT end) {
            for (auto it = begin; it != end; ++it) *this >> *it;
        }
    };
    class MaiPrinter {
    public:
        template<typename T>
        void output_integer(T var) {
            if (var == 0) {
                putchar_unlocked('0');
                return;
            }
            if (var < 0) {
                putchar_unlocked('-');
                var = -var;
            }
            char stack[32];
            int stack_p = 0;
            while (var) {
                stack[stack_p++] = '0' + (var % 10);
                var /= 10;
            }
            while (stack_p)
                putchar_unlocked(stack[--stack_p]);
        }
        inline MaiPrinter& operator<<(char c) {
            putchar_unlocked(c); return *this;
        }
        inline MaiPrinter& operator<<(int var) {
            output_integer<int>(var); return *this;
        }
        inline MaiPrinter& operator<<(long long var) {
            output_integer<long long>(var); return *this;
        }
        inline MaiPrinter& operator<(int var) {
            output_integer<int>(var);
            putchar_unlocked(' ');
            return *this;
        }
        inline MaiPrinter& operator<(long long var) {
            output_integer<long long>(var);
            putchar_unlocked(' ');
            return *this;
        }
        inline MaiPrinter& operator<<(const string& str) {
            const char* p = str.c_str();
            const char* l = p + str.size();
            while (p < l) putchar_unlocked(*p++);
            return *this;
        }
        inline MaiPrinter& operator<<(char* str_p) {
            while (*str_p) putchar_unlocked(*(str_p++));
            return *this;
        }
    };
}
MaiScanner scanner;
MaiPrinter printer;

template<typename T> inline T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> inline T lcm(T a, T b) { return a * b / gcd(a, b); }

ll m, n, kei;

ll aa[100010];

//vector<pair<int, ll>> queries;

int main() {

    scanner >> n >> m;
    //queries.reserve(m);

    scanner.in(aa, aa + n);

    ll g = aa[0];
    for (int i = 1; i < n; ++i) {
        g = gcd(g, aa[i]);
    }

    repeat(i, m) {
        ll x, y;
        scanner >> x >> y;
        --x;
        //queries.emplace_back(x, y);
        //assert(aa[x] % y == 0);
        aa[x] /= y;
        g = gcd(g, aa[x]);
        printer << g << '\n';
    }


    return 0;
}