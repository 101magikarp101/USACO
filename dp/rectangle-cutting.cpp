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

int a, b;
int dp[505][505];

int main() {
    cin >> a >> b;
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= 500; i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
            }
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            }
        }
    }
    cout << dp[a][b] << endl;
}