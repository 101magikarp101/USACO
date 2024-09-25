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

ll N;
ll dp[125255];

int main() {
    cin >> N;
    ll tar = N * (N + 1) / 2;
    if (tar %2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    tar = tar / 2-1;
    dp[0] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = tar; j >= i; j--) {
            dp[j] += dp[j-i];
            dp[j] %= MOD2;
        }
    }
    cout << dp[tar] << endl;
}