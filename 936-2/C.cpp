#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
vt<int> adj[100005];
int sz[100005];
int a[100005];
bool vis[100005];

void calc(int n) {
    sz[n] = 1;
    vis[n] = 1;
    for (int i : adj[n]) {
        if (vis[i]) continue;
        calc(i);
        sz[n] += sz[i];
    }
}

void reset() {
    for (int i = 1; i <= N; i++) {
        a[i] = sz[i];
        vis[i] = 0;
    }
}

int check(int n, int x) {
    int ans = 0;
    vis[n] = 1;
    for (int i : adj[n]) {
        if (vis[i]) continue;
        ans += check(i, x);
        a[n] += a[i]-sz[i];
    }
    if (a[n]>=x) {
        a[n] = 0;
        return ans+1;
    } else {
        return ans;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            vis[i] = 0;
        }
        for (int i = 0; i < N-1; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            // cout << "u: " << u << " v: " << v << '\n';
        }
        calc(1);
        // cout << "sz: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << sz[i] << ' ';
        // }
        // cout << '\n';
        int l = 1, r = N;
        while (l < r) {
            int m = (l+r+1)/2;
            reset();
            int res = check(1, m);
            if (res-1>=K) l = m;
            else r = m-1;
        }
        cout << l << '\n';
    }
    return 0;
}