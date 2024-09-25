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
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tree[i] = std::min(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    void push(int node) {
        tree[node * 2] = lz[node];
        tree[node * 2 + 1] = lz[node];
        lz[node * 2] = lz[node];
        lz[node * 2 + 1] = lz[node];
        lz[node] = DEFAULT;
    }
    void set(int node, int s, int e, int idx, T val) {
        if (s == e) {
            tree[node] = val;
            return;
        }
        if (lz[node] != DEFAULT) push(node);
        int m = (s + e) / 2;
        if (idx <= m) {
            set(node * 2, s, m, idx, val);
        } else {
            set(node * 2 + 1, m + 1, e, idx, val);
        }
        tree[node] = std::min(tree[node * 2], tree[node * 2 + 1]);
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
vt<edge> adj[200005];
ll par[200005], len[200005];
int dep[100005];
edge a[1000005];
vt<edge> oth;
ll tot = 0;

void dfs(int u, int p, int d) {
    par[u] = p;
    dep[u] = d;
    for (edge e : adj[u]) {
        if (e.v == p) continue;
        dfs(e.v, u, d+1);
    }
}

// void run(int u, ll v) {
//     if (u <= 1) return;
//     if (len[u] == -1) {
//         len[u] = v;
//         run(par[u], v);
//     }
// }

ll find(int u, int p) {
    ll res = 0;
    for (edge e : adj[u]) {
        if (e.v == p) continue;
        res = max(res, find(e.v, u));
        res = max(res, len[e.v]-e.w);
    }
    return res;
}

int main() {
    // HLD first
    // backwards iterate through edges
    // lazy minsegtree
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    DSU dsu(N+1);
    for (int i = 1; i <= N; i++) {
        len[i] = -1;
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
            // cout << "edge " << a[i].u << " " << a[i].v << " " << a[i].w << endl;
        } else {
            oth.pb(a[i]);
        }
    }
    // cout << "tot: " << tot << endl;
    dfs(1, 0, 0);
    for (edge e : oth) {
        int u = e.u, v = e.v;
        // run(u, e.w);
        // run(v, e.w);
    }
    // cout << "par: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << par[i] << " ";
    // }
    // cout << endl;
    // cout << "len: ";
    // for (int i = 1; i <= N; i++) {
    //     cout << len[i] << " ";
    // }
    // cout << endl;
    cout << tot+find(1, 0) << endl;
    return 0;
}