#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000009
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

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

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll ma = 115381398;
    ll m2 = 276147934;
    //884618610
    // cout << binpow(ma, 2) << endl;f

    cin >> T;
    unordered_set<ll> s;
    for (ll i = 17; i <= 17*26; i++) {
        for (ll j = 17; j <= 17*26; j++) {
            for (ll k = 17; k <= 17*26; k++) {
                ll res = i+ma*j+884618610*k;
                res %= MOD2;
                s.insert(res);
            }
        }
    }
    while (T--) {
        ll n; cin >> n;
        if (s.count(n)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}