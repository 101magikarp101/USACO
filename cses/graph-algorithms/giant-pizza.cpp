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

// SCC - Kosaraju's algorithm
void dfs(int u, vvt<int> &adj, vt<bool> &vis, vt<int> &out) {
    vis[u] = 1;
    each(v, adj[u]) {
        if (!vis[v]) {
            dfs(v, adj, vis, out);
        }
    }
    out.push_back(u);
}
// input: N, adj
// output: idx, scc - index of component, number of components
// idx: forms a directed acyclic graph
void SCC(int N, vvt<int> &adj, vt<int> &idx, int &scc) {
    vt<int> out;
    vt<bool> vis(N,0);
    rep(i,0,N) {
        if (!vis[i]) {
            dfs(i, adj, vis, out);
        }
    }
    vt<vt<int>> adjrev(N);
    rep(i,0,N) {
        each(v,adj[i]) {
            adjrev[v].pb(i);
        }
    }
    vis.assign(N,0);
    int sccidx = 0;
    rrep(i,sz(out)-1,0) {
        int u = out[i];
        if (vis[u]) continue;
        stack<int> st2;
        st2.push(u);
        while (!st2.empty()) {
            int v = st2.top();
            st2.pop();
            if (vis[v]) continue;
            vis[v] = 1;
            idx[v] = sccidx;
            each(w,adjrev[v]) {
                if (!vis[w]) {
                    st2.push(w);
                }
            }
        }
        sccidx++;
    }
    scc = sccidx;
}

struct TwoSAT {
    int n;
    vvt<int> adj;
    TwoSAT(int n) : n(n), adj(2*n) {}
    void add(int u, bool bu, int v, bool bv) {
        adj[2*u + !bu].pb(2*v + bv);
        adj[2*v + !bv].pb(2*u + bu);
    }
    vt<bool> solve() {
        vt<int> idx(2*n, -1);
        int scc = 0;
        SCC(2*n, adj, idx, scc);
        vt<bool> res(n, false);
        rep(i,0,n) {
            if (idx[2*i] == idx[2*i + 1]) {
                return vt<bool>();
            }
            res[i] = idx[2*i] < idx[2*i + 1];
        }
        return res;
    }
};

int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    TwoSAT ts(M);
    rep(i,0,N) {
        char c1, c2; int u, v; cin >> c1 >> u >> c2 >> v;
        u--, v--;
        bool b1 = c1 == '+';
        bool b2 = c2 == '+';
        ts.add(u, b1, v, b2);
    }
    vt<bool> res = ts.solve();
    if (res.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        rep(i,0,M) {
            cout << (res[i] ? '+' : '-') << " ";
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}