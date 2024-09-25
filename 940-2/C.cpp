#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll K;
ll fac[300005];
ll ifac[300005];

ll add(ll a, ll b) {
    return (a+b)%MOD2;
}

ll sub(ll a, ll b) {
    return (a-b+MOD2)%MOD2;
}

ll mul(ll a, ll b) {
    return (a*b)%MOD2;
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

ll nck(ll n, ll k) {
    return mul(fac[n], mul(ifac[k], ifac[n-k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for (ll i = 1; i <= 300000; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    ifac[300000] = inv(fac[300000]);
    for (ll i = 300000-1; i >= 0; i--) {
        ifac[i] = mul(ifac[i+1], i+1);
    }
    vt<ll> dp(300005,0);
    dp[0] = 1;
    dp[1] = 0;
    for (ll i = 2; i <= 300000; i++) {
        dp[i] = mul(dp[i-2], (i-1)*2);
    }
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (ll i = 0; i < K; i++) {
            ll x, y;
            cin >> x >> y;
            if (x==y) {
                N--;
            } else {
                N-=2;
            }
        }
        ll ans = 0;
        for (ll i = 0; i <= N; i++) {
            // cout << "i: " << i << " res: " << mul(dp[N-i], nck(N,i)) << "\n";
            ans = add(ans, mul(dp[N-i], nck(N,i)));
        }
        cout << ans << "\n";
    }
    return 0;
}