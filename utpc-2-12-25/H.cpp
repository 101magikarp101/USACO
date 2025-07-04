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

struct edge {
    int u, v;
    ll w;
};

int T, N, M;
vt<edge> adj[200005];
int dep[200005];
int dp[200005];
bool vis[200005];
map<pii,ll> mp;
vt<ll> ans;

void dfs(int u, int p, int d) {
    // cout << "u = " << u << " p = " << p << " d = " << d << endl;
    vis[u] = 1;
    dep[u] = d;
    for (edge e : adj[u]) {
        if (e.v == p) continue;
        if (!vis[e.v]) dfs(e.v, u, d+1);
    }
}

void dfs2(int u, int p) {
    dp[u] = 0;
    for (edge e : adj[u]) {
        if (dep[e.v] < dep[u]) {
            dp[u]++;
            continue;
        }
        if (dep[e.v] > dep[u]) dp[u]--;
        if (dep[e.v] != dep[u]+1) continue;
        dfs2(e.v, u);
        dp[u] += dp[e.v];
    }
    // cout << "u = " << u << " dp = " << dp[u] << endl;
    if (dp[u] == 1) {
        ans.pb(mp[{u,p}]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    rep(i,0,M) {
        ll id; int u, v; cin >> id >> u >> v;
        if (u == v) continue;
        adj[u].pb({u, v, id});
        adj[v].pb({v, u, id});
        mp[{u,v}] = id; 
        mp[{v,u}] = id;
    }
    dfs(0, -1, 0);
    dfs2(0, -1);
    sort(all(ans));
    if (sz(ans) == 0) {
        cout << -1 << endl;
    } else {
        each(i,ans) cout << i << ' ';
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}