#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
#define pb push_back
#define pf push_front
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define uset unordered_set
#define umap unordered_map
#define mset multiset
struct pii {
    int x, y;
    bool operator<(const pii &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pii &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pii &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pii &a) const { return x != a.x || y != a.y; }
    pii operator+(const pii &a) const { return {x+a.x, y+a.y}; }
    pii operator-(const pii &a) const { return {x-a.x, y-a.y}; }
    pii operator*(const int &a) const { return {x*a, y*a}; }
    pii operator/(const int &a) const { return {x/a, y/a}; }
};
struct pll {
    ll x, y;
    bool operator<(const pll &a) const { return x == a.x ? y < a.y : x < a.x; }
    bool operator>(const pll &a) const { return x == a.x ? y > a.y : x > a.x; }
    bool operator==(const pll &a) const { return x == a.x && y == a.y; }
    bool operator!=(const pll &a) const { return x != a.x || y != a.y; }
    pll operator+(const pll &a) const { return {x+a.x, y+a.y}; }
    pll operator-(const pll &a) const { return {x-a.x, y-a.y}; }
    pll operator*(const ll &a) const { return {x*a, y*a}; }
    pll operator/(const ll &a) const { return {x/a, y/a}; }
};

ll T, N, C;
ll dp[200005][2];
ll a[200005];
vt<int> adj[200005];

void solve(int u, int p) {
    ll ans0 = 0, ans1 = a[u];
    for (int v : adj[u]) {
        if (v == p) continue;
        solve(v, u);
        ans0 += max(dp[v][0], dp[v][1]);
        ans1 += max(dp[v][0], dp[v][1]-2*C);
    }
    dp[u][0] = ans0;
    dp[u][1] = ans1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> C;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            dp[i][0] = dp[i][1] = -1e18;
        }
        for (int i = 0; i < N; i++) {
            adj[i].clear();
        }
        for (int i = 0; i < N-1; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        solve(0, -1);
        // cout << "dp: " << endl;
        // for (int i = 0; i < N; i++) {
        //     cout << dp[i][0] << " " << dp[i][1] << endl;
        // }
        cout << max({dp[0][0], dp[0][1], 0LL}) << endl;
    }
    return 0;
}