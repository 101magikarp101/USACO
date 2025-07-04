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

struct state {
    ll x, y, z;
    state operator+(const state &a) const {
        return {x + a.x, y + a.y, z + a.z};
    }
};

int N, K;
ll ans = 0;
bool fail = 0;
ll a[200005];
state dp[200005];
vt<int> adj[200005];

void solve(int u, int p) {
    state cur = {0, 0, 0};
    ll cap = K;
    if (a[u] != -1) {
        cap -= a[u];
    }
    bool active = 0;
    each(v,adj[u]) {
        if (v == p) continue;
        solve(v, u);
        cur = cur + dp[v];
        if (a[v] != -1) {
            cap -= a[v];
        } else {
            active = 1;
        }
    }
    if (cap < 0) {
        fail = 1;
        return;
    }
    ll hm = cur.y+cur.z;
    if (hm >= cap) {
        ll cut = hm - cap;
        ll c1 = min(cut, cur.z);
        cur.z -= c1;
        cut -= c1;
        ll c2 = min(cut, cur.y);
        cur.y -= c2;
        cut -= c2;
        if (cut > 0) {
            fail = 1;
            return;
        }
        hm = cap;
    }
    state res = {cur.x+cur.y, cur.z + (cap-hm), cur.y};
    if (a[u] == -1) {
        dp[u] = res;
        return;
    } else if (active) {
        ans += res.x;
    }
    ans += a[u];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> K;
    rep(i,1,N+1) cin >> a[i];
    a[0] = 0;
    adj[0].pb(1);
    rep(i,0,N-1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    solve(0,-1);
    if (fail) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}