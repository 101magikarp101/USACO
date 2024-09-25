#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll N;
ll a[21];
vt<int> adj[21];
vt<ll> r;

void dfs(int u, int p) {
    int cnt = 0;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        cnt++;
    }
    if (cnt == 0) {
        r.push_back(a[u]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    int n = r.size();
    vt<ll> res(n+1, 0);
    for (ll m = 1; m < (1<<n); m++) {
        ll prod = 1;
        for (int i = 0; i < n; i++) {
            if (m & (1<<i)) {
                prod *= r[i];
            }
        }
        res[__builtin_popcount(m)] += prod;
    }
    if (n==1) {
        cout << "x";
    } else {
        cout << "x^" << n;
    }
    for (int i = 1; i <= n; i++) {
        if (i%2==1) {
            res[i] = -res[i];
        }
        if (res[i] == 0) continue;
        if (res[i] == 1) {
            if (i == n) {
                printf("+1");
            } else if (i == n-1) {
                printf("+x");
            } else {
                printf("+x^%d", n-i);
            }
            continue;
        }
        if (res[i] == -1) {
            if (i == n) {
                printf("-1");
            } else if (i == n-1) {
                printf("-x");
            } else {
                printf("-x^%d", n-i);
            }
            continue;
        }
        if (i == n) {
            printf("%+lld", res[i]);
        } else if (i == n-1) {
            printf("%+lldx", res[i]);
        } else {
            printf("%+lldx^%d", res[i], n-i);
        }
    }
    return 0;
}