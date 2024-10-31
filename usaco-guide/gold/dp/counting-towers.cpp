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

ll T, N;
ll dp[1000005][2];

int main() {
    cin >> T;
    while (T--) {
        cin >> N;
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= N; i++) {
            dp[i][0] = (dp[i-1][0] * 4 + dp[i-1][1]) % MOD2;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 2) % MOD2;
        }
        cout << (dp[N][0] + dp[N][1]) % MOD2 << endl;
    }
}