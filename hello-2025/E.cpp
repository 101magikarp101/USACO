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

struct edge {
    int u, v, w;
};

int T, N, M, Q;
vt<edge> adj[405];

struct state {
    int u;
    ll k;
    bool operator<(const state &a) const { return k > a.k; }
};

bool solve(int s, int e, int ma, ll k) {
    vt<int> vis(N+1,INT_MAX);
    priority_queue<state> pq;
    pq.push({s,0});
    vis[s] = 0;
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        if (vis[cur.u] > cur.k) continue;
        if (cur.u == e) return 1;
        each(i,adj[cur.u]) {
            if (cur.k < vis[i.v] && i.w <= ma) {
                vis[i.v] = cur.k;
                pq.push({i.v,cur.k});
            } else if (cur.k+1 < vis[i.v] && i.w > ma && cur.k < k) {
                vis[i.v] = cur.k+1;
                pq.push({i.v,cur.k+1});
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifdef MAGIKARP
    auto start_time = chrono::high_resolution_clock::now();
    #endif

    cin >> T;
    while (T--) {
        cin >> N >> M >> Q;
        rep(i,1,N+1) adj[i].clear();
        vt<int> ws;
        rep(i,0,M) {
            int u, v, w; cin >> u >> v >> w;
            ws.pb(w);
            adj[u].pb({u,v,w});
            adj[v].pb({v,u,w});
        }
        sort(all(ws));
        while (Q--) {
            int u, v; ll k; cin >> u >> v >> k;
            int l = 0, r = M-1;
            while (l < r) {
                int m = (l+r)/2;
                if (solve(u,v,ws[m],k-1)) {
                    r = m;
                } else {
                    l = m+1;
                }
            }
            cout << ws[l] << ' ';
        }
        cout << endl;
    }

    #ifdef MAGIKARP
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - start_time).count();
    cerr << "Time: " << duration << "ms" << endl;
    #endif
    return 0;
}