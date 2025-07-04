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
int a[200002];
ll dp[2][200002];
ll b00[200002];
ll b01[200002];
ll b10[200002]; 
ll b11[200002];

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mult(ll a, ll b) {
    return (a * b) % MOD;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        a[i] %= 2;
    }
    dp[0][0] = 0;
    dp[1][0] = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] == 0) {
            dp[0][i] = dp[0][i - 1] + 1;
            dp[1][i] = dp[1][i - 1];
        } else {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1] + 1;
        }
    }
    b00[0] = 0;
    b01[0] = 0;
    b10[0] = 0;
    b11[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (a[i] == 0) {
            b00[i] = dp[0][i]*(dp[0][i] - 1)/2 % MOD;
            b10[i]
        } else {
            b00[i] = b00[i - 1];
            b01[i] = b01[i - 1] + 1;
            b10[i] = b10[i - 1] + 1;
            b11[i] = b11[i - 1];
        }
    }
}