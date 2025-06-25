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
    void operator+=(const pii &a) { x += a.x; y += a.y; }
    void operator-=(const pii &a) { x -= a.x; y -= a.y; }
    void operator*=(const int &a) { x *= a; y *= a; }
    void operator/=(const int &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pii &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pii &p) {return is >> p.x >> p.y;}
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
    void operator+=(const pll &a) { x += a.x; y += a.y; }
    void operator-=(const pll &a) { x -= a.x; y -= a.y; }
    void operator*=(const ll &a) { x *= a; y *= a; }
    void operator/=(const ll &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pll &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pll &p) {return is >> p.x >> p.y;}
};
static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x^(x>>30))*0xbf58476d1ce4e5b9;
    x = (x^(x>>27))*0x94d049bb133111eb;
    return x^(x>>31);
}
struct custom_hash {
    static const uint64_t FIXED_RANDOM;
    size_t operator()(uint64_t x) const {return splitmix64(x + FIXED_RANDOM);}
    template<typename T> size_t operator()(const T& t) const {return splitmix64(uint64_t(std::hash<T>{}(t)) + FIXED_RANDOM);}
};
const uint64_t custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(custom_hash::FIXED_RANDOM);
template<typename K, typename V> using umap = unordered_map<K, V, custom_hash>;
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

struct state {
    ll l, r;
    bool b;
};

int N, M;
ll range = -1;
pll a[100005][2];
ll siz[200005];
map<ll,vt<state>> m;

template <class T = pll> class LzSegTree { // {min, cnt of min}
  private:
    const T DEFAULT = {LLONG_MAX, 0};
    vector<T> tr;
    vector<ll> lz;
    int len;
    T merge(const T &a, const T &b) {
        if (a.x < b.x) return a;
        if (b.x < a.x) return b;
        return {a.x, a.y + b.y};
    }
    void push(int n, int s, int m, int e) {
        if (lz[n] == 0) return;
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        tr[2*n].x += lz[n];
        tr[2*n+1].x += lz[n];
        lz[n] = 0;
    }
    void _range_add(int n, int s, int e, int l, int r, int val) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            tr[n].x += val;
            lz[n] += val;
            return;
        }
        int m = (s + e) / 2;
        push(n, s, m, e);
        _range_add(n*2, s, m, l, r, val);
        _range_add(n*2+1, m+1, e, l, r, val);
        tr[n] = merge(tr[n*2], tr[n*2+1]);
    }
    T _query(int n, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tr[n];
        int m = (s + e) / 2;
        push(n, s, m, e);
        T left = _query(n*2, s, m, l, r);
        T right = _query(n*2+1, m+1, e, l, r);
        return merge(left, right);
    }
  public:
    LzSegTree(int n) {
        len = 1;
        while (len < n) len *= 2;
        tr.assign(len*2, DEFAULT);
        lz.assign(len*2, 0);
        rep(i,0,n) tr[i+len] = {0, siz[i]};
        rrep(i,len-1,1) {
            tr[i] = merge(tr[i*2], tr[i*2+1]);
        }
    }
    void range_add(int l, int r, int val) {
        _range_add(1, 0, len-1, l, r, val);
    }
    // query range [l, r]
    T query(int l, int r) {
        return _query(1, 0, len-1, l, r);
    }
};

void comp() {
    set<ll> s;
    rep(i,0,N) {
        s.insert(a[i][0].y);
        s.insert(a[i][1].y);
    }
    range = *s.rbegin() - *s.begin();
    map<ll,ll> hm;
    ll prev = *s.begin();
    ll cnt = 0;
    each(x,s) {
        hm[x] = cnt;
        siz[cnt] = x - prev;
        prev = x;
        cnt++;
    }
    rep(i,0,N) {
        a[i][0].y = hm[a[i][0].y];
        a[i][1].y = hm[a[i][1].y];
    }
    M = sz(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    rep(i,0,N) {
        cin >> a[i][0] >> a[i][1];
    }
    comp();
    // cout << "range = " << range << endl;
    rep(i,0,N) {
        int l = a[i][0].x;
        int r = a[i][1].x;
        m[l].pb({a[i][0].y, a[i][1].y, 1});
        m[r].pb({a[i][0].y, a[i][1].y, 0});
    }
    LzSegTree<pll> st(M);
    ll ans = 0;
    ll prev = 0;
    ll prevx = -1e9;
    each(i,m) {
        ans += (i.fi - prevx) * prev;
        prevx = i.fi;
        each(p,i.se) {
            if (p.b) {
                st.range_add(p.l+1, p.r, 1);
            } else {
                st.range_add(p.l+1, p.r, -1);
            }
        }
        pll cur = st.query(0, M-1);
        ll res = range;
        if (cur.x == 0) {
            res -= cur.y;
        }
        prev = res;
    }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}