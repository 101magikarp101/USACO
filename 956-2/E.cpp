#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll a[400005];

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
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        ll S = 0;
        ll sum = 0;
        for (int i = 1; i <= K; i++) {
            sum = add(sum, a[i]);
        }
        if (N==K) {
            cout << sum << " " << 0 << "\n";
            continue;
        }
        ll A = di(sum, K);
        S += sum;
        sum = 0;
        for (int i = K+1; i <= N; i++) {
            sum = add(sum, a[i]);
        }
        ll M = N-K;
        ll B = di(sum, M);
        ll res1 = 0, res2 = mul(B, (M+1)/2);
        if (M%2 == 0) {
            res1 = mul(A, mul(K, di(M/2+1,M+1)));
        } else {
            res1 = mul(A, di(K,2));
        }
        S += sum;
        ll ans = add(res1, res2);
        cout << ans << " " << sub(S, ans) << "\n";
    }
    return 0;
}