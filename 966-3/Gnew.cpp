#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

struct edge {
    int v;
    ll w1, w2;
};

struct state {
    int u;
    ll t;
    bool operator<(const state &s) const {
        return t < s.t;
    }
    bool operator>(const state &s) const {
        return t > s.t;
    }
};

int T, N, M;
vt<edge> adj[100005];
ll t0, t1, t2;

pll intersect(ll x, ll y) {
    ll l = max(x,t1), r = min(y,t2);
    return {l,r};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        cin >> t0 >> t1 >> t2;
        for (int i = 0; i < M; i++) {
            int u, v; ll w1, w2;
            cin >> u >> v >> w1 >> w2;
            adj[u].push_back({v,w1,w2});
            adj[v].push_back({u,w1,w2});
        }
        ll ans = -1;
        vt<ll> d1(N+1,1e18);
        priority_queue<state, vt<state>, greater<state>> pq;
        pq.push({1,0});
        while (!pq.empty()) {
            state s = pq.top();
            pq.pop();
            if (d1[s.u] < s.t) {
                continue;
            }
            d1[s.u] = s.t;
            for (edge e : adj[s.u]) {
                if (d1[e.v] > s.t+e.w1) {
                    pq.push({e.v,s.t+e.w1});
                }
            }
        }
        if (d1[N] <= t1) {
            ans = t1-d1[N];
        }
        vt<ll> d(N+1,-1);
        priority_queue<state> pq1;
        pq1.push({N,t0});
        while (!pq1.empty()) {
            state s = pq1.top();
            pq1.pop();
            if (d[s.u] > s.t) {
                continue;
            }
            for (edge e : adj[s.u]) {
                pll i = intersect(s.t-e.w1,s.t);
                if (i.x<i.y) {
                    pll ii = intersect(s.t-e.w2,s.t);
                    ll best = min(s.t-ii.x+e.w1,e.w2);
                    if (d[e.v] < s.t-best) {
                        d[e.v] = s.t-best;
                        pq1.push({e.v,s.t-best});
                    }
                } else {
                    if (d[e.v] < s.t-e.w1) {
                        d[e.v] = s.t-e.w1;
                        pq1.push({e.v,s.t-e.w1});
                    }
                }
            }
        }
        cout << max(ans,d[1]) << endl;
    }
    return 0;
}