#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
template <class T> using vvt = vt<vt<T>>;
template <class T> using vvvt = vt<vvt<T>>;
template <class T> using vvvvt = vt<vvvt<T>>;
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
#define repl(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define rrepl(i,a,b) for(ll i=a;i>=b;i--)
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int C = uniform_int_distribution<int>(0.1*MOD2, 0.9*MOD2)(rng);
// const int C = 100;
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int ad(int a, int b) {
    a+=b;
    if (a>=MOD2) a-=MOD2;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD2;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD2);
}

int binpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b&1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD2-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

int N, Q;
int ip[200005], p[200005];

void pre(int n) {
    p[0] = 1;
    rep(i, 1, n + 1) {
        p[i] = mul(p[i - 1], C);
    }
    ip[0] = 1;
    int in = inv(C);
    rep(i, 1, n + 1) {
        ip[i] = mul(ip[i - 1], in);
    }
}

template <class T> class BIT {
    // MUST be 1-indexed
public:
    vector<T> bit;
    int size;
    BIT(int n) {size = n; bit.resize(n + 1);}
    void upd(int i, T x) {
        for (; i <= size; i += i & -i) bit[i] = ad(bit[i], x);
    }
    // returns sum of [1, i]
    T sum(int i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s = ad(s, bit[i]);
        return s;
    }
    // returns sum of [l, r]
    T sum(int l, int r) {
        return sub(sum(r), (l > 1 ? sum(l - 1) : 0));
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    string s; cin >> s;
    BIT<int> b0(N), b1(N);
    pre(N);
    rep(i,0,N) {
        int c = s[i]-'a'+1;
        b0.upd(i+1, mul(p[i], c));
        b1.upd(i+1, mul(ip[i], c));
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int i; char c; cin >> i >> c;
            i--;
            int diff = sub(c, s[i]);
            s[i] = c;
            b0.upd(i + 1, mul(p[i], diff));
            b1.upd(i + 1, mul(ip[i], diff));
        } else {
            int l, r; cin >> l >> r;
            int res0 = b0.sum(l,r);
            int res1 = b1.sum(l,r);
            int len = r-l+1;
            res0 = mul(res0, ip[l-1]);
            res1 = mul(res1, p[l+len-2]);
            // cout << "res0: " << res0 << ", res1: " << res1 << endl;
            cout << (res0 == res1 ? "YES" : "NO") << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}