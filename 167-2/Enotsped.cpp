#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll dp[200005][13];
ll pre[200005][13];

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            dp[i][j] = 0;
            pre[i][j] = 0;
        }
    }
    for (int i = 1; i <= N-1; i++) {
        dp[i][1] = 1;
        for (int j = 2; j <= K; j++) {
            if (i>3) dp[i][j] = pre[i-3][j-1];
            dp[i][j] = add(dp[i][j], dp[i-1][j-1]);
        }
        if (i>3) dp[i][K] = add(dp[i][K], pre[i-3][K]);
        dp[i][K] = add(dp[i][K], dp[i-1][K]);
        for (int j = 1; j <= K; j++) {
            pre[i][j] = add(pre[i-1][j], dp[i][j]);
        }
    }
    for (int j = 1; j <= K; j++) {
        dp[N][j] = add(dp[N][j], pre[N-1][j-1]);
    }
    dp[N][K] = add(dp[N][K], pre[N-1][K]);
    cout << dp[N][K] << "\n";
    return 0;
}