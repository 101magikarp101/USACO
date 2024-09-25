#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll fac[1000005];
ll ifac[1000005];

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
    return mul(fac[n], mul(ifac[k], ifac[n-k]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for (ll i = 1; i <= 1000000; i++) {
        fac[i] = fac[i-1]*i;
    }
    ifac[1000000] = inv(fac[1000000]);
    for (ll i = 999999; i >= 0; i--) {
        ifac[i] = mul(ifac[i+1], i+1);
    }
    for (int j = 1; j <= 15; j++) {
        cout << j << ": ";
        for (int i = j; i <= 15; i++) {
            cout << (fac[i]/fac[i-j]/j)%j << " ";
        }
        cout << "\n";
    }
    cin >> T;
    while (T--) {
        cin >> N;
    }
    return 0;
}