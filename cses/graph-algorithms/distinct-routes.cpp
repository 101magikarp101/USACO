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

int N, M;

template <class T = int> struct Dinic {
    const static bool SCALING = false; // non-scaling = V^2E, Scaling=VElog(U) with higher constant
    int N;
    int lim = 1;
    const T INF = numeric_limits<T>::max();
    struct edge {
        int to, rev;
        T cap, flow;
    };
    vt<int> level, ptr;
    vt<vt<edge>> adj;
    void init(int N) {
        this->N = N;
        level.resize(N); ptr.resize(N); adj.resize(N);
    }
    void addEdge(int a, int b, T cap, bool isDirected = true) {
        adj[a].push_back({b, sz(adj[b]), cap, 0});
        adj[b].push_back({a, sz(adj[a]) - 1, isDirected ? 0 : cap, 0});
    }
    bool bfs(int s, int t) {
        queue<int> q({s});
        fill(all(level), -1);
        level[s] = 0;
        while (!q.empty() && level[t] == -1) {
            int v = q.front();
            q.pop();
            for (auto e : adj[v]) {
                if (level[e.to] == -1 && e.flow < e.cap && (!SCALING || e.cap - e.flow >= lim)) {
                    q.push(e.to);
                    level[e.to] = level[v] + 1;
                }
            }
        }
        return level[t] != -1;
    }
    T dfs(int v, int t, T flow) {
        if (v == t || !flow)
            return flow;
        for (; ptr[v] < adj[v].size(); ptr[v]++) {
            edge &e = adj[v][ptr[v]];
            if (level[e.to] != level[v] + 1)
                continue;
            if (T pushed = dfs(e.to, t, min(flow, e.cap - e.flow))) {
                e.flow += pushed;
                adj[e.to][e.rev].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    long long calc(int s, int t) {
        long long flow = 0;
        for (lim = SCALING ? (1 << 30) : 1; lim > 0; lim >>= 1) {
            while (bfs(s, t)) {
                fill(all(ptr), 0);
                while (T pushed = dfs(s, t, INF))
                    flow += pushed;
            }
        }
        return flow;
    }
};

void solve(int i, int u, vt<vt<int>> &ans, Dinic<int> &dinic) {
    ans[i].pb(u);
    if (u == N) return;
    for (auto &e : dinic.adj[u]) {
        if (e.flow == 1) {
            e.flow = 0;
            solve(i, e.to, ans, dinic);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    Dinic dinic;
    dinic.init(N+1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        dinic.addEdge(u, v, 1);
    }
    int n = dinic.calc(1, N);
    cout << n << endl;
    vt<vt<int>> ans(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        solve(i, 1, ans, dinic);
    }
    for (auto &v : ans) {
        cout << sz(v) << endl;
        for (auto &x : v) {
            cout << x << ' ';
        }
        cout << endl;
    }
    return 0;
}