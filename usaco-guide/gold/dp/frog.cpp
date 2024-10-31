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
#define INT_MAX 2147483647

using namespace std;

int N;
ll h[100005];
ll dp[100005];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= N; i++) {
        dp[i] = LLONG_MAX;
    }
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        dp[i] = min(dp[i], dp[i-1] + abs(h[i] - h[i-1]));
        if (i > 2) {
            dp[i] = min(dp[i], dp[i-2] + abs(h[i] - h[i-2]));
        }
    }
    cout << dp[N] << endl;
}