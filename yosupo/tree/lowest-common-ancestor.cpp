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

struct LCA {
    int n, lg;
    vvt<int> up;
    vt<int> dep;
    vvt<int> adj;
    LCA(vvt<int> &adj) : n(sz(adj)), adj(adj) {
        lg = 32 - __builtin_clz(max(1, n));
        up.assign(lg, vt<int>(n));
        dep.assign(n, 0);
        adj.assign(n, vt<int>());
        init();
    }

    void init(int root = 0) {
        queue<int> q;
        dep[root] = 0;
        up[0][root] = root;
        q.push(root);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            each(v,adj[u]) {
                if (v == up[0][u]) continue;
                dep[v] = dep[u] + 1;
                up[0][v] = u;
                q.push(v);
            }
        }
        rep(k,1,lg) {
            rep(v,0,n) {
                up[k][v] = up[k-1][up[k-1][v]];
            }
        }
    }

    int lift(int u, int k) {
        while (k) {
            int j = __builtin_ctz(k);
            u = up[j][u];
            k &= k - 1;
        }
        return u;
    }

    int lca(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);
        int diff = dep[u] - dep[v];
        u = lift(u, diff);
        if (u == v) return u;
        rrep(k,lg-1,0) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
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
    vvt<int> adj(N);
    rep(i,1,N) {
        int p; cin >> p;
        adj[p].pb(i);
    }
    LCA lca(adj);
    while (Q--) {
        int u, v; cin >> u >> v;
        cout << lca.lca(u, v) << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}