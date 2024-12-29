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
#define rrep(i,a,b) for(int i=a;i>=b;i--)
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

int T, N;
vt<int> adj[200005];
int d[200005], dep[200005];
int cnt[200005], par[200005];

void dfs(int u, int p, int depth) {
    dep[u] = depth;
    par[u] = p;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, depth+1);
        }
    }
}

void dfs1(int u, int p) {
    cnt[u] = (d[u] >= 2);
    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            cnt[u] += cnt[v];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,1,N+1) {
            adj[i].clear();
            d[i] = 1e9;
            dep[i] = -1;
            cnt[i] = 0;
        }
        rep(i,0,N-1) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        ll ans = 0;
        ll leaf = 0;
        queue<int> q;
        rep(i,1,N+1) {
            if (sz(adj[i]) == 1) {
                leaf++;
                d[i] = 0;
                q.push(i);
            }
        }
        ans = leaf*(N-leaf);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (d[v] == 1e9) {
                    d[v] = d[u]+1;
                    q.push(v);
                }
            }
        }
        dfs(1,0,0);
        dfs1(1,0);
        // cout << "d: ";
        // rep(i,1,N+1) cout << d[i] << ' ';
        // cout << endl;
        // cout << "dep: ";
        // rep(i,1,N+1) cout << dep[i] << ' ';
        // cout << endl;
        // cout << "cnt: ";
        // rep(i,1,N+1) cout << cnt[i] << ' ';
        // cout << endl;
        rep(i,1,N+1) {
            if (d[i] == 0) continue;
            ll up = cnt[1]-cnt[i];
            if (par[i] != 0 && d[par[i]] == 1) {
                // cout << "i: " << i << " par[i]: " << par[i] << " up: " << up << endl;
                ans+=up;
            }
            for (int v : adj[i]) {
                if (v != par[i]) {
                    ll down = cnt[v];
                    if (d[v] == 1) {
                        ans+=down;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}