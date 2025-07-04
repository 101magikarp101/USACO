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

int N, M, C;
int m[1003];
vector<int> adj[1003];
int dp[1003][502]; //pos, time

int main () {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 500; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    dp[1][0] = 0;
    for (int t = 0; t <= 500; t++) {
        for (int i = 1; i <= N; i++) {
            if (dp[i][t] != INT_MIN) {
                // cout << "i: " << i << " t: " << t << " dp[i][t]: " << dp[i][t] << endl;
                if (i == 1) {
                    ans = max(ans, dp[i][t] - C*t*t);
                }
                for (int j = 0; j < adj[i].size(); j++) {
                    int k = adj[i][j];
                    dp[k][t+1] = max(dp[k][t+1], dp[i][t] + m[k]);
                }
            }
        }
    }
    cout << ans << endl;
}