#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int N;
pll a[2005];
ll dp[2005];
vt<ll> dpp[2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    ll tot = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < 2005; i++) {
        dp[i] = 1e18;
    }
    dp[0] = 0;
    dpp[0] = {};
    for (int i = 0; i < N; i++) {
        for (int j = N; j >= 0; j--) {
            if (j+a[i].x <= N) {
                if (dp[j]+a[i].y < dp[j+a[i].x]) {
                    dp[j+a[i].x] = dp[j]+a[i].y;
                    dpp[j+a[i].x] = dpp[j];
                    dpp[j+a[i].x].push_back(i);
                }
            }
        }
    }
    ll ans = 1e18;
    for (int i = 0; i <= N; i++) {
        
    }
    cout << ans << "\n";
    return 0;
}