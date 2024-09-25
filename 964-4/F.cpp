#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll fac[200005];
ll ifac[200005];

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

ll nck(ll n, ll k) {
    if (k > n) return 0;
    return mul(fac[n], mul(ifac[k], ifac[n-k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for (int i = 1; i < 200005; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    ifac[200004] = inv(fac[200004]);
    for (int i = 200003; i >= 0; i--) {
        ifac[i] = mul(ifac[i+1], i+1);
    }
    cin >> T;
    while (T--) {
        cin >> N >> K;
        ll z = 0, o = 0;
        for (int i = 0; i < N; i++) {
            ll x; cin >> x;
            if (x==0) z++;
            else o++;
        }
        ll ans = 0;
        for (int i = (K+1)/2; i <= K; i++) {
            if (i > o) break;
            if (K-i > z) continue;
            ans = add(ans, mul(nck(o, i), nck(z, K-i)));
        }
        cout << ans << endl;
    }
    return 0;
}