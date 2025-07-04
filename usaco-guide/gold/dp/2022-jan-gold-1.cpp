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
#include <unordered_map>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

ll N;
ll h[103];
ll dp[103][1003];
ll pre[103][1003];

ll solve() {
    for (int i = 0; i <= h[1]; i++) {
        dp[1][i] = 1;
        if (i == 0) {
            pre[1][i] = 1;
        } else {
            pre[1][i] = pre[1][i-1] + dp[1][i];
        }
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= h[i]; j++) {
            int r = min(h[i]-j, h[i-1]);
            if (r < 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = pre[i-1][r];
                if (i == 0) {
                    pre[i][j] = dp[i][j];
                } else {
                    pre[i][j] = pre[i][j-1] + dp[i][j];
                    pre[i][j] %= MOD2;
                }
            }
        }
    }
    return pre[N][0];
}

int main () {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    if (N%2 == 0) {
        memset(dp, 0, sizeof(dp));
        memset(pre, 0, sizeof(pre));
        cout << solve() << endl;
    } else {
        ll ans = 0;
        while (true) {
            memset(dp, 0, sizeof(dp));
            memset(pre, 0, sizeof(pre));
            ans += solve();
            ans %= MOD2;
            for (int i = 1; i <= N; i++) {
                h[i]--;
                if (h[i] < 0) {
                    cout << ans << endl;
                    return 0;
                }
            }
        }
    }
}