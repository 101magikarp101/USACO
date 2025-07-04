#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];
vt<int> adj[200005];
int s = -1;

void solve(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        solve(v, u);
    }
    if (u!=s) cout << u << " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        int mi = 1e9+10;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            if (a[i] < mi) {
                mi = a[i];
                s = i;
            }
        }
        for (int i = 1; i <= N-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << N-1 << endl;
        solve(s, -1);
        cout << endl;
    }
    return 0;
}