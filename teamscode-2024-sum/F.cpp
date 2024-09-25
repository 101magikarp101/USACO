#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        vt<vt<int>> a(N+1, vt<int>(M+1,0));
        vt<vt<int>> dp(N+1, vt<int>(M+1,INT_MAX));
        for (int i = 1; i <= N; i++) {
            string s; cin >> s;
            for (int j = 1; j <= M; j++) {
                a[i][j] = s[j-1]-'0';
            }
        }
        dp[1][1] = a[1][1]==0?1:0;
        for (int i = 1; i<= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (i==1&&j==1) continue;
                if (a[i][j]==0) {
                    dp[i][j] = min((j>1&&a[i][j-1]==0)?dp[i][j-1]:INT_MAX, (i>1&&dp[i-1][j]!=INT_MAX)?dp[i-1][j]+1:INT_MAX);
                } else {
                    dp[i][j] = min((j>1&&a[i][j-1]==1)?dp[i][j-1]:INT_MAX, (i>1&&dp[i-1][j]!=INT_MAX)?dp[i-1][j]:INT_MAX);
                }
            }
        }
        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= M; j++) {
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        cout << (dp[N][M]==INT_MAX?-1:dp[N][M]) << '\n';
    }
    return 0;
}