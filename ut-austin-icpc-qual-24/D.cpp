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

    template <class T> class MaxSegTree {
private:
    const T DEFAULT = std::numeric_limits<T>().min();
    vector<T> tree;
    vector<T> lz;
    int len;
public:
    MaxSegTree(int len) : len(len), tree(len * 4, DEFAULT), lz(len * 4, 0) {}
    void build() {
        for (int i = len - 1; i > 0; i--) {
            tree[i] = std::max(tree[i * 2], tree[i * 2 + 1]);
        }
    }
    void push(int node) {
        tree[node * 2] += lz[node];
        tree[node * 2 + 1] += lz[node];
        lz[node * 2] += lz[node];
        lz[node * 2 + 1] += lz[node];
        lz[node] = 0;
    }
    void set(int node, int s, int e, int idx, T val) {
        if (s == e) {
            tree[node] = val;
            return;
        }
        if (lz[node] != 0) push(node);
        int m = (s + e) / 2;
        if (idx <= m) {
            set(node * 2, s, m, idx, val);
        } else {
            set(node * 2 + 1, m + 1, e, idx, val);
        }
        tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
    }
    void update(int node, int s, int e, int l, int r, T val) {
        if (s > r || e < l) return;
        if (l <= s && e <= r) {
            tree[node] += val;
            lz[node] += val;
            return;
        }
        if (lz[node] != 0) push(node);
        int m = (s + e) / 2;
        update(node * 2, s, m, l, r, val);
        update(node * 2 + 1, m + 1, e, l, r, val);
        tree[node] = std::max(tree[node * 2], tree[node * 2 + 1]);
    }
    T query(int node, int s, int e, int l, int r) {
        if (s > r || e < l) return DEFAULT;
        if (l <= s && e <= r) return tree[node];
        if (lz[node] != 0) push(node);
        int m = (s + e) / 2;
        ll left = query(node * 2, s, m, l, r);
        ll right = query(node * 2 + 1, m + 1, e, l, r);
        return std::max(left, right);
    }
};

int N, K;
int up[100005];
int in[100005], out[100005];
bool vis[100005];
map<int,int> mp;
int d[100005];
vt<int> adj[100005];
int t = 0;

void dfs(int u, int dep) {
    in[u] = t++;
    mp[in[u]] = u;
    d[u] = dep;
    for (int v : adj[u]) {
        dfs(v, dep+1);
    }
    out[u] = t++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    MaxSegTree<int> st(2*N);
    up[1] = 0;
    for (int i = 2; i <= N; i++) {
        int x; cin >> x;
        adj[x].pb(i);
        up[i] = x;
    }
    dfs(1,1);
    for (int i = 1; i <= N; i++) {
        st.set(1,0,2*N-1,in[i],d[i]);
        st.set(1,0,2*N-1,out[i],d[i]);
    }
    int ans = 0;
    while (K--) {
        int ma = st.query(1,0,2*N-1,0,2*N-1);
        if (ma <= 0) break;
        int l = 0, r = 2*N-1;
        while (l < r) {
            int m = (l+r)/2;
            if (st.query(1,0,2*N-1,0,m) == ma) {
                r = m;
            } else {
                l = m+1;
            }
        }
        int u = mp[l];
        ans += ma;
        while (!vis[u]) {
            vis[u] = 1;
            st.update(1,0,2*N-1,in[u],out[u],-1);
            u = up[u];
            if (u == 0) break;
        }
    }
    cout << ans << endl;
    return 0;
}