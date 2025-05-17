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
    int u, d;
    bool operator<(const state &a) const {
        return d > a.d;
    }
};

int T, N, M, K;
int a[200005];
vt<int> adj[200005];
int d[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    a[0] = 1;
    while (T--) {
        cin >> N >> M >> K;
        rep(i,1,N+1) {
            adj[i].clear();
        }
        rep(i,1,K+1) {
            cin >> a[i];
        }
        rep(i,1,K+1) {
            int u = a[i-1], v = a[i];
            adj[u].pb(v);
            adj[v].pb(u);
        }
        rep(i,0,M) {
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        rep(i,1,N+1) {
            d[i] = INT_MAX;
        }
        queue<state> pq;
        pq.push({1, 0});
        d[1] = 0;
        while (!pq.empty()) {
            state cur = pq.front();
            pq.pop();
            each(i, adj[cur.u]) {
                if (d[i] > cur.d + 1) {
                    d[i] = cur.d + 1;
                    pq.push({i, d[i]});
                }
            }
        }
        bool ok = 1;
        rep(i,2,K+1) {
            int u = a[i-1], v = a[i];
            if (d[u] >= d[v]) {
                ok = 0;
                break;
            }
        }
        // cout << "d: ";
        // rep(i,1,N+1) {
        //     cout << d[i] << " ";
        // }
        // cout << endl;
        if (!ok) {
            cout << -1 << endl;
        } else {
            vt<pii> ans;
            rep(i,1,K+1) {
                int u = a[i-1], v = a[i];
                if (u != v) {
                    ans.pb({u, v});
                }
            }
            cout << sz(ans) << endl;
            each(i, ans) {
                cout << i.x << " " << i.y << endl;
            }
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}