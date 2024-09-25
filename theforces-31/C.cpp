#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
vt<int> adj[100005];
ll res[2];

void dfs1(int u, int p, int d) {
    res[d%2]++;
    for (int v : adj[u]) {
        if (v==p) continue;
        dfs1(v, u, d+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        res[0] = 0;
        res[1] = 0;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < N-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(1, 0, 1);
        ll ans = res[0]*(res[0]-1)/2 + res[1]*(res[1]-1)/2;
        cout << ans << endl;
    }
    return 0;
}