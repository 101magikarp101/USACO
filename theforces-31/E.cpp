#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N;
ll a[500005];
ll dp[500005];
ll pre[500005];
ll prex[500005];

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
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            dp[i] = 0;
            pre[i] = 0;
            prex[i] = 0;
        }
        dp[1] = a[1];
        pre[1] = a[1];
        prex[1] = a[1];
        for (int i = 2; i <= N; i++) {
            dp[i] = add(pre[i-1], prex[i]);
            pre[i] = add(pre[i-1], dp[i]);
        }
        cout << "prex: ";
        for (int i = 1; i <= N; i++) {
            cout << prex[i] << " ";
        }
        cout << endl;
        cout << "pre: ";
        for (int i = 1; i <= N; i++) {
            cout << pre[i] << " ";
        }
        cout << endl;
        cout << dp[N] << endl;
    }
    return 0;
}