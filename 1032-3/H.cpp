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
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

template <class T> class LzSegTree {
  private:
    const T DEFAULT = 0;
    vector<T> tr;
    vector<T> lz;
    int len;
    void push(int n, int s, int m, int e) {
        if (lz[n] == DEFAULT) return;
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        tr[2*n] += lz[n];
        tr[2*n+1] += lz[n];
        lz[n] = DEFAULT;
    }
    void _ck(int n, int s, int e, int idx, T val) {
        if (s == e) {
            tr[n] = max(tr[n], val);
            return;
        }
        int m = (s + e) / 2;
        push(n, s, m, e);
        if (idx <= m) {
            _ck(n*2, s, m, idx, val);
        } else {
            _ck(n*2+1, m+1, e, idx, val);
        }
        tr[n] = max(tr[n*2], tr[n*2+1]);
    }
    void _range_add(int n, int s, int e, int l, int r, T val) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            tr[n] += val;
            lz[n] += val;
            return;
        }
        int m = (s + e) / 2;
        push(n, s, m, e);
        _range_add(n*2, s, m, l, r, val);
        _range_add(n*2+1, m+1, e, l, r, val);
        tr[n] = max(tr[n*2], tr[n*2+1]);
    }
    T _query(int n, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tr[n];
        int m = (s + e) / 2;
        push(n, s, m, e);
        T left = _query(n*2, s, m, l, r);
        T right = _query(n*2+1, m+1, e, l, r);
        return max(left, right);
    }
  public:
    LzSegTree(vt<T> &a) {
        len = 1;
        while (len < sz(a)) len *= 2;
        tr.assign(len*2, DEFAULT);
        lz.assign(len*2, DEFAULT);
        rep(i,0,sz(a)) tr[i+len] = a[i];
        rrep(i,len-1,1) {
            tr[i] = max(tr[i*2], tr[i*2+1]);
        }
    }
    void ck(int idx, T val) {
        _ck(1, 0, len-1, idx, val);
    }
    void add(int idx, T val) {
        _add(1, 0, len-1, idx, val);
    }
    void range_add(int l, int r, T val) {
        if (l > r) return;
        _range_add(1, 0, len-1, l, r, val);
    }
    // query range [l, r]
    T query(int l, int r) {
        return _query(1, 0, len-1, l, r);
    }
};

int T, N;
pii a[200005];
int n = 0;

void comp() {
    set<int> s;
    rep(i,0,N) s.insert(a[i].x), s.insert(a[i].y);
    int cnt = 0;
    map<int,int> m;
    each(x,s) {
        m[x] = cnt++;
    }
    rep(i,0,N) {
        a[i] = {m[a[i].x], m[a[i].y]};
    }
    n = sz(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,0,N) cin >> a[i].x >> a[i].y;
        comp();
        vt<int> v(n);
        LzSegTree<int> st(v);
        vt<int> ans(N);
        rep(i,0,N) {
            int l = a[i].x, r = a[i].y;
            st.range_add(l+1, r, 1);
            int ma = st.query(0, l)+1;
            st.ck(l, ma);
            int res = st.query(0,n-1);
            ans[i] = res;
        }
        rep(i,0,N) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}