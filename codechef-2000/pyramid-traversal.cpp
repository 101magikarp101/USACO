#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T;
ll fac[100005];

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

pll solve(ll x) {
    ll tot = 0;
    for (ll a = 0; a <= 100000; a++) {
        tot += a;
        if (x <= tot+a+1) {
            ll b = x-tot;
            return {a+1, b};
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    for (ll i = 1; i <= 100000; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    cin >> T;
    while (T--) {
        ll s, e; cin >> s >> e;
        pll a = solve(s);
        pll b = solve(e);
        // cout << a.x << " " << a.y << " " << b.x << " " << b.y << endl;
        if (a.x == b.x && a.y == b.y) {
            cout << 1 << endl;
            continue;
        }
        if (b.x <= a.x) {
            cout << 0 << endl;
            continue;
        }
        if (b.y >= a.y && b.y <= b.x-(a.x-a.y)) {
            ll ans = di(fac[b.x-a.x], mul(fac[b.y-a.y], fac[b.x-a.x-(b.y-a.y)]));
            cout << ans << endl;
            continue;
        } else {
            cout << 0 << endl;
            continue;
        }
    }
    return 0;
}