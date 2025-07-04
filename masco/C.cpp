#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct edge {
    int v;
    ll w;
};

struct state {
    int u;
    ll d;
    bool operator<(const state &s) const {
        return d > s.d;
    }
};

int N, M, S, F;
vt<edge> adj[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cin >> S >> F;
    priority_queue<state> pq;
    pq.push({S, 0});
    vt<ll> dist(N+1, 1e18);
    dist[S] = 0;
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        if (cur.d > dist[cur.u]) continue;
        if (cur.u == F) {
            cout << dist[F] << endl;
            return 0;
        }
        for (edge e : adj[cur.u]) {
            if (dist[e.v] > dist[cur.u] + e.w) {
                dist[e.v] = dist[cur.u] + e.w;
                pq.push({e.v, dist[e.v]});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}