#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
#define endl '\n'
struct pii {int x, y;};
struct pll {ll x, y;};

int T, N, M;
int dp[205][205][205];// i, pre, suf

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        string s, t; cin >> s >> t;
        N = s.size(), M = t.size();
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        vt<vt<int>> a(26,vt<int>(M,0)), b(26,vt<int>(M,0));
        int aa = 0, bb = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 1; j < M; j++) {
                int sz = M-j+1;
                if (t.substr(0,sz)==t.substr(j)+(char)(i+'a')) {
                    aa = sz-1;
                    // cout << "a[" << i << "] = " << a[i] << endl;
                    break;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            for (int j = M-2; j >= 0; j--) {
                int sz = j+2;
                if (t.substr(M-sz)==(char)(i+'a')+t.substr(0,sz-1)) {
                    bb = sz-1;
                    // cout << "b[" << i << "] = " << b[i] << endl;
                    break;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            char c = (char)(i+'a');
            for (int j = 0; j < M; j++) {
                for (int k = j+1; k >= 1; k--) {
                    // cout << "t.substr(" << j-k+1 << "," << k-1 << ") = " << t.substr(j-k+1,k-1)+c << endl;
                    // cout << "t.substr(0," << k << ") = " << t.substr(0,k) << endl;
                    if (t.substr(j-k+1,k-1)+c==t.substr(0,k)) {
                        a[i][j] = k;
                        // cout << "a[" << i << "][" << j << "] = " << a[i][j] << endl;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            char c = (char)(i+'a');
            for (int j = 0; j < M; j++) {
                for (int k = j+1; k >= 1; k--) {
                    // cout << "t.substr(" << M-k+1 << "," << k-1 << ") = " << c+t.substr(M-k+1,k-1) << endl;
                    // cout << "t.substr(M-" << k << ") = " << t.substr(M-k) << endl;
                    if (c+t.substr(M-j,k-1)==t.substr(M-k)) {
                        b[i][j] = k;
                        // cout << "b[" << i << "][" << j << "] = " << b[i][j] << endl;
                        break;
                    }
                }
            }
        }
        dp[N][0][0] = 0;
        for (int i = N-1; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                for (int k = 0; k < M; k++) {
                    char c = s[i];
                    if (dp[i+1][j][k] != -1) {
                        bool good = 0;
                        if (t[j]==c) {
                            if (j!=M-1) dp[i][j+1][k] = max(dp[i][j+1][k],dp[i+1][j][k]);
                            else {
                                dp[i][aa][k] = max(dp[i][aa][k],dp[i+1][j][k]+1);
                                dp[i][0][k] = max(dp[i][0][k],dp[i+1][j][k]+1);
                            }
                            // dp[i][(j+1)%M][k] = max(dp[i][(j+1)%M][k],dp[i+1][j][k]+(j==M-1));
                            good = 1;
                        }
                        if (t[M-1-k]==c) {
                            if (k!=M-1) dp[i][j][k+1] = max(dp[i][j][k+1],dp[i+1][j][k]);
                            else {
                                dp[i][j][bb] = max(dp[i][j][bb],dp[i+1][j][k]+1);
                                dp[i][j][0] = max(dp[i][j][0],dp[i+1][j][k]+1);
                            }
                            // dp[i][j][(k+1)%M] = max(dp[i][j][(k+1)%M],dp[i+1][j][k]+(k==M-1));
                            good = 1;
                        }
                        if (!good) {
                            dp[i][a[c-'a'][j]][k] = max(dp[i][a[c-'a'][j]][k],dp[i+1][j][k]);
                            dp[i][j][b[c-'a'][k]] = max(dp[i][j][b[c-'a'][k]],dp[i+1][j][k]);
                        }
                    }
                }
            }
        }
        // cout << "dp" << endl;
        // for (int i = 0; i <= N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         for (int k = 0; k < M; k++) {
        //             cout << dp[i][j][k] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        int ans = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                // cout << "dp[0][" << i << "][" << j << "] = " << dp[0][i][j] << endl;
                ans = max(ans,dp[0][i][j]+(i+j==M));
            }
        }
        cout << ans << endl;
    }
    return 0;
}