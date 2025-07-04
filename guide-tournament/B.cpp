#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>
#include <unordered_map>
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct edge {
    ll u, v, w;
    bool n;
};

struct state {
    ll to, d;
    bool u;
    bool operator<(const state &s) const {
        return d > s.d;
    }
};

ll N, M, K, s, t;
vt<edge> adj[10005];
ll dist[10005][2];

int main () {
    cin >> N >> M >> K >> s >> t;
    for (int i = 0; i < M; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({u, v, w, false});
    }
    for (int j = 1; j <= N; j++) {
        dist[j][0] = LLONG_MAX;
        dist[j][1] = LLONG_MAX;
    }
    for (int i = 0; i < K; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({u, v, w, true});
    }
    priority_queue<state> pq;
    pq.push({s, 0, false});
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        if (dist[cur.to][cur.u] != LLONG_MAX) continue;
        dist[cur.to][cur.u] = cur.d;
        if (cur.to == t) {
            break;
        }
        for (edge e : adj[cur.to]) {
            if (e.n && !cur.u) {
                if (dist[e.v][1] == LLONG_MAX) {
                    pq.push({e.v, cur.d+e.w, true});
                }
            } else if (!e.n) {
                if (dist[e.v][cur.u] == LLONG_MAX) {
                    pq.push({e.v, cur.d+e.w, cur.u});
                }
            }
        }
    }
    cout << min(dist[t][0], dist[t][1]) << endl;
}