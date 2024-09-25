#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, M;
vt<int> adj[100005];
ll sz[100005];
int dp[100005];
bool vis[100005];
int dep[100005];
ll ans;

void solve(int d, int u, int p) {
    vis[u] = 1;
    dep[u] = d;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!vis[v]) {
            solve(d+1, v, u);
            sz[u] += sz[v];
            dp[u] += dp[v];
        } else if (dep[v] < dep[u]) {
            dp[u]++;
            dp[v]--;
        }
    }
    if (dp[u] == 0) {
        ans = min(ans, sz[u]*(sz[u]-1)/2 + (N-sz[u])*(N-sz[u]-1)/2);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            dep[i] = 0;
            vis[i] = 0;
            sz[i] = 1;
            dp[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = N*(N-1)/2;
        solve(0, 1, -1);
        // cout << "sz: ";
        // for (int i = 1; i <= N; i++) cout << sz[i] << " ";
        // cout << "\n";
        // cout << "dp: ";
        // for (int i = 1; i <= N; i++) cout << dp[i] << " ";
        // cout << "\n";
        cout << ans << "\n";
    }
    return 0;
}