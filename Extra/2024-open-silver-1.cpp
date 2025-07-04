#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {
    ll x, y;
    bool operator<(const pll& a) const {
        return x > a.x;
    }
};

struct edge {
    ll v, t;
};

ll N, K;
ll a[300005];
vt<edge> adj[300005];
bool vis[300005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    priority_queue<pll> pq; //time, index
    for (ll i = 0; i < K; i++) {
        pq.push({a[i], i});
    }
    int cur = K;
    pll last = {-1, -1};
    while (true) {
        pll p = pq.top();
        // cout << p.x << " " << p.y << "\n";
        pq.pop();
        vt<pll> v = {p};
        while (!pq.empty() && pq.top().x == p.x) {
            v.push_back(pq.top());
            pq.pop();
        }
        for (int i = 0; i < v.size()-1; i++) {
            adj[v[i].y].push_back({v[i+1].y, v[i].x});
            adj[v[i+1].y].push_back({v[i].y, v[i].x});
        }
        for (int i = 0; i < v.size(); i++) {
            if (cur == N) {
                last = v[i];
                break;
            }
            pq.push({v[i].x+a[cur], v[i].y});
            // cout << "pushing " << v[i].x+a[cur] << " " << v[i].y << "\n";
            cur++;
        }
        if (last.x != -1) {
            break;
        }
    }
    // if (last.x == -1) {
    //     last = pq.top();
    //     pq.pop();
    //     vt<pll> v = {last};
    //     while (!pq.empty() && pq.top().x == last.x) {
    //         v.push_back(pq.top());
    //         pq.pop();
    //     }
    //     for (int i = 0; i < v.size()-1; i++) {
    //         adj[v[i].y].push_back(v[i+1].y);
    //         adj[v[i+1].y].push_back(v[i].y);
    //     }
    // }
    queue<pll> q;
    q.push({last.y, LLONG_MAX});
    vis[last.y] = true;
    while (!q.empty()) {
        pll u = q.front();
        q.pop();
        for (edge e : adj[u.x]) {
            if (!vis[e.v] && e.t <= u.y) {
                vis[e.v] = true;
                q.push({e.v, e.t});
            }
        }
    }
    cout << last.x << "\n";
    for (int i = 0; i < K; i++) {
        cout << (vis[i] ? "1" : "0");
    }
    return 0;
}