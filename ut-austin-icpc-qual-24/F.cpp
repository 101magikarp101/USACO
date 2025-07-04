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
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
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

struct SumSegTree {
  private:
    vector<pll> tr;
    vector<ll> lz;
    int len;
  public:
    SumSegTree(int l) : len(l), tr(l*4, {0,0}), lz(l*4, 0) {}
    void build(int n, int s, int e) {
        if (s == e) {
            tr[n] = {0,1};
            return;
        }
        int m = (s+e)/2;
        build(n*2, s, m);
        build(n*2+1, m+1, e);
        tr[n] = merge(tr[n*2], tr[n*2+1]);
    }
    void push(int n, int e) {
        lz[2*n] += lz[n];
        lz[2*n+1] += lz[n];
        tr[2*n].x += lz[n];
        tr[2*n+1].x += lz[n];
        lz[n] = 0;
    }
    pll merge(pll a, pll b) {
        if (a.x < b.x) return a;
        if (a.x > b.x) return b;
        return {a.x, a.y+b.y};
    }
    void range_add(int n, int s, int e, int l, int r, ll val) {
        if (s>r || e<l) return;
        if (l<=s && e<=r) {
            tr[n].x += val;
            lz[n] += val;
            return;
        }
        int m = (s+e)/2;
        if (lz[n] != 0) push(n,e);
        range_add(n*2, s, m, l, r, val);
        range_add(n*2+1, m+1, e, l, r, val);
        tr[n] = merge(tr[n*2], tr[n*2+1]);
    }
    ll query(int n, int s, int e, int l, int r) {
        if (s>r || e<l) return 0;
        if (l<=s && e<=r) return (tr[n].x == 0 ? tr[n].y : 0);
        int m = (s+e)/2;
        if (lz[n] != 0) push(n,e);
        ll left = query(n*2, s, m, l, r);
        ll right = query(n*2+1, m+1, e, l, r);
        return left+right;
    }
};

struct line {
    pll a, b;
};

struct state {
    bool b;
    ll x, y;
};

ll N, P;
line a[10005];
ll x1, y01, x2, y2;

ll area(ll a1, ll b1, ll a2, ll b2) {
    ll x = max(x1, a1);
    ll X = min(x2, a2);
    ll y = max(y01, b1);
    ll Y = min(y2, b2);
    if (x >= X || y >= Y) return 0;
    return (X-x)*(Y-y);
}

bool solve(ll d) {
    map<ll,vt<state>> m;
    SumSegTree st(100005);
    st.build(1, 0, 100000);
    for (int i = 0; i < N; i++) {
        ll l = min(a[i].a.x, a[i].b.x)-d;
        ll r = max(a[i].a.x, a[i].b.x)+d;
        ll t = max(a[i].a.y, a[i].b.y)+d;
        ll b = min(a[i].a.y, a[i].b.y)-d;
        m[l].pb({0,t,b});
        m[r].pb({1,t,b});
    }
    ll tot = 0;
    ll prev = 0;
    for (auto &x : m) {
        ll res = st.query(1, 0, 100000, y01, y2-1);
        res = (y2-y01)-res;
        ll l = max(prev, x1);
        ll r = min(x.fi, x2);
        if (l < r) {
            tot += res*(r-l);
        }
        for (auto &y : x.se) {
            ckmax(y.y, y01);
            ckmin(y.x, y2);
            if (y.x == y.y) continue;
            if (y.b) {
                st.range_add(1, 0, 100000, y.y, y.x-1, -1);
            } else {
                st.range_add(1, 0, 100000, y.y, y.x-1, 1);
            }
        }
        prev = x.fi;
    }
    return tot*100LL >= P*(x2-x1)*(y2-y01);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i].a.x >> a[i].a.y >> a[i].b.x >> a[i].b.y;
    }
    cin >> P >> x1 >> y01 >> x2 >> y2;
    ll l = 0, r = 1e5;
    while (l < r) {
        ll m = (l+r)/2;
        if (solve(m)) r = m;
        else l = m+1;
    }
    cout << l << endl;
    return 0;
}