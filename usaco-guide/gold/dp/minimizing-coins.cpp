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

#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define LLONG_MAX 9223372036854775807
#define MOD 998244353
#define MOD2 1000000007
#define INT_MAX 2147483647

using namespace std;

int N, X;
int dp[1000005];
int a[105];

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= X; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            if (i - a[j] >= 0 && dp[i-a[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-a[j]] + 1);
            }
        }
    }
    if (dp[X] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[X] << endl;
    }
}