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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

struct edge{
    int to;
    ll w;
};

int N, Q;
vector<edge> adj[5005];
bool vis[5005];

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    cin >> N >> Q;
    for (int i = 0; i < N-1; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        memset(vis, false, sizeof(vis));
        queue<pll> q; // {node, weight}
        q.push({v, INT_MAX});
        ll ans = -1;
        while (!q.empty()) {
            pll cur = q.front();
            q.pop();
            if (vis[cur.first]) continue;
            vis[cur.first] = true;
            if (cur.second >= k) {
                ans++;
            } else {
                continue;
            }
            for (edge i : adj[cur.first]) {
                if (!vis[i.to]) {
                    q.push({i.to, min(cur.second, i.w)});
                }
            }
        }
        cout << ans << endl;
    }
}