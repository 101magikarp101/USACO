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
    void operator+=(const pii &a) { x += a.x; y += a.y; }
    void operator-=(const pii &a) { x -= a.x; y -= a.y; }
    void operator*=(const int &a) { x *= a; y *= a; }
    void operator/=(const int &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pii &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
    friend istream& operator>>(istream &is, pii &p) {
        return is >> p.x >> p.y;
    }
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
    friend ostream& operator<<(ostream &os, const pll &p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
    friend istream& operator>>(istream &is, pll &p) {
        return is >> p.x >> p.y;
    }
};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

template <class T> class BIT {
    // MUST be 1-indexed
public:
    vector<T> bit;
    int size;
    BIT(int n) {size = n; bit.resize(n + 1);}
    void upd(int i, T x) {
        for (; i <= size; i += i & -i) bit[i] += x;
    }
    // returns sum of [1, i]
    T sum(int i) {
        T s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
    // returns sum of [l, r]
    T sum(int l, int r) {
        return sum(r) - (l>1 ? sum(l-1) : 0);
    }
};

int N;
int X, Y;
pii a[100005][2];
vt<pii> v[200005];
vt<int> ls[200005], rs[200005];

void comp() {
    set<int> s;
    rep(i,0,N) {
        s.insert(a[i][0].x);
        s.insert(a[i][1].x);
    }
    map<int,int> m;
    each(x,s) {
        m[x] = sz(m);
    }
    rep(i,0,N) {
        a[i][0].x = m[a[i][0].x];
        a[i][1].x = m[a[i][1].x];
    }
    X = sz(m);
    s.clear();
    rep(i,0,N) {
        s.insert(a[i][0].y);
        s.insert(a[i][1].y);
    }
    m.clear();
    each(x,s) {
        m[x] = sz(m);
    }
    rep(i,0,N) {
        a[i][0].y = m[a[i][0].y];
        a[i][1].y = m[a[i][1].y];
    }
    Y = sz(m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N;
    map<pii,ll> m;
    rep(i,0,N) {
        cin >> a[i][0] >> a[i][1];
    }
    comp();
    rep(i,0,N) {
        pii p0 = a[i][0];
        pii p1 = a[i][1];
        if (p0.x == p1.x) {
            v[p0.x].pb({min(p0.y, p1.y), max(p0.y, p1.y)});
        } else {
            ls[min(p0.x, p1.x)].pb(p0.y);
            rs[max(p0.x, p1.x)].pb(p0.y);
        }
    }
    BIT<ll> bit(Y);
    ll ans = 0;
    rep(i,0,X) {
        each(p,ls[i]) {
            bit.upd(p+1, 1);
        }
        each(p,rs[i]) {
            bit.upd(p+1, -1);
        }
        each(p,v[i]) {
            int l = p.x + 1, r = p.y + 1;
            ll cnt = bit.sum(l, r);
            ans += cnt;
        }
    }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}