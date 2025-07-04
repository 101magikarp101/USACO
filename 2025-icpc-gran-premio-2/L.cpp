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
#define yesno(x) cout<<(x?"YES":"NO")<<endl
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

int N;
int a[100005];
string s;
ll ans = 0;

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

void dfs(int u, int p, int cur, int mif, int mib, vvi& adj, vt<bool>& rem, vi& hmf, vi& hmb) {
    cur += a[u];
    ckmin(mif, cur);
    ckmin(mib, -cur);
    // cerr << "Visiting node " << u << " with current value " << cur << ", mif: " << mif << ", mib: " << mib << endl;
    if (cur == mif) {
        if (sz(hmf) <= -mif) hmf.pb(1);
        else hmf[-mif]++;
    }
    if (-cur == mib) {
        if (sz(hmb) <= -mib) hmb.pb(1);
        else hmb[-mib]++;
    }
    each(v, adj[u]) {
        if (v != p && !rem[v]) {
            dfs(v, u, cur, mif, mib, adj, rem, hmf, hmb);
        }
    }
}

void build(int u, int p, vvi& adj, vt<bool>& rem, vi& szs, vi& par) {
    int siz = dfs_sz(u, -1, adj, rem, szs);
    int c = dfs_centroid(u, -1, siz, adj, rem, szs);
    par[c] = p;
    rem[c] = true;
    vvi hmfs, hmbs;
    each(v, adj[c]) {
        if (!rem[v]) {
            vi hmf = {0}, hmb = {0};
            dfs(v, c, 0, 0, 0, adj, rem, hmf, hmb);
            hmfs.pb(hmf);
            hmbs.pb(hmb);
        }
    }
    int maf = 0, mab = 0;
    rep(i,0,sz(hmfs)) ckmax(maf, sz(hmfs[i]));
    rep(i,0,sz(hmbs)) ckmax(mab, sz(hmbs[i]));
    // cerr << "Centroid: " << c << ", size: " << siz << ", maf: " << maf << ", mab: " << mab << endl;
    vi totf(maf,0), totb(mab,0);
    rep(i,0,sz(hmfs)) {
        rep(j,0,sz(hmfs[i])) {
            totf[j] += hmfs[i][j];
        }
    }
    rep(i,0,sz(hmbs)) {
        rep(j,0,sz(hmbs[i])) {
            totb[j] += hmbs[i][j];
        }
    }
    rep(i,0,sz(hmbs)) {
        rep(j,0,sz(hmbs[i])) {
            int o = (0<=j+a[c]&&j+a[c]<maf ? totf[j+a[c]] : 0);
            o -= (0<=j+a[c]&&j+a[c]<sz(hmfs[i]) ? hmfs[i][j+a[c]] : 0);
            ans += (ll)o * hmbs[i][j];
        }
    }
    if (a[c] == -1) {
        rep(i,0,sz(hmbs)) {
            if (sz(hmbs[i]) > 1) ans += hmbs[i][1];
        }
    } else if (a[c] == 1) {
        rep(i,0,sz(hmfs)) {
            if (sz(hmfs[i]) > 1) ans += hmfs[i][1];
        }
    }
    // cout << "Centroid: " << c << ", ans: " << ans << endl;
    for (int v : adj[c]) 
        if (!rem[v])
            build(v, c, adj, rem, szs, par);
}

// Function to perform centroid decomposition on a tree represented by an adjacency list
vi centroid(vvi& adj) {
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

    cin >> N;
    cin >> s;
    rep(i,0,N) a[i] = (s[i]=='(')*2-1;
    vvi adj(N);
    rep(i,0,N-1) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    auto par = centroid(adj);
    // rep(i,0,N) {
    //     cout << par[i] << endl;
    // }
    cout << ans << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration/1000000.0 << "ms" << endl;
    #endif
    return 0;
}