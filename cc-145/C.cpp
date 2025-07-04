#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll dp[500005];

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
    cin >> T;
    N = 500000;
    dp[1] = 0;
    ll hm = 0;
    ll pre = 0;
    for (ll i = 2; i <= N; i++) {
        hm = add(2*hm, (i-1)*(i)*(2*i-1)/3);
        dp[i] = add(pre, hm);
        pre = add(pre, dp[i]);
    }
    while (T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }
    return 0;
}