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
#define pll pair<ll, ll>
#define pii pair<int, int>
#define MOD 998244353
#define MOD2 1000000007

ll N, M, K;
string s;
ll a[26][26];
ll pre[26][100003];
ll dp[100003][26];

void update(int tar, int src, ll k) {
    for (int i = 0; i < M; i++) {
        if (a[src][i]+k < a[tar][i]) {
            a[tar][i] = a[src][i]+k;
            update(tar, i, a[tar][i]);
        }
    }
}

int main () {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    cin >> N >> M >> K;
    cin >> s;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (i != j) {
                update(i, j, a[i][j]);
            }
        }
    }
    // cout << "a: " << endl;
    // for (int i = 0; i < M; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < s.length(); j++) {
            if (j == 0) {
                pre[i][j] = a[s[j]-'a'][i];
            } else {
                pre[i][j] = pre[i][j-1] + a[s[j]-'a'][i];
            }
        }
        // cout << "i: " << i << " pre[i]: ";
        // for (int j = 0; j < s.length(); j++) {
        //     cout << pre[i][j] << " ";
        // }
        // cout << endl;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = K-1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == K-1) {
                dp[i][j] = pre[j][i];
            } else {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + a[s[i]-'a'][j]);
                for (int k = 0; k < M; k++) {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], dp[i-K][k] + pre[j][i] - pre[j][i-K]);
                    }
                }
            }
        }
        // cout << "i: " << i << " dp[i]: ";
        // for (int j = 0; j < M; j++) {
        //     cout << dp[i][j] << " ";
        // }
        // cout << endl;
    }
    ll ans = INT_MAX;
    for (int i = 0; i < M; i++) {
        ans = min(ans, dp[N-1][i]);
    }
    cout << ans << endl;
}