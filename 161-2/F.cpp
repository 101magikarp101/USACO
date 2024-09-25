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
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

int T, N, X;
int a[104];
int dp[104][104][104];
bool has[104][104][104];

int main() {
    cin >> T;
    while (T--) {
        cin >> N >> X;
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
        for (int l = 0; l < N; l++) {
            for (int i = 0; i+l < N; i++) {
                for (int k = 1; k <= X; k++) {
                    has[i][i+l][k] = false;
                    dp[i][i+l][k] = INT_MAX;
                }
            }
        }
        for (int l = 0; l < N; l++) {
            for (int i = 0; i+l < N; i++) {
                if (l==0) {
                    for (int k = 1; k <= X; k++) {
                        if (a[i] == k) {
                            has[i][i][k] = true;
                        }
                        dp[i][i][k] = (a[i]==k?0:1);
                    }
                    continue;
                }
                for (int j = i; j < i+l; j++) {
                    for (int k = 1; k <= X; k++) {
                        if (has[j+1][i+l][k]||has[i][j][k]) {
                            has[i][i+l][k] = true;
                        }
                        if (!has[i][i+l][k]) {
                            dp[i][i+l][k] = 1;
                            continue;
                        }
                        dp[i][i+l][k] = min(dp[i][i+l][k], dp[i][j][k]+dp[j+1][i+l][k]);
                    }
                }
            }
        }
        cout << "dp: " << endl;
        for (int l = 0; l < N; l++) {
            for (int i = 0; i+l < N; i++) {
                for (int k = 1; k <= X; k++) {
                    cout << "i: " << i << " j: " << i+l << " k: " << k << " dp: " << dp[i][i+l][k] << endl;
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= X; i++) {
            if (has[0][N-1][i]) {
                ans = min(ans, dp[0][N-1][i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}