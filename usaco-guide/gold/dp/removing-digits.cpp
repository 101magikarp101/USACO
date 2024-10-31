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

int N;
int dp[1000002];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        dp[i] = INT_MAX;
    }
    dp[N] = 0;
    for (int i = N; i >= 0; i--) {
        if (dp[i] == INT_MAX) continue;
        int x = i;
        while (x > 0) {
            int d = x % 10;
            if (i - d >= 0) {
                dp[i-d] = min(dp[i-d], dp[i] + 1);
            }
            x /= 10;
        }
    }
    cout << dp[0] << endl;
}