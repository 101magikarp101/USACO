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

int N;
int a[102];
deque<int> b[102][102];
int dp[102][102];

int main () {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        dp[i][0] = 0;
        if (i == 0) {
            dp[i][1] = (a[i] == 0 ? 0 : 1);
        } else {
            dp[i][1] = dp[i-1][1] + (a[i] == i ? 0 : 1);
        }
    }
    for (int j = 2; j <= N; j++) {
        for (int i = j-1; i < N; i++) {
            if (i == j-1) {
                b[i][j] = deque<int>();
            } else {
                b[i][j] = b[i-1][j];
            }
            b[i][j].push_front(dp[i-1][j-1]);
            int mn = INT_MAX;
            for (int k = 0; k < b[i][j].size(); k++) {
                if (k!=a[i]) {
                    b[i][j][k]++;
                }
                mn = min(mn, b[i][j][k]);
            }
            // cout << "i: " << i << " j: " << j << " b[i][j]: " << endl;
            // for (int k = 0; k < b[i][j].size(); k++) {
            //     cout << b[i][j][k] << " ";
            // }
            // cout << endl;
            dp[i][j] = mn;
        }
    }
    for (int j = 1; j <= N; j++) {
        cout << dp[N-1][j] << endl;
    }
}