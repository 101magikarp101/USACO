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

vt<int> eulerian_path(int N, vvt<pii> &adj) {
    vt<int> path;
    int tot = 0;
    vt<int> odd;
    for (int i = 0; i < N; i++) {
        tot += sz(adj[i]);
        if (sz(adj[i]) & 1) {
            odd.pb(i);
        }
    }
    if (sz(odd) > 2 || sz(odd) == 1) {
        return vt<int>();
    }
    if (sz(odd) > 0 && odd[0] != 0) return vt<int>();
    tot /= 2;
    vt<bool> vis(tot,0);
    stack<int> s;
    s.push(0);
    while (!s.empty()) {
        int u = s.top();
        while (!adj[u].empty() && vis[adj[u].back().y]) {
            adj[u].pop_back();
        }
        if (sz(adj[u]) == 0) {
            path.pb(u);
            s.pop();
        } else {
            auto [v, i] = adj[u].back();
            adj[u].pop_back();
            vis[i] = 1;
            s.push(v);
        }
    }
    reverse(all(path));
    if (sz(path) != tot + 1 || path[0] != path.back()) {
        return vt<int>();
    }
    return path;
}

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    vvt<pii> adj(N);
    set<pii> s;
    rep(i,0,M) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        s.insert({min(u, v), max(u, v)});
    }
    vt<int> path = eulerian_path(N, adj);
    if (path.empty()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    rep(i,0,sz(path)) {
        cout << path[i] + 1 << " ";
    }
    cout << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}