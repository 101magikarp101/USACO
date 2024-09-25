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
char a[1005][1005];
ll dp[1005][1005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            a[i][j] = s[j];
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    if (a[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[i][j] == '*') continue;
            if (i > 0) {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= MOD2;
            }
            if (j > 0) {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD2;
            }
        }
    }
    cout << dp[N-1][N-1] << endl;
}