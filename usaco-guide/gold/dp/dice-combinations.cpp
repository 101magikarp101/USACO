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

int N;
ll dp[1000005];

int main () {
    cin >> N;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = 0;
        for (int j = 1; j <= 6; j++) {
            if (i-j >= 0) {
                dp[i] += dp[i-j];
                dp[i] %= MOD2;
            }
        }
    }
    cout << dp[N] << endl;
}