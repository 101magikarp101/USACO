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

int T, N;
vt<int> adj1[1005], adj2[1005];
bool fin[1005];
int d[1005][1005];

struct state {
    int u, v, d;
    bool operator<(const state &a) const { return d > a.d; }
};

int bfs(int s1, int s2) {
    rep(i,1,N+1) {
        rep(j,1,N+1) {
            d[i][j] = 1e9;
        }
    }
    d[s1][s2] = 0;
    priority_queue<state> pq;
    pq.push({s1,s2,0});
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        if (d[cur.u][cur.v] < cur.d) continue;
        if (cur.u == cur.v && fin[cur.u]) return cur.d;
        for (int u : adj1[cur.u]) {
            for (int v : adj2[cur.v]) {
                int dist = cur.d + abs(u-v);
                if (d[u][v] > dist) {
                    d[u][v] = dist;
                    pq.push({u,v,dist});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        int s1, s2;
        cin >> N >> s1 >> s2;
        rep(i,1,N+1) {
            adj1[i].clear();
            adj2[i].clear();
            fin[i] = 0;
        }
        int m1, m2;
        cin >> m1;
        set<pii> e;
        rep(i,0,m1) {
            int u, v;
            cin >> u >> v;
            adj1[u].pb(v);
            adj1[v].pb(u);
            e.insert({u,v});
        }
        cin >> m2;
        rep(i,0,m2) {
            int u, v;
            cin >> u >> v;
            adj2[u].pb(v);
            adj2[v].pb(u);
            if (e.count({u,v}) || e.count({v,u})) {
                fin[u] = 1;
                fin[v] = 1;
            }
        }
        int ans = bfs(s1,s2);
        cout << ans << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}