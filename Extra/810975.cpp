#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <bitset>
#include <string>

#define ll long long
#define pll pair<ll, ll>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353

using namespace std;

ll binexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll a) {
    return binexp(a, MOD-2);
}

ll di(ll a, ll b) {
    return (a*inv(b))%MOD;
}

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

ll choose(ll n, ll k) {
    ll ans = 1;
    for (ll i = n; i > n-k; i--) {
        ans = (ans*i)%MOD;
    }
    for (ll i = 1; i <= k; i++) {
        ans = di(ans, i);
    }
    return ans;
}

ll mult(ll a, ll b) {
    return (a*b)%MOD;
}

ll sub(ll a, ll b) {
    return (a-b+MOD)%MOD;
}

ll fac(ll a, ll b) {
    ll ans = 1;
    for (ll i = a; i > b; i--) {
        ans = (ans*i)%MOD;
    }
    return ans;

}

// ll solve(ll n, ll m, ll k) {
//     cout << "solve " << n << " " << m << " " << k << endl;
//     if (m*k < n) return 0;
//     ll ans = 0;
//     for (ll i = 0; i < m; i++) {
//         if (m-1-i > n+m-i*k-(2*i+1)) break;
//         ll res1 = choose(m, i);
//         ll res2 = choose(n+m-i*k-(i+1), m-1);
//         cout << res1 << " " << res2 << endl;
//         if (i%2 == 0) ans = add(ans, mult(res1, res2));
//         else ans = sub(ans, mult(res1, res2));
//     }
//     return ans;
// }

ll solve1(ll n, ll m, ll k) {
    // cout << "solve " << n << " " << m << " " << k << endl;
    if (m*k < n) return 0;
    ll cur1 = 1;
    ll cur2 = choose(n+m-1, m-1);
    ll ans = mult(cur1, cur2);
    for (ll i = 1; i < m; i++) {
        if (m-1 > n+m-i*k-i-1) break;
        cur1 = mult(cur1, m-i+1);
        cur1 = di(cur1, i);
        // cout << n+m-i*k-i << " " << n+m-(i-1)*k-i+1 << endl;
        // cout << n-i*k-i << " " << n-(i-1)*k-i+1 << endl;
        cur2 = mult(cur2, fac(n-(i-1)*k-i+1, n-i*k-i));
        cur2 = di(cur2, fac(n+m-(i-1)*k-i, n+m-i*k-i-1));
        // cout << cur1 << " " << cur2 << endl;
        if (i%2 == 0) ans = add(ans, mult(cur1, cur2));
        else ans = sub(ans, mult(cur1, cur2));
    }
    return ans;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    if (k <= m && m <= n) {
        ll x = n-m+1; //number of numbers
        ll y = n+1-x; // target sum
        ll ans1 = solve1(y, x, k);
        ll ans2 = solve1(y, x, k-1);
        cout << sub(ans1, ans2) << endl;
    } else {
        cout << 0 << endl;
    }
}