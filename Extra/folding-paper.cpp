#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int N;
vt<ll> fac;

ll mul(ll a, ll b) {
    return a*b%MOD2;
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

ll nck(ll n, ll k) {
    ll hm = inv(fac[k]);
    return mul(fac[n], mul(hm, hm));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto start = chrono::high_resolution_clock::now();
    cin >> N;
    fac.resize((1LL<<N)-1);
    fac[0] = 1;
    for (int i = 1; i < (1LL<<N)-1; i++) {
        fac[i] = mul(fac[i-1], i);
    }
    vt<ll> dp(N+1);
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = mul(nck((1LL<<i)-2, (1LL<<(i-1))-1), mul(dp[i-1], dp[i-1]));
    }
    cout << dp[N] << endl;
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end-start).count() << endl;
    return 0;
}