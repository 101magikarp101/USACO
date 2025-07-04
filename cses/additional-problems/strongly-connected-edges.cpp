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
vt<int> adj[100005];
bool vis[100005];
int h[100005];
int d[100005];
string ans = "";
bool c = 1;

void solve(int u, int p, int dep) {
    vis[u] = 1;
    d[u] = dep;
    for (int v : adj[u]) {
        if (v==p) continue;
        if (!vis[v]) {
            ans += to_string(u)+" "+to_string(v)+"\n";
            solve(v, u, dep+1);
        } else if (d[v] > d[u]) {
            ans += to_string(v)+" "+to_string(u)+"\n";
            h[v] = min(h[v], d[u]);
        }
    }
}

pii check(int u, int p, int best) {
    vis[u] = 1;
    if (h[u] != INT_MAX) best = max(best, d[u]);
    int height = h[u];
    for (int v : adj[u]) {
        if (v==p) continue;
        if (!vis[v]) {
            pii res = check(v, u, best);
            height = min(height, res.x);
            best = max(best, res.y);
            if (res.y == -1) {
                // cout << "returning: " << u << " " << INT_MAX << " " << -1 << endl;
                return {INT_MAX, -1};
            }
        }
    }
    // cout << "res: " << u << " " << height << " " << best << endl;
    if (best < d[u]) {
        // cout << "returning: " << u << " " << INT_MAX << " " << -1 << endl;
        return {INT_MAX, -1};
    } else {
        // cout << "returning: " << u << " " << height << " " << best << endl;
        return {height, best};
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= N; i++) {
        d[i] = -1;
        h[i] = INT_MAX;
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    solve(1, 0, 0);
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            c = 0;
            break;
        }
    }
    if (!c) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    pii res = check(1, 0, -1);
    if (res.x > 0) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << ans;
    return 0;
}