#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll hm = 0;
ll cur = 1;

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

ll T, N;

ll nck(ll n) {
    ll x, y;
    for (ll i = hm+1; i <= n/2; i++) {
        cur = mul(cur, i);
    }
    x = cur;
    hm = n/2;
    for (ll i = hm+1; i <= n; i++) {
        cur = mul(cur, i);
    }
    y = cur;
    hm = n;
    // cout << "n: " << n << " x: " << x << " y: " << y << endl;
    return di(y, mul(x, x));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    N++;
    if (N>=30) {
        cout << 0 << endl;
        return 0;
    }
    ll dp[N+1];
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i]=mul(nck((1<<i)-2), mul(dp[i-1], dp[i-1]));
    }
    cout << dp[N] << endl;
    return 0;
}