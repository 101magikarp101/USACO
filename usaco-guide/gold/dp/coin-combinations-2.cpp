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

int N, X;
int a[102];
int dp[105][1000005];

int main() {
    cin >> N >> X;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= X; j++) {
            dp[i][j] = dp[i-1][j];
            int left = j-a[i];
            if (left >= 0) {
                dp[i][j] += dp[i][left];
                dp[i][j] %= MOD2;
            }
        }
    }
    cout << dp[N][X] << endl;
}