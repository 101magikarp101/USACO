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

int N, K;
int dp[50005];
int d[50005];
vt<int> adj[50005];
int up[50005][16];
int ans = 0;

void dfs(int u, int p, int dep) {
    up[u][0] = p;
    d[u] = dep;
    for (int i = 1; i < 16; i++) {
        if (up[u][i-1] == 0) break;
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, dep+1);
    }
}

int lift(int u, int k) {
    for (int i = 0; i < 16; i++) {
        if (k&(1<<i)) {
            u = up[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = lift(u, d[u]-d[v]);
    if (u == v) return u;
    for (int i = 15; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int solve(int u, int p) {
    int res = dp[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        res += solve(v, u);
    }
    ckmax(ans, res);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, 0);
    for (int i = 0; i < K; i++) {
        int u, v; cin >> u >> v;
        int l = lca(u,v);
        dp[u]++;
        dp[v]++;
        dp[l]--;
        dp[up[l][0]]--;
    }
    solve(1, 0);
    cout << ans << endl;
    return 0;
}