#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/** FastIO Interface */
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void flush();


inline ll ans(ll &n) {
	ll ans = 0;
	while (n > 1) {
		const ll m = n+(n&1);
		ans += m*m>>2, n >>= 1;
	} return ans + n;
}

void solve() {
	ll l = readInt()-1, r = readInt();
	writeInt(ans(r)-ans(l), '\n');
}

int main() {
	int T = readInt();
	while (T--) solve();
}




/** Read */

static const int buf_size = 3 << 20;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		flush();
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0) writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--) writeChar(s[n]);
	if (end) writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s) writeChar(*s++);
}

inline void flush() {
	fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

// Automatically flushes at end of program
struct Flusher {
	~Flusher() { flush(); }
} flusher;