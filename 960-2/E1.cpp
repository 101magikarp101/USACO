#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
vt<int> adj[5005];
int d[5005];
int p[5005];
int leaf = -1;
int maxd = -1;

void dfs(int u, int par, int dep) {
    p[u] = par;
    d[u] = dep;
    for (int v : adj[u]) {
        if (v == par) continue;
        dfs(v, u, dep+1);
    }
    if (adj[u].size() == 1 && u != 1) {
        leaf = u;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0, 0);
        for (int i = 0; i < 150; i++) {
            cout << "? " << leaf << endl;
            int x; cin >> x;
            if (x==1) {
                cout << "! " << leaf << endl;
                return 0;
            }
        }
        
    }
    return 0;
}