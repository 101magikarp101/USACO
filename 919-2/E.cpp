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

using namespace std;
#define ll long long
#define MOD 998244353
#define MOD2 1000000007
#define vt vector
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N, K;
ll dp[2501][2501];

ll add(ll a, ll b) {
    return (a+b)%MOD;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> K;
        for (int i = 0; i <= N; i++) {
            fill(dp[i], dp[i]+K+1, 0);
        }
        fill(dp[0], dp[0]+K+1, 1);
        ll ans = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                for (int k = 1; k <= K-j+1 && k*j <= i; k++) {
                    dp[i][j] = add(dp[i][j], dp[i-k*j][k]);
                }
            }
        }
        for (int i = 1; i <= K; i++) {
            ans = add(ans, dp[N][i]);
        }
        cout << ans << endl;
    }
}