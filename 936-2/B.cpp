#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll a[200005];

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
    cin >> T;
    while (T--) {
        cin >> N >> K;
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            sum += a[i];
        }
        ll ma = 0;
        ll cur = 0;
        set<ll> s;
        s.insert(0);
        for (int i = 0; i < N; i++) {
            cur+=a[i];
            ll mi = *s.begin();
            ma = max(ma, cur-mi);
            s.insert(cur);
        }
        sum = (sum%MOD2+MOD2)%MOD2;
        ma %= MOD2;
        // cout << "sum: " << sum << " ma: " << ma << '\n';
        ll ans = add(sum, mul(ma, sub(binpow(2, K), 1)));
        cout << ans << '\n';
    }
    return 0;
}