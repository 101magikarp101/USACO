#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        sort(a, a+N);
        vt<int> dp(N+1, 0);
        for (int i = 0; i < N-1; i++) {
            ll x = (a[N-1]-a[i]-K+2*K-1)/(2*K);
            ll l = a[i]+2*x*K-a[N-1];
            ll r = l+K;
            // cout << "l: " << l << " r: " << r << '\n';
            dp[max(0LL, l)]++;
            dp[min(N, r)]--;
        }
        for (int i = 1; i <= N; i++) {
            dp[i] += dp[i-1];
        }
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (dp[i]==N-1) {
                ans = a[N-1]+i;
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}