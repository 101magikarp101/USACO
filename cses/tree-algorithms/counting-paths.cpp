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

int N, M;
vt<int> adj[200005];
int d[200005];
int up[200005][18];
int dp[200005];

void dfs(int u, int par, int dep) {
    up[u][0] = par;
    d[u] = dep;
    for (int i = 1; i < 18; i++) {
        if (up[u][i-1] == 0) break;
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (int v : adj[u]) {
        if (v==par) continue;
        dfs(v, u, dep+1);
    }
}

int lift(int u, int k) {
    for (int i = 17; i >= 0; i--) {
        if (k&(1<<i)) {
            u = up[u][i];
        }
        if (u==0) return -1;
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] > d[v]) {
        u = lift(u, d[u]-d[v]);
    } else if (d[u] < d[v]) {
        v = lift(v, d[v]-d[u]);
    }
    if (u==v) return u;
    for (int i = 17; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void query(int u, int v) {
    int l = lca(u,v);
    dp[u]++;
    dp[v]++;
    dp[l]--;
    if (up[l][0]!=0) dp[up[l][0]]--;
}

void total(int u, int p) {
    for (int v: adj[u]) {
        if (v==p) continue;
        total(v,u);
        dp[u]+=dp[v];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, 0, 0);
    while (M--) {
        int u, v; cin >> u >> v;
        query(u,v);
    }
    total(1,0);
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    return 0;
}