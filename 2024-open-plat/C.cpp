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
#include <deque>
#include <climits>
#include <unordered_set>

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
struct pii {int x, y;};
struct pll {int x, y;};

struct state {
    ll t, d;
};

ll L, R, N, K;
int arr[100005];
vt<vt<ll>> dp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> R >> N >> K;
    dp = vt<vt<ll>>(1<<R, vt<ll>(R, LLONG_MAX));
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int m = 0; m < (1<<R); m++) {
        dp[m] = LLONG_MAX;
    }
    dp[0] = 0;
    for (int m = 1; m < (1<<R); m++) {
        for (int i = 0; i < R; i++) {
            if (m&(1<<i)) {
                dp[m] = max(dp[m], dp[m^(1<<i)]+a[i]);
            }
        }
    }
    return 0;
}