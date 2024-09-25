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

ll N, K;
ll dp[101][101][101][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // auto start = chrono::high_resolution_clock::now();
    cin >> N >> K;
    N--;
    K--;
    dp[0][0][1][0] = 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 1; k+i <= N; k++) {
                for (int l = 1; l <= N; l++) {
                    if (dp[i][j][l][0]==0&&dp[i][j][l][1]==0) continue;
                    ll res = mul(binpow(sub(binpow(2,l),1),k), binpow(2,k*(k-1)/2));
                    dp[i+k][j][k][1]=add(dp[i+k][j][k][1], mul(dp[i][j][l][0], res));
                    dp[i+k][j+k][k][0]=add(dp[i+k][j+k][k][0], mul(dp[i][j][l][1], res));
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = add(ans, add(dp[N][K][i][0], dp[N][K][i][1]));
    }
    cout << ans << "\n";
    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);
    // cout << "Time: " << duration.count() << "ms\n";
    return 0;
}