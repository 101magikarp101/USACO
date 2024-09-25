#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N;
int pre[200005];

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
        string s; cin >> s;
        N = s.size();
        for (int i = 0; i <= N; i++) {
            pre[i] = 0;
        }
        for (int i = 1; i <= N; i++) {
            pre[i] = pre[i-1] + (s[i-1] == '1'?1:-1);
        }
        ll ans = 0;
        map<ll, ll> m;
        m[0] = 1;
        for (ll i = 1; i <= N; i++) {
            if (m.find(pre[i]) != m.end()) {
                ll x = m[pre[i]];
                // cout << "i: " << i << " x: " << x << endl;
                ans = add(ans, mul(x, N-i+1));
            }
            m[pre[i]]+=i+1;
        }
        cout << ans << endl;
    }
    return 0;
}