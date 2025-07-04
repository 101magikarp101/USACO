#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

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
    ll n, k; cin >> n >> k;
    ll ans2 = 0;
    ll hm = 1;
    for (ll i = 1; i < k; i++) {
        hm = mul(hm, di(k-i+1,i));
        if (i%2==1) {
            ans2 = add(ans2, mul(hm,sub(binpow(k-i+1,n),1)));
        } else {
            ans2 = sub(ans2, mul(hm,sub(binpow(k-i+1,n),1)));
        }
    }
    ans2 = sub(binpow(k+1,n),ans2+1);
    cout << ans2 << '\n';
    return 0;
}