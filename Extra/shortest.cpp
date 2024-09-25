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
    bool operator<(const edge& e) const {
        return w > e.w;
    }
};

int N, M;
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
    }
    vt<ll> ans(N+1, 1e18);
    priority_queue<edge> pq;
    pq.push({1, 0});
    ans[1] = 0;
    while (!pq.empty()) {
        edge e = pq.top();
        pq.pop();
        if (ans[e.v] < e.w) continue;
        for (edge f : adj[e.v]) {
            if (ans[f.v] > ans[e.v] + f.w) {
                ans[f.v] = ans[e.v] + f.w;
                pq.push({f.v, ans[f.v]});
            }
        }
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}