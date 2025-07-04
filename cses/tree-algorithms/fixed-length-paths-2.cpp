#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
template <class T> using vvt = vt<vt<T>>;
template <class T> using vvvt = vt<vvt<T>>;
template <class T> using vvvvt = vt<vvvt<T>>;
typedef vt<int> vi;
typedef vvt<int> vvi;
typedef vvvt<int> vvvi;
typedef vvvvt<int> vvvvi;
typedef vt<ll> vl;
typedef vvt<ll> vvl;
typedef vvvt<ll> vvvl;
typedef vvvvt<ll> vvvvl;
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)((x).size())
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
    void operator+=(const pii &a) { x += a.x; y += a.y; }
    void operator-=(const pii &a) { x -= a.x; y -= a.y; }
    void operator*=(const int &a) { x *= a; y *= a; }
    void operator/=(const int &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pii &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pii &p) {return is >> p.x >> p.y;}
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
    void operator+=(const pll &a) { x += a.x; y += a.y; }
    void operator-=(const pll &a) { x -= a.x; y -= a.y; }
    void operator*=(const ll &a) { x *= a; y *= a; }
    void operator/=(const ll &a) { x /= a; y /= a; }
    friend ostream& operator<<(ostream &os, const pll &p) {return os << "(" << p.x << ", " << p.y << ")";}
    friend istream& operator>>(istream &is, pll &p) {return is >> p.x >> p.y;}
};
static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x^(x>>30))*0xbf58476d1ce4e5b9;
    x = (x^(x>>27))*0x94d049bb133111eb;
    return x^(x>>31);
}
struct custom_hash {
    static const uint64_t FIXED_RANDOM;
    size_t operator()(uint64_t x) const {return splitmix64(x + FIXED_RANDOM);}
    template<typename T> size_t operator()(const T& t) const {return splitmix64(uint64_t(std::hash<T>{}(t)) + FIXED_RANDOM);}
};
const uint64_t custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(custom_hash::FIXED_RANDOM);
template<typename K, typename V> using umap = unordered_map<K, V, custom_hash>;
template<typename K> using uset = unordered_set<K, custom_hash>;
template<typename T> using umset = unordered_multiset<T, custom_hash>;
template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; }

int N, K1, K2;
ll ans = 0, ans2 = 0;

int dfs_sz(int u, int p, vvi& adj, vt<bool>& rem, vi& szs) {
    szs[u] = 1;
    for (int v : adj[u])
        if (v != p && !rem[v])
            szs[u] += dfs_sz(v, u, adj, rem, szs);
    return szs[u];
}

int dfs_centroid(int u, int p, int tot, vvi& adj, vt<bool>& rem, vi& szs) {
    for (int v : adj[u]) 
        if (v != p && !rem[v] && szs[v] > tot / 2)
            return dfs_centroid(v, u, tot, adj, rem, szs);
    return u;
}

void dfs_dep(int u, int p, int d, vvi& adj, vt<bool>& rem, vi& dep) {
    if (sz(dep) <= d) dep.pb(1);
    else dep[d]++;
    for (int v : adj[u]) 
        if (v != p && !rem[v])
            dfs_dep(v, u, d + 1, adj, rem, dep);
}

void build(int u, int p, vvi& adj, vt<bool>& rem, vi& szs, vi& par) {
    int siz = dfs_sz(u, -1, adj, rem, szs);
    int c = dfs_centroid(u, -1, siz, adj, rem, szs);
    par[c] = p;
    rem[c] = true;
    vvi deps;
    each(v, adj[c]) {
        if (rem[v]) continue;
        vi dep(1,0);
        dfs_dep(v, c, 1, adj, rem, dep);
        deps.pb(dep);
    }
    // cout << "Centroid: " << c << ", Parent: " << p << endl;
    int m = -1;
    rep(i,0,sz(deps)) {
        ckmax(m, sz(deps[i]));
    }
    if (m != -1) {
        vi tot(m,0);
        rep(i,0,sz(deps)) {
            rep(j,0,sz(deps[i])) {
                // cerr << "deps[" << i << "][" << j << "] = " << deps[i][j] << endl;
                tot[j] += deps[i][j];
            }
        }
        rep(i,1,m) {
            tot[i] += tot[i-1];
        }
        vvi pre = deps;
        rep(i,0,sz(pre)) {
            rep(j,0,sz(pre[i])) {
                if (j) pre[i][j] += pre[i][j-1];
            }
        }
        rep(i,0,sz(deps)) {
            rep(j,1,sz(deps[i])) {
                // cout << "i = " << i << ", j = " << j << endl;
                int up = min(m-1,max(0,K2-j));
                int down = min(m-1,max(0,K1-j-1));
                // cout << "up = " << up << ", down = " << down << endl;
                ll res = tot[up] - tot[down];
                int up1 = min(sz(pre[i])-1,max(0,K2-j));
                int down1 = min(sz(pre[i])-1,max(0,K1-j-1));
                // cout << "up1 = " << up1 << ", down1 = " << down1 << endl;
                res -= pre[i][up1] - pre[i][down1];
                // cout << "res = " << res << endl;
                ans += (ll)deps[i][j] * res;
            }
        }
        rep(i,0,sz(deps)) {
            int up1 = min(sz(deps[i])-1,max(0,K2));
            int down1 = min(sz(deps[i])-1,max(0,K1-1));
            // cout << "i = " << i << ", up1 = " << up1 << ", down1 = " << down1 << endl;
            // cout << "res = " << pre[i][up1] - pre[i][down1] << endl;
            ans2 += pre[i][up1] - pre[i][down1];
        }
    }
    // cerr << "ans = " << ans << endl;
    // cerr << "ans2 = " << ans2 << endl;
    for (int v : adj[c]) 
        if (!rem[v])
            build(v, c, adj, rem, szs, par);
}

// Function to perform centroid decomposition on a tree represented by an adjacency list
vi centroidDecomposition(vvi& adj) {
    int n = sz(adj);
    vi szs(n,0);
    vt<bool> rem(n,0);
    vi par(n,-1);
    build(0, -1, adj, rem, szs, par);
    return par;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> K1 >> K2;
    vvi adj(N);
    rep(i,0,N-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi par = centroidDecomposition(adj);
    cout << ans/2 + ans2 << endl;
    // rep(i,0,N) {
    //     cout << i << ": " << par[i] << endl;
    // }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}