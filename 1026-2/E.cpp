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
    int v, w;
};

int T, N;
pii a[200005];
vt<edge> adj[400005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N;
        uset<int> sx, sy;
        rep(i,0,N) {
            cin >> a[i].x >> a[i].y;
            sx.insert(a[i].x);
            sy.insert(a[i].y);
        }
        umap<int, int> mx, my;
        int n = 0;
        for (auto &x : sx) mx[x] = n++;
        for (auto &y : sy) my[y] = n++;
        rep(i,0,N) {
            a[i].x = mx[a[i].x];
            a[i].y = my[a[i].y];
        }
        rep(i,0,n) {
            adj[i].clear();
        }
        rep(i,0,N) {
            int x = a[i].x, y = a[i].y;
            adj[x].pb({y, i+1});
            adj[y].pb({x, i+1});
        }
        // odd check
        int o = 0;
        int start = 0;
        rep(i,0,n) {
            if (sz(adj[i]) & 1) {
                o++;
                start = i;
            }
        }
        if (o != 0 && o != 2) {
            cout << "NO" << endl;
            continue;
        }
        vt<bool> vis(N, 0);
        vt<int> path;
        stack<pii> s; // node, edge_id
        s.push({start, -1});
        // Hierholzer's
        while (!s.empty()) {
            auto [u, edge_id] = s.top();
            // cout << "Visiting node: " << u << ", edge_id: " << edge_id << endl;
            while (!adj[u].empty() && vis[adj[u].back().w - 1]) {
                adj[u].pop_back();
            }
            if (adj[u].empty()) {
                if (edge_id != -1) {
                    path.pb(edge_id);
                }
                s.pop();
            } else {
                auto [v, id] = adj[u].back();
                vis[id - 1] = true;
                s.push({v, id});
                adj[u].pop_back();
            }
        }
        if (sz(path) != N) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            each(id, path) {
                cout << id << " ";
            }
            cout << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}