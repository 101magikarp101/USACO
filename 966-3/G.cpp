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
        return t > s.t;
    }
};


int T, N, M;
vt<edge> adj[100005];
ll t0, t1, t2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cin >> t0 >> t1 >> t2;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < M; i++) {
            int u, v; ll w1, w2;
            cin >> u >> v >> w1 >> w2;
            adj[u].push_back({v,w1,w2});
            adj[v].push_back({u,w1,w2});
        }
        vt<ll> d1(N+1,1e18), dn(N+1,1e18);
        priority_queue<state> pq;
        pq.push({N,0});
        while (!pq.empty()) {
            state s = pq.top();
            pq.pop();
            if (dn[s.u] <= s.t) {
                continue;
            }
            dn[s.u] = s.t;
            for (edge e : adj[s.u]) {
                if (dn[e.v] > s.t+e.w1) {
                    pq.push({e.v,s.t+e.w1});
                }
            }
        }
        pq.push({1,0});
        while (!pq.empty()) {
            state s = pq.top();
            pq.pop();
            if (d1[s.u] <= s.t) {
                continue;
            }
            d1[s.u] = s.t;
            for (edge e : adj[s.u]) {
                if (d1[e.v] > s.t+e.w1) {
                    pq.push({e.v,s.t+e.w1});
                }
            }
        }
        ll ans = -1;
        ll d = d1[N];
        for (int i = 1; i <= N; i++) {
            if (d1[i]<=t1 && dn[i]+t2-t1 <= t0-t1) {
                if (i==1) {
                    ans = max(ans,t0-d);
                } else {
                    ans = max(ans,t1-d1[i]);
                }
            }
            cout << "i: " << i << " d1: " << d1[i] << " dn: " << dn[i] << endl;
            cout << "ans: " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}