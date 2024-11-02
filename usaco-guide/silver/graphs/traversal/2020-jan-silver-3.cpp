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

struct edge {
    int v, w;
};

int N, M;
int a[100005];
vt<edge> adj[100005];
int col[100005];
bool vis[100005];

void dfs(int u, int c, int x) {
    col[u] = c;
    vis[u] = 1;
    for (edge e : adj[u]) {
        if (e.w < x) continue;
        if (!vis[e.v]) {
            dfs(e.v, c, x);
        }
    }
}

bool solve(int x) {
    for (int i = 1; i <= N; i++) {
        col[i] = -1;
        vis[i] = 0;
    }
    int cnt = 0;
    bool good = 1;
    for (int i = 1; i <= N; i++) {
        if (col[i] == -1) {
            dfs(i, cnt++, x);
        }
    }
    for (int i = 1; i <= N; i++) {
        if (col[i] != col[a[i]]) {
            good = 0;
            break;
        }
    }
    return good;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    #endif
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    int l = 1, r = 1e9+1;
    while (l < r) {
        int m = (l+r+1)/2;
        if (solve(m)) {
            l = m;
        } else {
            r = m-1;
        }
    }
    cout << (l == 1e9+1 ? -1 : l) << endl;
    return 0;
}