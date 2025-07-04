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

int ad(int a, int b) {
    a+=b;
    if (a>=MOD) a-=MOD;
    return a;
}

int sub(int a, int b) {
    a-=b;
    if (a<0) a+=MOD;
    return a;
}

int mul(int a, int b) {
    return (int)((a*1LL*b)%MOD);
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
    return binpow(a, MOD-2);
}

int di(int a, int b) {
    return mul(a, inv(b));
}

template <class T> class LzSegTree {
  private:
    const pii DEFAULT = {1,0};
    vector<int> tr;
    vector<pii> lz;
    int len;
    pii merge(pii a, pii b) {
        return {mul(a.x, b.x), ad(mul(a.y, b.x), b.y)};
    }
    void push(int n, int s, int m, int e) {
        if (lz[n] == DEFAULT) return;
        lz[n*2] = merge(lz[n*2], lz[n]);
        lz[n*2+1] = merge(lz[n*2+1], lz[n]);
        tr[n*2] = ad(mul(tr[n*2], lz[n].x), mul(lz[n].y, m - s + 1));
        tr[n*2+1] = ad(mul(tr[n*2+1], lz[n].x), mul(lz[n].y, e - m));
        lz[n] = DEFAULT;
    }
    void _range_add(int n, int s, int e, int l, int r, int b, int c) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            tr[n] = ad(mul(tr[n], b), mul(c, e - s + 1));
            lz[n] = merge(lz[n], {b, c});
            return;
        }
        int m = (s + e) / 2;
        push(n, s, m, e);
        _range_add(n*2, s, m, l, r, b, c);
        _range_add(n*2+1, m+1, e, l, r, b, c);
        tr[n] = ad(tr[n*2], tr[n*2+1]);
    }
    T _query(int n, int s, int e, int i) {
        if (s > i || e < i) return 0;
        if (s == e) return tr[n];
        int m = (s + e) / 2;
        push(n, s, m, e);
        if (i <= m) {
            return _query(n*2, s, m, i);
        } else {
            return _query(n*2+1, m+1, e, i);
        }
    }
  public:
    LzSegTree(vt<T> &a) {
        len = 1;
        while (len < sz(a)) len *= 2;
        tr.assign(len*2, 0);
        lz.assign(len*2, DEFAULT);
        rep(i,0,sz(a)) tr[i+len] = a[i];
        rrep(i,len-1,1) {
            tr[i] = ad(tr[i*2], tr[i*2+1]);
        }
    }
    void add(int idx, T val) {
        _add(1, 0, len-1, idx, val);
    }
    void range_add(int l, int r, int b, int c) {
        _range_add(1, 0, len-1, l, r, b, c);
    }
    // query point i
    T query(int i) {
        return _query(1, 0, len-1, i);
    }
};

int T;
int N, Q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    vt<int> a(N);
    rep(i,0,N) cin >> a[i];
    LzSegTree<int> st(a);
    rep(i,0,Q) {
        int t; cin >> t;
        if (t == 0) {
            int x, y, b, c;
            cin >> x >> y >> b >> c;
            st.range_add(x, y-1, b, c);
        } else {
            int x;
            cin >> x;
            cout << st.query(x) << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}