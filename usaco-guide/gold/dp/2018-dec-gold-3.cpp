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

int N, K;
int arr[10003];
int dp[10003][1003];
int best[1003];

int main() {
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    dp[0][1] = arr[0];
    for (int i = 0; i < N; i++) {
        int res = INT_MIN;
        int mx = arr[i];
        for (int j = 1; j <= min(i+1, K); j++) {
            if (i-j >= 0) {
                mx = max(mx, arr[i-j+1]);
            }
            int tmp = j*mx;
            if (i-j >= 0) {
                tmp += best[i-j];
            }
            // cout << "i: " << i << " j: " << j << " tmp: " << tmp << endl;
            res = max(res, tmp);
        }
        best[i] = res;
        // cout << "i: " << i << " best[i]: " << best[i] << endl;
    }
    cout << best[N-1] << endl;
}