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
    int u, v, c;
};

struct state {
    int u, d;
    bool operator<(const state& o) const {
        return d > o.d;
    }
};

int T, N, M;
vt<vt<edge>> adj;
map<int,vt<int>> mp;
vt<bool> vis;

void fill(int n, int c) {
    vis[n] = true;
    for (edge e : adj[n]) {
        if (!vis[e.v] && e.c==c) {
            fill(e.v,c);
        }
    }
    mp[c].push_back(n);
}

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> M;
        adj.resize(N+1);
        vis.resize(N+1);
        mp.clear();
        for (int i = 0; i < M; i++) {
            int u, v, c; cin >> u >> v >> c;
            adj[u].push_back({u,v,c});
            adj[v].push_back({v,u,c});
        }
        for (int i = 1; i <= N; i++) {
            if (!vis[i]) {
                fill(i,
            }
        }
        priority_queue<state> pq;
    }
    return 0;
}