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

string n, m;
int dp[5005][5005];

int main() {
    cin >> n >> m;
    for (int i = 0; i <= n.size(); i++) {
        for (int j = 0; j <= m.size(); j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i <= n.size(); i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m.size(); i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n.size(); i++) {
        for (int j = 1; j <= m.size(); j++) {
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (n[i-1] != m[j-1]));
        }
    }
    cout << dp[n.size()][m.size()] << endl;
}