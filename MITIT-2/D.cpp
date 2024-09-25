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
    int u;
    ll c, r;
};

struct node {
    ll c;
    vt<edge> adj;
};

int N, M;
node nodes[100005];
ll dist[100005];

bool solve(ll x) {
    for (int i = 1; i <= N; i++) {
        dist[i] = -1;
    }
    dist[1] = x;
    queue<pll> pq;
    pq.push({x, 1});
    while (!pq.empty()) {
        pll cur = pq.front();
        pq.pop();
        for (edge e : nodes[cur.second].adj) {
            if (cur.first < e.c) continue;
            if (e.r >= 1) return true;
            ll newCost = cur.first + e.r;
            if (newCost > dist[e.u]) {
                dist[e.u] = newCost;
                pq.push({newCost, e.u});
            }
        }
    }
    return dist[N] >= 0;
}

int main () {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int u, v;
        ll c, r;
        cin >> u >> v >> c >> r;
        nodes[u].adj.push_back({v, c, r-c});
        nodes[v].adj.push_back({u, c, r-c});
    }
    ll low = 0, high = 1e14+5;
    while (low < high) {
        ll mid = (low+high)/2;
        if (solve(mid)) high = mid;
        else low = mid+1;
    }
    cout << low << '\n';
}
