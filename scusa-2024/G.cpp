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
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;i++)
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

int N, M, K;
vt<int> adj[100005];
int out[100005];
bool vis[100005], vis1[100005];

int dfs(int u) {
    vis[u] = 1;
    int siz = 1;
    for (int &v : adj[u]) {
        if (!vis[v]) {
            siz += dfs(v);
        }
    }
    return siz;
}

bool dfs1(int u, int s) {
    vis1[u] = 1;
    if (out[u] != s) return 0;
    bool good = 1;
    for (int &v : adj[u]) {
        if (!vis1[v]) {
            good &= dfs1(v, s);
        }
    }
    return good;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    rep(i,0,M) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        out[u]++;
    }
    int ans = 0;
    rep(i,1,N+1) {
        if (!vis[i]) {
            int siz = dfs(i);
            if (siz == K) {
                ans += dfs1(i, siz-1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}