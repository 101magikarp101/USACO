#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll nck[5005][5005];

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
    nck[0][0] = 1;
    for (int i = 1; i <= 5000; i++) {
        nck[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            nck[i][j] = add(nck[i-1][j], nck[i-1][j-1]);
        }
    }
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = 0;
        for (ll i = 0; i <= N; i++) {
            for (ll j = i+1; j <= 2*i+1; j++) {
                ll l = min(j-1, N);
                ll r = max(0LL, N-j);
                ll res = mul(nck[l][j-i-1], nck[r][i-(j-i-1)]);
                // cout << "l: " << l << " r: " << r << endl;
                // cout << "i: " << i << " j: " << j << " res: " << res << "\n";
                res = mul(res, j);
                ans = add(ans, res);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}