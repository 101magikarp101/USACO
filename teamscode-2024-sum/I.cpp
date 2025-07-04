#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll dp[1000005][2];

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
        if (b%2) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll di(ll a, ll b) {
    return mul(a, inv(b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (ll i = 2; i <= 1000000; i++) {
        dp[i][1] = add(di(dp[i-1][1], i-1), mul(di(i-2, i-1), dp[i-1][0]+1));
        dp[i][0] = add(di(dp[i-1][1], i-1), mul(di(i-2, i-1), dp[i-1][0]));
    }
    cin >> T;
    while (T--) {
        cin >> N;
        ll res = add(di(dp[N][1], N), mul(di(N-1,N), dp[N][0]));
        cout << res << '\n';
    }
    return 0;
}