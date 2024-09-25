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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct edge {
    ll u, v, w;
};

struct state {
    ll n, d, b;
};

int T, N, M;
vector<edge> adj[1003];
ll best[1003][1003];
ll bi[1003];

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            for (int j = 1; j <= 1000; j++) {
                best[i][j] = 1e18;
            }
        }
        for (int i = 0; i < M; i++) {
            ll u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({u, v, w});
            adj[v].push_back({v, u, w});
        }
        for (int i = 1; i <= N; i++) {
            cin >> bi[i];
        }
        queue<state> q;
        q.push({1, 0, bi[1]});
        while (!q.empty()) {
            state cur = q.front();
            q.pop();
            if (best[cur.n][cur.b] <= cur.d) {
                continue;
            } else {
                best[cur.n][cur.b] = cur.d;
            }
            ll b = min(cur.b, bi[cur.n]);
            for (edge e : adj[cur.n]) {
                ll dis = cur.d + e.w*b;
                if (dis < best[e.v][b]) {
                    q.push({e.v, dis, b});
                }
            }
        }
        ll ans = 1e18;
        for (int i = 1; i <= 1000; i++) {
            ans = min(ans, best[N][i]);
        }
        cout << ans << endl;
    }
}