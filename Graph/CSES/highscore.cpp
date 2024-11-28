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
struct pii {int x, y;};
struct pll {int x, y;};

struct edge {
    int v;
    ll w;
};

struct state {
    int u;
    ll d;
};

int N, M;
vt<edge> adj;
ll dist[2505];

int main() {
    cin >> N >> M;
    adj.resize(N+5);
    for (int i = 0; i < M; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for (int i = 1; i <= N; i++) {
        dist[i] = LLONG_MAX;
    }
    queue<state> q;
    q.push({1, 0});
    while (!q.empty()) {
        state cur = q.front();
        q.pop();
        if (dist[cur.u] <= cur.d) continue;
    }
    return 0;
}