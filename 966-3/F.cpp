#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll dp[1005][105];
pll a[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= K; j++) {
                dp[i][j] = 1e9;
            }
        }
        for (int i = 1; i <= N; i++) {
            cin >> a[i].x >> a[i].y;
            if (a[i].x>a[i].y) {
                swap(a[i].x, a[i].y);
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            ll x = a[i].x, y = a[i].y;
            vt<ll> b(x+y+1,1e9);
            b[0] = 0;
            for (int j = 0; j <= x; j++) {
                for (int k = 0; k <= y; k++) {
                    b[j+k] = min(b[j+k], j*y+k*x-j*k);
                }
            }
            for (int j = 0; j <= K; j++) {
                for (int k = 0; k <= x+y; k++) {
                    if (j+k<=K) {
                        dp[i][j+k] = min(dp[i][j+k], dp[i-1][j]+b[k]);
                    }
                }
            }
        }
        // cout << "dp:" << endl;
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 0; j <= K; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        ll ans = 1e9;
        for (int i = 1; i <= N; i++) {
            ans = min(ans, dp[i][K]);
        }
        cout << (ans==1e9 ? -1 : ans) << endl;
    }
    return 0;
}