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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define INT_MAX 2147483647

using namespace std;

ll T, N, K;
ll D;
ll a[2002];
ll v[100005];
ll dp[2002];

ll count() {
    ll cnt = 0;
    ll d = 0;
    for (ll i = 1; i <= N; i++) {
        d += dp[i];
        // cout << "a[i]: " << a[i] << " d: " << d << " i: " << i << endl;
        if (a[i] + d == i) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        cin >> N >> K >> D;
        for (ll i = 1; i <= N; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < K; i++) {
            cin >> v[i];
        }
        ll ans = count() + (D-1)/2;
        for (ll i = 0; i < 2*N; i++) {
            ll idx = i % K;
            dp[1]++;
            dp[v[idx] + 1]--;
            ll cnt = count();
            if (i+2 > D) {
                break;
            }
            ll res = cnt + (D-i-2)/2;
            // cout << "i: " << i << " cnt: " << cnt << " res: " << res << endl;
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
}