#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};
const int BUF_SZ = 1 << 15;
inline namespace Input {
    char buf[BUF_SZ];
    int pos;
    int len;
    char next_char() {
    	if (pos == len) {
    		pos = 0;
    		len = (int)fread(buf, 1, BUF_SZ, stdin);
    		if (!len) { return EOF; }
    	}
    	return buf[pos++];
    }

    int read_int() {
    	int x;
    	char ch;
    	int sgn = 1;
    	while (!isdigit(ch = next_char())) {
    		if (ch == '-') { sgn *= -1; }
    	}
    	x = ch - '0';
    	while (isdigit(ch = next_char())) { x = x * 10 + (ch - '0'); }
    	return x * sgn;
    }
}
inline namespace Output {
    char buf[BUF_SZ];
    int pos;
    
    void flush_out() {
    	fwrite(buf, 1, pos, stdout);
    	pos = 0;
    }
    
    void write_char(char c) {
    	if (pos == BUF_SZ) { flush_out(); }
    	buf[pos++] = c;
    }
    
    void write_int(int x) {
    	static char num_buf[100];
    	if (x < 0) {
    		write_char('-');
    		x *= -1;
    	}
    	int len = 0;
    	for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
    	write_char((char)('0' + x));
    	while (len) { write_char(num_buf[--len]); }
    	write_char('\n');
    }
    
    // auto-flush output when program exits
    void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output

int N;

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0);
    cin.tie(0);
    // scanf("%d", &N);
    // cin >> N;
    N = read_int();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int x;
        // scanf("%d", &x);
        // cin >> x;
        x = read_int();
        ans ^= x;
    }
    cout << ans << endl;
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
    cerr << "Time: " << duration.count() << "ms" << endl;
    return 0;
}