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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int T, N, M, K;
vt<vt<int>> grid;
vt<vt<int>> pre, d1, d2; // pre is prefix sum, d1 is diagonal from top left to bottom right, d2 is diagonal from bottom left to top right
vt<vt<int>> dp;

bool good(int i, int j) {
    return (i >= 1 && i <= N && j >= 1 && j <= M);
}

int rect(int i1, int j1, int i2, int j2) {
    i2 = min(i2, N);
    j2 = min(j2, M);
    i1 = max(i1, 1);
    j1 = max(j1, 1);
    int res = pre[i2][j2]-pre[i1-1][j2]-pre[i2][j1-1]+pre[i1-1][j1-1];
    return res;
}

int getd1(int i, int j, int k) {
    int res = 0;
    if (i > N || j > M) {
        int hmm = max(i-N, j-M);
        if (good(i-hmm, j-hmm)) res += d1[i-hmm][j-hmm];
    } else {
        res += d1[i][j];
    }
    if (good(i-k-1, j-k-1)) res-=d1[i-k-1][j-k-1];
    return res;
}

int getd2(int i, int j, int k) {
    int res = 0;
    if (i > N || j < 1) {
        int hmm = max(i-N, 1-j);
        if (good(i-hmm, j+hmm)) res += d2[i-hmm][j+hmm];
    } else {
        res += d2[i][j];
    }
    if (good(i-k-1, j+k+1)) res-=d2[i-k-1][j+k+1];
    return res;
}

int main () {
    cin >> T;
    while (T--) {
        cin >> N >> M >> K;
        grid.clear();
        grid.resize(N+2, vt<int>(M+2, 0));
        pre.clear();
        pre.resize(N+2, vt<int>(M+2, 0));
        d1.clear();
        d1.resize(N+2, vt<int>(M+2, 0));
        d2.clear();
        d2.resize(N+2, vt<int>(M+2, 0));
        dp.clear();
        dp.resize(N+2, vt<int>(M+2, 0));
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < M; j++) {
                grid[i][j+1] = (s[j]=='#'?1:0);
            }
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++){
                pre[i][j]=grid[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
                d1[i][j]=grid[i][j]+d1[i-1][j-1];
                d2[i][j]=grid[i][j]+d2[i-1][j+1];
            }
        }
        int ans = 0;
        //aim top right
        for (int i = 1; i <= N; i++) {
            dp[i][1]=dp[i-1][1]+rect(i, 1, i, 1+K)-getd1(i-1, 1+K, K);
            ans = max(ans, dp[i][1]);
            for (int j = 2; j <= M; j++) {
                dp[i][j]=dp[i][j-1]+getd1(i, j+K, K)-rect(i-K, j-1, i, j-1);
                ans = max(ans, dp[i][j]);
            }
        }
        dp.clear();
        dp.resize(N+2, vt<int>(M+2, 0));
        //aim bottom right
        for (int i = N; i >= 1; i--) {
            dp[i][M]=dp[i+1][M]+rect(i, M, i, M+K)-getd2(i+K+1, M, K);
            ans = max(ans, dp[i][M]);
            for (int j = M-1; j >= 1; j--) {
                dp[i][j]=dp[i][j+1]-getd2(i+K, j+1, K)+rect(i, j, i+K, j);
                ans = max(ans, dp[i][j]);
            }
        }
        dp.clear();
        dp.resize(N+2, vt<int>(M+2, 0));
        //aim bottom left
        for (int i = N; i >= 1; i--) {
            dp[i][1]=dp[i+1][1]+rect(i, 1-K, i, 1)-getd1(i+K+1, 1, K);
            ans = max(ans, dp[i][1]);
            for (int j = 2; j <= M; j++) {
                dp[i][j]=dp[i][j-1]-getd1(i+K, j-1, K)+rect(i, j, i+K, j);
                ans = max(ans, dp[i][j]);
            }
        }
        dp.clear();
        dp.resize(N+2, vt<int>(M+2, 0));
        //aim top left
        for (int i = 1; i <= N; i++) {
            dp[i][1]=dp[i-1][1]+rect(i, 1-K, i, 1)-getd2(i-1, 1-K, K);
            ans = max(ans, dp[i][1]);
            for (int j = 2; j <= M; j++) {
                dp[i][j]=dp[i][j-1]-getd2(i, j-1-K, K)+rect(i-K, j, i, j);
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
    }
}