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
    while (b) {
        if (b&1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll di(ll a, ll b) {
    return mul(a, binpow(b, MOD2-2));
}

ll c2(ll n) {
    return di(mul(n, n-1), 2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    ll K = 1;
    ll L = binpow(K, (n/2)*((n+1)/2));
    ll hm = binpow(L,4);
    hm = sub(hm, mul(L, L-1));
    hm = sub(hm, L);
    hm = di(hm, 4);
    hm = mul(binpow(K, n%2), hm);
    hm = add(hm, c2(L));
    hm = add(hm, L);
    cout << hm << endl;
    return 0;
}