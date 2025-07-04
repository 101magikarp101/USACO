#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

const int MX = 56*1000;

ll T, N, X, M;
ll fib[24];
ll dp[1005][MX];

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

int bits(int x) {
    int cnt = 0;
    for (int i = 23; i >= 0; i--) {
        if (x >= fib[i]) {
            x -= fib[i];
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 24; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cin >> N >> X >> M;
    dp[0][0] = 1;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < MX; k++) {
                dp[j+1][k+fib[i]] = add(dp[j+1][k+fib[i]], dp[j][k]);
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < MX; i++) {
        if (bits(i) == M) {
            ans = add(ans, dp[N][i]);
        }
    }
    cout << ans << "\n";
    return 0;
}