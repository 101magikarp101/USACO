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

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

template <class T> class LzSegTree {
  private:
    const T DEFAULT = 0;
    vector<T> tr;
    vector<T> lza, lzs;
    int len;
    pll merge(ll a, ll s, ll a2, ll s2) {
        if (s != DEFAULT) return {DEFAULT, s};
        else if (s2 == DEFAULT) return {a2+a, DEFAULT};
        else return {DEFAULT, s2+a};
    }
    void push(int n, int s, int m, int e) {
        if (lza[n] == DEFAULT && lzs[n] == DEFAULT) return;
        auto [x, y] = merge(lza[n], lzs[n], lza[2*n], lzs[2*n]);
        lza[2*n] = x;
        lzs[2*n] = y;
        auto [x2, y2] = merge(lza[n], lzs[n], lza[2*n+1], lzs[2*n+1]);
        lza[2*n+1] = x2;
        lzs[2*n+1] = y2;
        if (lzs[n] != DEFAULT) {
            tr[n*2] = (ll)(m-s+1)*lzs[n];
            tr[n*2+1] = (ll)(e-m)*lzs[n];
        } else if (lza[n] != DEFAULT) {
            tr[n*2] += (ll)(m-s+1)*lza[n];
            tr[n*2+1] += (ll)(e-m)*lza[n];
        }
        lza[n] = DEFAULT;
        lzs[n] = DEFAULT;
    }
    void _range_add(int n, int s, int e, int l, int r, T ad, T se) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            if (ad != DEFAULT) {
                tr[n] += (ll)(e-s+1)*ad;
            } else if (se != DEFAULT) {
                tr[n] = (ll)(e-s+1)*se;
            }
            auto [x, y] = merge(ad, se, lza[n], lzs[n]);
            lza[n] = x;
            lzs[n] = y;
            return;
        }
        int m = (s + e) / 2;
        push(n, s, m, e);
        _range_add(n*2, s, m, l, r, ad, se);
        _range_add(n*2+1, m+1, e, l, r, ad, se);
        tr[n] = tr[n*2] + tr[n*2+1];
    }
    T _query(int n, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tr[n];
        int m = (s + e) / 2;
        push(n, s, m, e);
        T left = _query(n*2, s, m, l, r);
        T right = _query(n*2+1, m+1, e, l, r);
        return left + right;
    }
  public:
    LzSegTree(vt<T> &a) {
        len = 1;
        while (len < sz(a)) len *= 2;
        tr.assign(len*2, DEFAULT);
        lza.assign(len*2, DEFAULT);
        lzs.assign(len*2, DEFAULT);
        rep(i,0,sz(a)) tr[i+len] = a[i];
        rrep(i,len-1,1) {
            tr[i] = tr[i*2] + tr[i*2+1];
        }
    }
    void add(int idx, T val) {
        _add(1, 0, len-1, idx, val);
    }
    void range_add(int l, int r, T x, T y) {
        _range_add(1, 0, len-1, l, r, x, y);
    }
    // query range [l, r]
    T query(int l, int r) {
        return _query(1, 0, len-1, l, r);
    }
};

int N, Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    vt<ll> a(N);
    rep(i,0,N) cin >> a[i];
    LzSegTree<ll> seg(a);
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r; ll x; cin >> l >> r >> x;
            seg.range_add(l-1, r-1, x, 0);
        } else if (t == 2) {
            int l, r; ll y; cin >> l >> r >> y;
            seg.range_add(l-1, r-1, 0, y);
        } else {
            int l, r; cin >> l >> r;
            cout << seg.query(l-1, r-1) << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}