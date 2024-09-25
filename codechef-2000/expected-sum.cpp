#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int a[200005];

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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll f = 1;
    for (ll i = 1; i <= 1e9; i++) {
        f = mul(f, i);
    }
    cout << f << endl;
    return 0;
}