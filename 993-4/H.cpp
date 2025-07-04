#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define each(i,a) for(auto &i:a)
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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

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

    void write_ll(ll x) {
        static char num_buf[100];
        if (x < 0) {
            write_char('-');
            x *= -1;
        }
        int len = 0;
        for (; x >= 10; x /= 10) { num_buf[len++] = (char)('0' + (x % 10)); }
        write_char((char)('0' + x));
        while (len) { write_char(num_buf[--len]); }
        // write_char('\n');
    }
    
    // auto-flush output when program exits
    void init_output() { assert(atexit(flush_out) == 0); }
}  // namespace Output

ll T, N, Q;
ll a[2005][2005];
ll p[2005][2005];
ll pre1[2005][2005], pre2[2005][2005];

ll query(int x1, int y1, int x2, int y2) {
    ll res1 = pre1[x2][y2]-pre1[x1-1][y2]-pre1[x2][y1-1]+pre1[x1-1][y1-1]; // 34, 34, 34
    ll res2 = res1-(ll)(y1-1)*(p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1]); // 12, 12, 12
    ll res3 = pre2[x2][y2]-pre2[x1-1][y2]-pre2[x2][y1-1]+pre2[x1-1][y1-1];
    ll res4 = res3-(ll)(x1)*(p[x2][y2]-p[x1-1][y2]-p[x2][y1-1]+p[x1-1][y1-1]);
    res4 *= (ll)(y2-y1+1);
    // cout << "res1: " << res1 << " res2: " << res2 << " res3: " << res3 << " res4: " << res4 << endl;
    ll res = res2+res4;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // cin >> T;
    T = read_int();
    while (T--) {
        // cin >> N >> Q;
        N = read_int(), Q = read_int();
        rep(i,1,N+1) {
            rep(j,1,N+1) {
                // cin >> a[i][j];
                a[i][j] = read_int();
            }
        }
        rep(i,1,N+1) {
            rep(j,1,N+1) {
                p[i][j] = p[i-1][j]+p[i][j-1]-p[i-1][j-1]+a[i][j];
                pre1[i][j] = pre1[i-1][j]+pre1[i][j-1]-pre1[i-1][j-1]+a[i][j]*(ll)j;
                pre2[i][j] = pre2[i-1][j]+pre2[i][j-1]-pre2[i-1][j-1]+a[i][j]*(ll)i;
            }
        }
        while (Q--) {
            // int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            int x1 = read_int(), y1 = read_int(), x2 = read_int(), y2 = read_int();
            ll ans = query(x1, y1, x2, y2);
            // cout << ans << " ";
            write_ll(ans);
            write_char(' ');
        }
        // cout << endl;
        write_char('\n');
    }
    flush_out();
    return 0;
}