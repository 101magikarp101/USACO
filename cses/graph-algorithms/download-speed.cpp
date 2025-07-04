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
ll cap[505][505];
vt<int> adj[505];
int d[505], pr[505];
int source = 1, sink;

bool reach() {
    fill(d+1, d+N+1, 1e9);
    queue<int> q;
    d[source] = 0;
    q.push(source);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            ll w = cap[u][v];
            if (w && d[v] == 1e9) {
                d[v] = d[u]+1;
                pr[v] = u;
                q.push(v);
            }
        }
    }
    return d[sink] != 1e9;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    sink = N;
    for (int i = 0; i < M; i++) {
        int u, v; ll w; cin >> u >> v >> w;
        adj[u].pb(v);
        adj[v].pb(u);
        cap[u][v] += w;
    }
    ll ans = 0;
    while (reach()) {
        int u = sink;
        ll f = 1e9;
        while (u != source) {
            f = min(f, cap[pr[u]][u]);
            u = pr[u];
        }
        u = sink;
        while (u != source) {
            cap[pr[u]][u] -= f;
            cap[u][pr[u]] += f;
            u = pr[u];
        }
        ans += f;
    }
    cout << ans << endl;
    return 0;
}