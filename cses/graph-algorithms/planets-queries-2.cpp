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

int N, Q;
const int M = 18;
int a[200005][M];
vt<int> par[200005]; // parent of node
bool vis[200005];
int len[200005], idx[200005]; // length of cycle, index in cycle
int dist[200005]; // distance of node from cycle

int lift(int x, int k) {
    rrep(i,M-1,0) {
        if (k & (1 << i)) {
            x = a[x][i];
        }
    }
    return x;
}

void find_cycle(int u) {
    vis[u] = 1;
    set<int> s;
    s.insert(u);
    while (!vis[a[u][0]]) {
        u = a[u][0];
        vis[u] = 1;
        s.insert(u);
    }
    if (s.count(a[u][0])) { // cycle found
        u = a[u][0];
        int cnt = 0;
        idx[u] = cnt++;
        int v = a[u][0];
        while (v != u) {
            idx[v] = cnt++;
            v = a[v][0];
        }
        len[u] = cnt;
        v = a[u][0];
        while (v != u) {
            len[v] = cnt;
            v = a[v][0];
        }
    }
}

void dfs(int u, int d) {
    dist[u] = d;
    each(v, par[u]) {
        dfs(v, d+1);
    }
}

int solve(int x, int y) {
    if (len[y] != -1) {
        int ans = dist[x];
        x = lift(x, dist[x]);
        if (idx[y] >= idx[x]) {
            ans += idx[y] - idx[x];
        } else {
            ans += len[y] - idx[x] + idx[y];
        }
        return ans;
    } else if (len[x] != -1 && len[y] == -1) {
        return -1;
    } else {
        if (dist[x] < dist[y]) {
            return -1;
        }
        int ans = dist[x] - dist[y];
        x = lift(x, ans);
        if (x == y) {
            return ans;
        } else {
            return -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> Q;
    DSU dsu(N+1);
    rep(i,1,N+1) {
        cin >> a[i][0];
        par[a[i][0]].pb(i);
        dsu.unite(i, a[i][0]);
        idx[i] = -1;
        len[i] = -1;
    }
    rep(i,1,M) {
        rep(j,1,N+1) {
            a[j][i] = a[a[j][i-1]][i-1];
        }
    }
    rep(i,1,N+1) {
        if (!vis[i]) {
            find_cycle(i);
        }
    }
    rep(i,1,N+1) {
        if (idx[i] == -1) continue;
        each(v,par[i]) {
            if (idx[v] == -1) {
                dfs(v, 1);
            }
        }
    }
    while (Q--) {
        int x, y; cin >> x >> y;
        if (!dsu.same_set(x, y)) {
            cout << -1 << endl;
        } else {
            int ans = solve(x, y);
            cout << ans << endl;
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}