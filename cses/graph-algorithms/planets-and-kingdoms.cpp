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
int sccidx;
void dfs1(int u, vt<bool> &vis, vt<vt<int>> &adj, vt<int> &out) {
    vis[u] = 1;
    each(v,adj[u]) {
        if (!vis[v]) {
            dfs1(v, vis, adj, out);
        }
    }
    out.pb(u);
}

void dfs2(int u, vt<bool> &vis, vt<vt<int>> &adjrev, vt<int> &idx) {
    vis[u] = 1;
    idx[u] = sccidx;
    each(v,adjrev[u]) {
        if (!vis[v]) {
            dfs2(v, vis, adjrev, idx);
        }
    }
}

// input: N, adj
// output: idx, scc - index of component, number of components
// idx: forms a directed acyclic graph
void SCC(int N, vt<vt<int>> &adj, vt<int> &idx, int &scc) {
    vt<int> out;
    vt<bool> vis(N,0);
    // sort nodes by finish time
    rep(i,0,N) {
        if (!vis[i]) {
            dfs1(i, vis, adj, out);
        }
    }
    // reverse graph + dfs
    vt<vt<int>> adjrev(N);
    rep(i,0,N) {
        each(v,adj[i]) {
            adjrev[v].pb(i);
        }
    }
    vis.assign(N,0);
    sccidx = 0;
    rrep(i,sz(out)-1,0) {
        if (!vis[out[i]]) {
            dfs2(out[i], vis, adjrev, idx);
            sccidx++;
        }
    }
    scc = sccidx;
}

int N, M;
vt<vt<int>> adj;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    adj.resize(N);
    rep(i,0,M) {
        int u, v; cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
    }
    vt<int> idx(N);
    int scc = 0;
    SCC(N, adj, idx, scc);
    cout << scc << endl;
    rep(i,0,N) {
        cout << idx[i] << ' ';
    }
    cout << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}