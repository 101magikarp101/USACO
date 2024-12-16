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
int p[500005];
vt<int> comp;

vt<int> adj[200005];
int a[200005];
int vis[400005];

void sieve(int n) {
    p[0] = p[1] = 1;
    comp.pb(1);
    for (int i = 2; i <= n; i++) {
        if (p[i]) comp.pb(i);
        if (!p[i]) {
            for (int j = i+i; j <= n; j += i) {
                p[j] = 1;
            }
        }
    }
}

void solve(int u, int par, int c) {
    if (c > 2*N) return;
    a[u] = c;
    vis[c] = 1;
    // cout << "u: " << u << " c: " << c << endl;
    int d = 0;
    for (int v : adj[u]) {
        if (v == par) continue;
        if (c-1 > 0 && !vis[c-1]) {
            solve(v,u,c-1);
        } else {
            while (comp[d]+c <= 2*N && vis[comp[d]+c]) d++;
            solve(v,u,c+comp[d]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    sieve(500000);
    cin >> T;
    while (T--) {
        cin >> N;
        rep(i,1,2*N+1) vis[i] = 0;
        rep(i,1,N+1) adj[i].clear();
        rep(i,0,N-1) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        solve(1,0,1);
        bool bad = 0;
        rep(i,1,N+1) {
            if (a[i] == 0) {
                bad = 1;
                break;
            }
        }
        // rep(i,1,N+1) cout << a[i] << " ";
        //     cout << endl;
        if (bad) {
            cout << -1 << endl;
        } else {
            rep(i,1,N+1) cout << a[i] << " ";
            cout << endl;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end-start;
    cerr << "Elapsed time: " << elapsed.count() << "s" << endl;
    return 0;
}