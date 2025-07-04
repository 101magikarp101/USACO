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

struct edge {
    int u, v;
    ll w;
    bool operator<(const edge &a) const { return w < a.w; }
};

struct state {
    int u;
    ll d;
    bool b;
    bool operator<(const state &a) const {
        return d > a.d;
    }
};

int N, M;
vt<edge> adj[200005];
ll d[200005][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    rep(i,0,M) {
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        adj[u].pb({u, v, w});
    }
    priority_queue<state> pq;
    rep(i,1,N+1) {
        d[i][0] = 1e18;
        d[i][1] = 1e18;
    }
    d[1][0] = 0;
    pq.push({1, 0, 0});
    while (!pq.empty()) {
        state s = pq.top(); pq.pop();
        if (s.u == N) break;
        if (s.d > d[s.u][s.b]) continue;
        each(e,adj[s.u]) {
            if (s.b) {
                if (d[e.v][1] > d[s.u][1] + e.w) {
                    d[e.v][1] = d[s.u][1] + e.w;
                    pq.push({e.v, d[e.v][1], 1});
                }
            } else {
                if (d[e.v][0] > d[s.u][0] + e.w) {
                    d[e.v][0] = d[s.u][0] + e.w;
                    pq.push({e.v, d[e.v][0], 0});
                }
                if (d[e.v][1] > d[s.u][0] + e.w / 2) {
                    d[e.v][1] = d[s.u][0] + e.w / 2;
                    pq.push({e.v, d[e.v][1], 1});
                }
            }
        }
    }
    cout << min(d[N][0], d[N][1]) << endl;

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}