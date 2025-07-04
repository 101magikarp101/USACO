#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[300005];
ll c[300005][21];
vt<int> adj[300005];
int what = 20;

void bfs(int u, int p) {
    for (int v : adj[u]) {
        if (v==p) continue;
        bfs(v, u);
    }
    for (ll d = 1; d <= what; d++) {
        c[u][d] = a[u]*d;
        for (int v : adj[u]) {
            if (v==p) continue;
            ll mi = LLONG_MAX;
            for (int i = 1; i <= what; i++) {
                if (i==d) continue;
                mi = min(mi, c[v][i]);
            }
            c[u][d] += mi;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            adj[i].clear();
        }
        for (int i = 1; i < N; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bfs(1, -1);
        // cout << "c: " << endl;
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= 3; j++) {
        //         cout << c[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        ll ans = LLONG_MAX;
        for (int i = 1; i <= what; i++) {
            ans = min(ans, c[1][i]);
        }
        cout << ans << endl;
    }
    // auto end = chrono::high_resolution_clock::now();
    // cerr << "Time: " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;

    return 0;
}