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

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int N, K;
int arr[100005];
int dp[100005][21][3]; //pos, changes, move

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'H') {
            arr[i] = 0;
        } else if (c == 'P') {
            arr[i] = 1;
        } else {
            arr[i] = 2;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = INT_MIN;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= min(K, i); j++) {
            for (int k = 0; k < 3; k++) {
                if (i == 0) {
                    dp[i][j][k] = (arr[i] == k);
                } else {
                    if (j == 0) {
                        dp[i][j][k] = dp[i-1][j][k] + (arr[i] == k);
                    } else {
                        if (j != i) {
                            dp[i][j][k] = dp[i-1][j][k] + (arr[i] == k);
                        }
                        for (int l = 0; l < 3; l++) {
                            if (l != k) {
                                dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][l] + (arr[i] == k));
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j < 3; j++) {
            ans = max(ans, dp[N-1][i][j]);
        }
    }
    cout << ans << endl;
}