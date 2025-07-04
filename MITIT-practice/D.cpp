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
    ll f, r;
};

struct state {
    int n;
    ll c;
    bool operator<(const state &s) const {
        return c < s.c;
    }
};

int N, M;
vt<edge> adj[100005];

bool check(ll n) {
    vt<ll> dist(N+1, -1e18);
    priority_queue<state> pq;
    pq.push({1, n});
    while (!pq.empty()) {
        state s = pq.top();
        pq.pop();
        if (dist[s.n] > s.c) {
            continue;
        }
        dist[s.n] = s.c;
        if (s.n == N) {
            return true;
        }
        for (edge e : adj[s.n]) {
            if (s.c >= e.f && e.r > 0) {
                return true;
            } else if (s.c >= e.f && dist[e.v] < s.c+e.r) {
                if (s.c+e.r >= 0) {
                    dist[e.v] = s.c+e.r;
                    pq.push({e.v, s.c+e.r});
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        ll f, r;
        cin >> u >> v >> f >> r;
        adj[u].push_back({v, f, r-f});
        adj[v].push_back({u, f, r-f});
    }
    ll l = 0, r = 1e14;
    while (l < r) {
        ll m = (l+r)/2;
        if (check(m)) {
            r = m;
        } else {
            l = m+1;
        }
    }
    cout << l << "\n";
    return 0;
}