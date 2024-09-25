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

int T, N;
int arr[200005];
int dp[200005][2];

int main () {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 1; j <= N; j++) {
            cin >> arr[j];
        }
        for (int j = 0; j <= N; j++) {
            dp[j][0] = INT_MAX;
            dp[j][1] = INT_MAX;
        }
        //0->teammate, 1->you
        dp[0][1] = 0;
        for (int j = 1; j <= N; j++) {
            if (dp[j-1][1] != INT_MAX) {
                dp[j][0] = min(dp[j][0], dp[j-1][1] + arr[j]);
            }
            if (j>=2 && dp[j-2][1] != INT_MAX) {
                dp[j][0] = min(dp[j][0], dp[j-2][1] + arr[j-1] + arr[j]);
            }
            if (dp[j-1][0] != INT_MAX) {
                dp[j][1] = min(dp[j][1], dp[j-1][0]);
            }
            if (j>=2 && dp[j-2][0] != INT_MAX) {
                dp[j][1] = min(dp[j][1], dp[j-2][0]);
            }
            // cout << dp[j][0] << " " << dp[j][1] << endl;
        }
        cout << min(dp[N][0], dp[N][1]) << endl;
    }
}