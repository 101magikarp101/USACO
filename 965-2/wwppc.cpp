#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll N = 101;
ll X = 101;
ll p[40001];
ll dp[50005];

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
    auto start = chrono::high_resolution_clock::now();
    ll num = 1, den = 1;
    for (ll i = 1; i <= X; i++) {
        num = mul(num, X-i+1);
        den = mul(den, X);
        p[i] = di(num, den);
    }
    dp[0] = 1;
    for (ll i = 1; i <= N; i++) {
        for (ll j = X-i; j >= 0; j--) {
            dp[j+i] = add(dp[j+i], dp[j]);
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= min(N, X); i++) {
        ans = add(ans, mul(p[i], dp[i]));
    }
    ans = di(ans, binpow(2, N));
    cout << ans << endl;
    auto end = chrono::high_resolution_clock::now();
    cerr << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;
    return 0;
}