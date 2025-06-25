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

int N, Q;
vt<int> adj[200005];
int a[200005];
pii ord[200005];
int t = 1;

void dfs(int u, int p) {
    ord[u].x = t++;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    ord[u].y = t-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    rep(i,0,N) cin >> a[i];
    rep(i,1,N) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    BIT<ll> bit(N);
    rep(i,0,N) {
        bit.upd(ord[i].x, a[i]);
        bit.upd(ord[i].y + 1, -a[i]);
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int u; ll x; cin >> u >> x;
            u--;
            bit.upd(ord[u].x, x - a[u]);
            bit.upd(ord[u].y + 1, -(x - a[u]));
            a[u] = x;
        } else {
            int u; cin >> u;
            u--;
            ll res = bit.sum(ord[u].x);
            cout << res << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}