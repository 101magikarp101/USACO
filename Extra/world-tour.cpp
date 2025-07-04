#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

struct state {
    int u, d;
    bool operator<(const state &s) const {
        return d > s.d;
    }
};

int T, N, M;
vt<int> adj[3005];
int d[3005][3005];
vt<int> vs[3005], ve[3005];

void dij(int s) {
    priority_queue<state> pq;
    pq.push({s, 0});
    while (!pq.empty()) {
        state cur = pq.top();
        pq.pop();
        if (d[s][cur.u] < cur.d) continue;
        for (int v : adj[cur.u]) {
            if (d[s][v] > cur.d + 1) {
                d[s][v] = cur.d + 1;
                pq.push({v, d[s][v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            d[i][j] = 1e9;
        }
        dij(i);
        d[i][i] = 1e9;
    }
    vt<pii> v;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (d[i][j] != 1e9) {
                v.push_back({i, j});
                vs[i].push_back(j);
                ve[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        sort(vs[i].begin(), vs[i].end(), [&](int a, int b) {
            return d[i][a] > d[i][b];
        });
        sort(ve[i].begin(), ve[i].end(), [&](int a, int b) {
            return d[a][i] > d[b][i];
        });
    }
    sort(v.begin(), v.end(), [&](pii a, pii b) {
        return d[a.x][a.y] > d[b.x][b.y];
    });
    int dist = -1;
    vt<int> ans;
    for (pii p : v) {
        int u = p.x, v = p.y;
        for (int i = 0; i < min(3, (int)ve[u].size()); i++) {
            for (int j = 0; j < min(3, (int)vs[v].size()); j++) {
                if (ve[u][i] == v || vs[v][j] == u || ve[u][i] == vs[v][j]) continue;
                int nd = d[ve[u][i]][u] + d[u][v] + d[v][vs[v][j]];
                if (nd > dist) {
                    dist = nd;
                    ans = {ve[u][i], u, v, vs[v][j]};
                }
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}