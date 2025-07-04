#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

ll T, N, M, L, F;
bool dp[51][51];

ll gcd(ll a, ll b) {
    return b==0?a:gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M >> L >> F;
        ll n = max(0LL,N-50), m = max(0LL,M-50);
        ll ans = 0;
        for (int i = n; i <= N; i++) {
            for (int j = m; j <= M; j++) {
                if (i==n||j==m) dp[i-n][j-m] = 1;
                else if (gcd(i, j)==1) dp[i-n][j-m] = (dp[i-1-n][j-m]|dp[i-n][j-1-m]);
                else dp[i-n][j-m] = 0;
                if (dp[i-n][j-m]) {
                    ans = max(ans, i*L+j*F);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}