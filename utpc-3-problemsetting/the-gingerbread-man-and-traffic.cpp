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
    int u, v, w;
};

struct state {
    int u, d;
    bool operator<(const state &s) const {
        return d > s.d;
    }
};

int N, M;
vt<edge> adj[100005];
int dist[100005], r[100005], g[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> N >> M;
    rep(i,1,N+1) {
        cin >> r[i] >> g[i];
    }
    rep(i,0,M) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({u, v, w});
        adj[v].pb({v, u, w});
    }
    rep(i,1,N+1) {
        dist[i] = 1e9;
    }
    priority_queue<state> pq;
    pq.push({1, 0});
    dist[1] = 0;
    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();
        if (s.d > dist[s.u]) continue;
        if (s.u == N) {
            cout << s.d << endl;
            break;
        }
        int rem = s.d % (r[s.u] + g[s.u]);
        if (rem >= r[s.u] && rem < r[s.u] + g[s.u]) {
            s.d += r[s.u] + g[s.u] - rem;
        }
        each(i, adj[s.u]) {
            if (dist[i.v] > s.d + i.w) {
                dist[i.v] = s.d + i.w;
                pq.push({i.v, dist[i.v]});
            }
        }
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}