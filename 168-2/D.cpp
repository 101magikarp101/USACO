#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
ll a[200005];
vt<int> adj[200005];

void solve(int u) {
    if (adj[u].empty()) return;
    ll m = 1e18;
    for (int v: adj[u]) {
        solve(v);
        m = min(m, a[v]);
    }
    if (u == 1) {
        a[u] += m;
        return;
    }
    if (a[u] > m) {
        a[u] = m;
        return;
    }
    ll d = (m - a[u])/2;
    a[u] += d;
    m -= d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            adj[i].clear();
        }
        for (int i = 2; i <= N; i++) {
            int x; cin >> x;
            adj[x].push_back(i);
        }
        solve(1);
        // cout << "a: ";
        // for (int i = 1; i <= N; i++) cout << a[i] << " ";
        // cout << "\n";
        cout << a[1] << "\n";
    }
    return 0;
}