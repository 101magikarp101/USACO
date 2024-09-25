#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll fac[200005];

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

ll nck(ll n, ll k) {
    if (k > n) return 0;
    if (k < 0) return 0;
    return di(fac[n], mul(fac[k], fac[n-k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for (ll i = 1; i <= 200000; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
        }
        if (N==1) {
            cout << 1 << endl;
            continue;
        }
        ll ans = 0;
        for (ll i = 1; i <= N; i++) {
            ans = add(ans, fac[N]);
            ans = add(ans, mul(di(fac[N], N-i+1),i));
            ans = sub(ans, mul(i, mul(fac[N-i],fac[i-1])));
        }
        cout << ans << "\n";
    }
    return 0;
}