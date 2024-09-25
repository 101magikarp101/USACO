#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, K;
int a[2005];
int dp[2005][2005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
            a[i] = max(-1, i-a[i]);
        }
        int ans = 1e9;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= N; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+(a[i]==j));
                dp[i][j+1] = max(dp[i][j+1], dp[i-1][j]);
            }
        }
        for (int i = 0; i <= N; i++) {
            if (dp[N][i] >= K) {
                ans = i;
                break;
            }
        }
        cout << (ans == 1e9 ? -1 : ans) << endl;
    }
    return 0;
}