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
    vector<T> lz, add;
    int len;
    T op(ll s) {
        return s*(s+1)/2;
    }
    void push(int n, int s, int m, int e) {
        if (lz[n] == DEFAULT && add[n] == DEFAULT) return;
        // cout << "n = " << n << ", s = " << s << ", m = " << m << ", e = " << e << endl;
        // cout << "tr[" << n << "] = " << tr[n] << ", lz[" << n << "] = " << lz[n] << ", add[" << n << "] = " << add[n] << endl;
        // cout << "tr[" << 2*n << "] = " << tr[2*n] << ", lz[" << 2*n << "] = " << lz[2*n] << ", add[" << 2*n << "] = " << add[2*n] << endl;
        // cout << "tr[" << 2*n+1 << "] = " << tr[2*n+1] << ", lz[" << 2*n+1 << "] = " << lz[2*n+1] << ", add[" << 2*n+1 << "] = " << add[2*n+1] << endl;
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        add[2*n] += add[n];
        add[2*n+1] += add[n] + (ll)(m-s+1)*lz[n];
        tr[2*n] += (ll)(m-s+1)*add[n] + op(m-s+1)*lz[n];
        tr[2*n+1] += (ll)(e-m)*add[n] + op(e-m)*lz[n] + (ll)(m-s+1)*lz[n]*(e-m);
        // cout << "After push, tr[" << 2*n << "] = " << tr[2*n] << ", lz[" << 2*n << "] = " << lz[2*n] << ", add[" << 2*n << "] = " << add[2*n] << endl;
        // cout << "After push, tr[" << 2*n+1 << "] = " << tr[2*n+1] << ", lz[" << 2*n+1 << "] = " << lz[2*n+1] << ", add[" << 2*n+1 << "] = " << add[2*n+1] << endl;
        lz[n] = DEFAULT;
        add[n] = DEFAULT;
    }
    void _range_add(int n, int s, int e, int l, int r, T x) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            lz[n]++;
            add[n] += x;
            tr[n] += op(e-s+1) + (ll)(e-s+1)*x;
            return;
        }
        int m = (s + e) / 2;
        push(n, s, m, e);
        _range_add(n*2, s, m, l, r, x);
        int hm = (l<=m ? m-max(s,l)+1 : 0);
        _range_add(n*2+1, m+1, e, l, r, x + hm);
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
        lz.assign(len*2, DEFAULT);
        add.assign(len*2, DEFAULT);
        rep(i,0,sz(a)) tr[i+len] = a[i];
        rrep(i,len-1,1) {
            tr[i] = tr[i*2] + tr[i*2+1];
        }
    }
    void range_add(int l, int r) {
        _range_add(1, 0, len-1, l, r, 0);
    }
    // query range [l, r]
    T query(int l, int r) {
        return _query(1, 0, len-1, l, r);
    }
    void print() {
        cout << "Segment Tree: ";
        rep(i,1,len*2) {
            if (tr[i] != DEFAULT) cout << "i: " << i << " " << tr[i] << endl;
        }
        cout << "Lazy Array: ";
        rep(i,1,len*2) {
            if (lz[i] != DEFAULT) cout << "i: " << i << " " << lz[i] << endl;
        }
        cout << "Add Array: ";
        rep(i,1,len*2) {
            if (add[i] != DEFAULT) cout << "i: " << i << " " << add[i] << endl;
        }
        cout << endl;
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
        int t, l, r; cin >> t >> l >> r;
        l--; r--;
        if (t == 1) {
            seg.range_add(l, r);
        } else {
            cout << seg.query(l, r) << endl;
        }
        // seg.print();
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}