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

ll fac(ll n) {
    ll res = 1;
    for (ll i = 1; i <= n; i++) {
        res = mul(res, i);
    }
    return res;
}

ll N;

int main() {
    // freopen("input.txt", "w", stdout);
    // random_device rd;
    // mt19937 gen(rd());
    // uniform_int_distribution<ll> n(1, 1e12);
    // int nn = 1000;
    // cout << nn << endl;
    // for (int i = 0; i < nn*(nn+1)/2; i++) {
    //     cout << n(gen) << ' ';
    // }
    // cout << endl;
    // fclose(stdout);
    // freopen("output.txt", "w", stdout);
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ll sum = 0;
    for (int i = 0; i < N*(N+1)/2; i++) {
        ll x; cin >> x;
        sum = add(sum, x);
    }
    ll ans = mul(sum, mul(di(mul(N, mul(N+1, N+2)), 6), fac(N*(N+1)/2-1)));
    cout << ans << '\n';
    return 0;
}