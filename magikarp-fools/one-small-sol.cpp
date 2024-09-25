#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N, K;
ll dp[300005][2];
ll pre[300005][2];

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
    cin >> N >> K;
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = sub(i>=2?pre[i-2][0]:0,i>K?pre[i-K-1][0]:0);
        pre[i][0] = add(pre[i-1][0], dp[i][0]);
        pre[i][1] = add(pre[i-1][1], dp[i][1]);
    }
    // cout << "dp: " << endl;
    // for (int i = 0; i <= N; i++) {
    //     cout << dp[i][0] << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i <= N; i++) {
    //     cout << dp[i][1] << " ";
    // }
    // cout << "\n";
    cout << add(dp[N][0], dp[N][1]) << "\n";
    return 0;
}