#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll a[505][505];

ll solve(vt<ll> &v) {
    ll ans = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        ll res = 0;
        for (int j = 0; j < N; j++) {
            res += v[j]*abs(j-i);
        }
        ans = min(ans, res);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    vt<ll> r(N), c(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    ll ans = solve(r) + solve(c);
    cout << ans << endl;
    return 0;
}