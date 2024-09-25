#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
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

struct edge{
    int u, v;
    ll w;
};

struct state {
    int u;
    ll d;
    bool h;
    bool operator<(const state &a) const { return d > a.d; }
};

ll T, N, M, H;
ll dis[200005][2], dis2[200005][2];
int h[200005];
bool ho[200005];
vt<edge> adj[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> H;
        for (int i = 1; i <= N; i++) {
            dis[i][0] = dis[i][1] = 1e18;
            dis2[i][0] = dis2[i][1] = 1e18;
            adj[i].clear();
        }
        for (int i = 0; i < H; i++) {
            cin >> h[i];
            ho[h[i]] = 1;
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u].pb({u, v, w});
            adj[v].pb({v, u, w});
        }
        priority_queue<state> pq;
        pq.push({1, 0LL, ho[1]});
        dis[1][ho[1]] = 0;
        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            if (cur.d > dis[cur.u][cur.h]) continue;
            for (edge e : adj[cur.u]) {
                if (cur.h && cur.d+e.w/2 < dis[e.v][cur.h]) {
                    dis[e.v][cur.h] = cur.d+e.w/2;
                    pq.push({e.v, dis[e.v][cur.h], cur.h});
                } else if (!cur.h && cur.d+e.w < dis[e.v][cur.h]) {
                    dis[e.v][cur.h] = cur.d+e.w;
                    bool nh = cur.h|ho[e.v];
                    pq.push({e.v, dis[e.v][cur.h], nh});
                }
            }
        }
        pq.push({(int)N, 0LL, ho[N]});
        dis2[N][ho[N]] = 0;
        while (!pq.empty()) {
            state cur = pq.top();
            pq.pop();
            if (cur.d > dis2[cur.u][cur.h]) continue;
            for (edge e : adj[cur.u]) {
                if (cur.h && cur.d+e.w/2 < dis2[e.v][cur.h]) {
                    dis2[e.v][cur.h] = cur.d+e.w/2;
                    pq.push({e.v, dis2[e.v][cur.h], cur.h});
                } else if (!cur.h && cur.d+e.w < dis2[e.v][cur.h]) {
                    dis2[e.v][cur.h] = cur.d+e.w;
                    bool nh = cur.h|ho[e.v];
                    pq.push({e.v, dis2[e.v][cur.h], nh});
                }
            }
        }
        ll ans = 1e18;
        for (int i = 1; i <= N; i++) {
            ll res = max(min(dis[i][0], dis[i][1]), min(dis2[i][0], dis2[i][1]));
            ans = min(ans, res);
        }
        cout << (ans==1e18?-1:ans) << endl;
        for (int i = 0; i < H; i++) {
            ho[h[i]] = 0;
        }
    }
    return 0;
}