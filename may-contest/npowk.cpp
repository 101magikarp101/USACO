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

int T, N;
//We would never actually need N up to 1e18.
ll nck[5005][5005];
ll dp[5005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    nck[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        nck[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            nck[i][j] = add(nck[i-1][j], nck[i-1][j-1]);
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i]=1;
        for (int j = 0; j < i; j++) {
            dp[i] = add(dp[i], mul(dp[j], nck[i][j]));
        }
    }
    cout << dp[N] << endl;
    return 0;
}