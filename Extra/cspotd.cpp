#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll a[200005];
vt<int> adj[200005];
ll ans0 = 0, ans1 = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1 ; i <= N; i++) {
        vt<ll> vec;
        ll sq = 0, s = 0;
        for (int v : adj[i]) {
            vec.push_back(a[v]);
            sq += a[v] * a[v];
            s += a[v];
        }
        sort(vec.begin(), vec.end(), greater<ll>());
        ans1 += (s*s-sq)/2;
        if (vec.size() >= 2) ans0 = max(ans0, vec[0]*vec[1]);
    }
    cout << ans0 << " " << ans1 << endl;
    return 0;
}