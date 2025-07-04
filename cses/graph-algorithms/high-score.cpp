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
    bool operator<(const edge &a) const { return w < a.w; }
};

int N, M;
vt<edge> adj[2505];
ll d[2505];
bool vis[2505];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    rep(i,0,M) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].pb({u, v, w});
    }
    rep(i,1,N+1) d[i] = -1e18;
    d[1] = 0;
    bool cooked = false;
    rep(i,1,N) {
        rep(j,1,N+1) {
            each(e, adj[j]) {
                if (d[e.u] == -1e18) continue;
                if (d[e.u] + e.w > d[e.v]) {
                    d[e.v] = d[e.u] + e.w;
                }
            }
        }
    }
    vt<int> v;
    rep(j,1,N+1) {
        each(e, adj[j]) {
            if (d[e.u] == -1e18) continue;
            if (d[e.u] + e.w > d[e.v]) {
                v.pb(e.v);
            }
        }
    }
    queue<int> q;
    each(e, v) {
        if (!vis[e]) {
            q.push(e);
            vis[e] = true;
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        each(e, adj[u]) {
            if (!vis[e.v]) {
                vis[e.v] = true;
                q.push(e.v);
            }
        }
    }
    if (vis[N]) {
        cout << -1 << endl;
    } else {
        cout << d[N] << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}