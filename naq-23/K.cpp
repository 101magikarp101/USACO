#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

struct DSU {
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x] > e[y]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

template <class T> class MinSegTree {
private:
    const T DEFAULT = std::numeric_limits<T>().max();
    vector<T> tree;
    vector<T> lz;
    int len;
public:
    MinSegTree(int len) : len(len), tree(len * 4, DEFAULT), lz(len * 4, DEFAULT) {}
    void push(int node) {
        tree[node * 2] = lz[node];
        tree[node * 2 + 1] = lz[node];
        lz[node * 2] = lz[node];
        lz[node * 2 + 1] = lz[node];
        lz[node] = DEFAULT;
    }
    void update(int node, int s, int e, int l, int r, T val) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            tree[node] = val;
            lz[node] = val;
            return;
        }
        if (lz[node] != DEFAULT) push(node);
        int m = (s + e) / 2;
        update(node * 2, s, m, l, r, val);
        update(node * 2 + 1, m + 1, e, l, r, val);
        tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
    }
    T query(int node, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tree[node];
        if (lz[node] != DEFAULT) push(node);
        int m = (s + e) / 2;
        ll left = query(node * 2, s, m, l, r);
        ll right = query(node * 2 + 1, m + 1, e, l, r);
        return std::min(left, right);
    }
};

struct edge {
    int u, v;
    ll w;
    bool operator<(const edge &a) const {
        return w < a.w;
    }
};

int N, M;
vt<edge> adj[100005];
int up[100005][17];
int par[100005], siz[100005];
int dep[100005];
int hld[100005];
int tim[100005];
ll sus[100005];
edge a[1000005];
vt<edge> oth;
ll tot = 0;
int t = 1;
MinSegTree<ll> st(100005);
DSU dsu(100005);


void removep(int u, int p) {
    par[u] = p;
    for (edge e : adj[u]) {
        if (e.v==p) continue;
        removep(e.v,u);
    }
    for (int i = 0; i < sz(adj[u]); i++) {
        if (adj[u][i].v == p) {
            swap(adj[u][i], adj[u][sz(adj[u])-1]);
            adj[u].pop_back();
            break;
        }
    }
}

void dfs1(int u, int d) {
    siz[u] = 1;
    dep[u] = d;
    up[u][0] = par[u];
    for (int i = 1; i < 17; i++) {
        if (up[u][i-1]==0) break;
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (edge e : adj[u]) {
        dfs1(e.v,d+1);
        siz[u]+=siz[e.v];
    }
}

void dfs2(int u) {
    tim[u] = t++;
    for (int i = 0; i < sz(adj[u]); i++) {
        if (siz[adj[u][i].v] > siz[adj[u][0].v]) {
            swap(adj[u][i],adj[u][0]);
        }
    }
    for (int i = 0; i < sz(adj[u]); i++) {
        if (i==0) {
            hld[adj[u][i].v] = hld[u]+1;
        } else {
            hld[adj[u][i].v] = 0;
        }
        dfs2(adj[u][i].v);
    }
}

int lift(int u, int k) {
    for (int i = 16; i >= 0; i--) {
        if (k&(1<<i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) {
        u = lift(u, dep[u]-dep[v]);
    } else if (dep[u] < dep[v]) {
        v = lift(v, dep[v]-dep[u]);
    }
    if (u==v) return v;
    for (int i = 16; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return par[u];
}

void runup(int u, int d, ll w) {
    if (d <= 0) return;
    if (hld[u] == 0) {
        sus[u] = w;
        u = par[u];
        runup(u, d-1, w);
    } else {
        int dd = min(d,hld[u]);
        st.update(1,1,N,tim[u]-dd+1,tim[u],w);
        u = lift(u,dd);
        runup(u, d-dd, w);
    }
}

void run(int u, int v, ll w) {
    int l = lca(u,v);
    runup(u, dep[u]-dep[l], w);
    runup(v, dep[v]-dep[l], w);
}

ll find(int u) {
    ll ans = 0;
    for (edge e : adj[u]) {
        ll res = min(sus[e.v], st.query(1,1,N,tim[e.v],tim[e.v]));
        ans = max(ans, res-e.w);
        ans = max(ans, find(e.v));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        sus[i] = LLONG_MAX;
    }
    for (int i = 0; i < M; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        a[i] = {u, v, w};
    }
    sort(a, a+M);
    for (int i = 0; i < M; i++) {
        if (dsu.unite(a[i].u, a[i].v)) {
            adj[a[i].u].pb({a[i].u, a[i].v, a[i].w});
            adj[a[i].v].pb({a[i].v, a[i].u, a[i].w});
            tot += a[i].w;
        } else {
            oth.pb(a[i]);
        }
    }
    removep(1,0);
    dfs1(1,0);
    dfs2(1);
    reverse(all(oth));
    for (edge e : oth) {
        int u = e.u, v = e.v; ll w = e.w;
        run(u,v,e.w);
    }
    ll ans = find(1);
    cout << tot+ans << endl;
    return 0;
}