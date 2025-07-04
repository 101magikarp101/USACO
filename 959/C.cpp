#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, X;
ll a[200005];
ll dp[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> X;
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            dp[i] = 0;
        }
        ll l = 1, r = 1;
        ll sum = a[1];
        while (r <= N) {
            if (sum-a[r] <= X && sum > X) {
                dp[r] += dp[l-1]+1;
            }
            while (l < r && sum-a[l]>X) {
                sum -= a[l];
                l++;
                if (sum-a[r] <= X && sum > X) {
                    dp[r] += dp[l-1]+1;
                }
            }
            r++;
            if (r <= N) {
                sum += a[r];
            } else {
                break;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            ans += dp[i];
        }
        // cout << "dp: ";
        // for (int i = 1; i <= N; i++) {
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        ans = N*(N+1)/2-ans;
        cout << ans << endl;
    }
    return 0;
}