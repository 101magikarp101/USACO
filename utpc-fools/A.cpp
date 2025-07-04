#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
int a[10];
vt<int> adj[10];
int ans = -1;
bool vis[10];

void dfs(int u, int res) {
    if (u != 0) {
        res ^= a[u];
        ans = max(ans, res);
    }
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, res);
        }
    }
    vis[u] = 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        adj[0].push_back(i);
        adj[i].push_back(0);
    }
    dfs(0, 0);
    cout << ans << '\n';
    return 0;
}