#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, K;
ll a[500005];
ll sz = 0;

bool check (ll m) {
    if (K <= 1000) {
        vt<vt<int>> res(K, vt<int>(sz+1, INT_MIN));
        vt<vt<int>> dp(N+1, vt<int>(sz+1, INT_MIN));
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            int hm = (a[i]>=m?1:-1);
            int mod = (i-1)%K;
            for (int j = 0; j < sz; j++) {
                dp[i][j+1] = max(dp[i][j+1], res[mod][j]+hm);
            }
            for (int j = 0; j <= sz; j++) {
                res[i%K][j] = max(res[i%K][j], dp[i][j]);
            }
        }
        for (int i = 1; i <= N; i++) {
            if ((N-i)%K == 0 && dp[i][sz] >= 1) {
                return 1;
            }
        }
        return 0;
    } else {
        int gaps = (N-sz)/K;
        vt<vt<int>> dp(N+1, vt<int>(gaps+1, INT_MIN));
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            int hm = (a[i]>=m?1:-1);
            for (int j = i-1; j >= 0; j-=K) {
                for (int k = 0; k+(i-j)/K <= gaps; k++) {
                    dp[i][k+(i-j)/K] = max(dp[i][k+(i-j)/K], dp[j][k]+hm);
                }
            }
        }
        for (int i = 1; i <= N; i++) {
            if ((N-i)%K == 0 && dp[i][gaps] >= 1) {
                return 1;
            }
        }
        return 0;
    }
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
        if (K >= N) {
            sort(a+1, a+N+1);
            int m = (N+1)/2;
            cout << a[m] << '\n';
            continue;
        }
        sz = N%K;
        if (sz == 0) {
            sz = K;
        }
        ll l = 1, r = 1e9;
        while (l < r) {
            ll m = (l+r+1)/2;
            if (check(m)) {
                l = m;
            } else {
                r = m-1;
            }
        }
        cout << l << '\n';
    }
    return 0;
}