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

int N, M;
int a[100005];

int dx[] = {-1, 0, 1};

ll calc(ll l, ll r) {
    if (l == 0 && r == N+1) {
        vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
        for (int i = 1; i <= M; i++) {
            dp[1][i] = 1;
        }
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                for (int k = 0; k < 3; k++) {
                    int x = j + dx[k];
                    if (x >= 1 && x <= M) {
                        dp[i][j] += dp[i-1][x];
                        dp[i][j] %= MOD2;
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= M; i++) {
            ans += dp[N][i];
            ans %= MOD2;
        }
        return ans;
    }
    if (l == 0 || r == N+1) {
        int d = r - l;
        vector<vector<ll>> dp(d+1, vector<ll>(M+1, 0));
        if (l == 0) {
            dp[0][a[r]] = 1;
        } else if (r == N+1) {
            dp[0][a[l]] = 1;
        }
        for (int i = 1; i < d; i++) {
            for (int j = 1; j <= M; j++) {
                for (int k = 0; k < 3; k++) {
                    int x = j + dx[k];
                    if (x >= 1 && x <= M) {
                        dp[i][j] += dp[i-1][x];
                        dp[i][j] %= MOD2;
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 1; i <= M; i++) {
            ans += dp[d-1][i];
            ans %= MOD2;
        }
        return ans;
    } else {
        int d = r - l;
        vector<vector<ll>> dp(d+1, vector<ll>(M+1, 0));
        dp[0][a[l]] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = 1; j <= M; j++) {
                for (int k = 0; k < 3; k++) {
                    int x = j + dx[k];
                    if (x >= 1 && x <= M) {
                        dp[i][j] += dp[i-1][x];
                        dp[i][j] %= MOD2;
                    }
                }
            }
        }
        // cout << "l = " << l << " r = " << r << endl;
        // cout << "ans = " << dp[d][a[r]] << endl;
        return dp[d][a[r]];
    }
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    int l = -1, r = -1;
    ll ans = 1;
    for (int i = 1; i <= N; i++) {
        if (i >= 2) {
            if (a[i]!=0 && a[i-1]!=0 && abs(a[i] - a[i-1]) > 1) {
                cout << 0 << endl;
                return 0;
            }
        }
        if (a[i] != 0) {
            if (l != -1 && r != -1) {
                ans *= calc(l-1, r+1);
                ans %= MOD2;
            }
            l = r = -1;
        } else {
            if (l == -1) {
                l = i;
            }
            r = i;
        }
    }
    if (l != -1 && r != -1) {
        ans *= calc(l-1, r+1);
        ans %= MOD2;
    }
    cout << ans << endl;
}