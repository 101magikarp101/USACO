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

int N, M, K;
ll MO = 1e9+9;
ll a[1002], b[1002];
ll dp[11][1002][1002];
ll pre[11][1002][1002]; //2d prefix sum

ll add(ll a, ll b) {
    return (a+b)%MO;
}

ll sub(ll a, ll b) {
    return (a-b+MO)%MO;
}

ll mult(ll a, ll b) {
    return (a*b)%MO;
}

int main() {
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    sort(a, a+N, greater<ll>());
    sort(b, b+M, greater<ll>());
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            dp[1][i][j] = (b[i] < a[j]);
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            pre[1][i][j] = dp[1][i][j];
            if (i > 0) {
                pre[1][i][j] = add(pre[1][i][j], pre[1][i-1][j]);
            }
            if (j > 0) {
                pre[1][i][j] = add(pre[1][i][j], pre[1][i][j-1]);
            }
            if (i > 0 && j > 0) {
                pre[1][i][j] = sub(pre[1][i][j], pre[1][i-1][j-1]);
            }
        }
    }
    for (int k = 2; k <= K; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[1][i][j] != 1) continue;
                if (i == 0 || j == 0) {
                    dp[k][i][j] = 0;
                } else {
                    dp[k][i][j] = pre[k-1][i-1][j-1];
                }
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                pre[k][i][j] = dp[k][i][j];
                if (i > 0) {
                    pre[k][i][j] = add(pre[k][i][j], pre[k][i-1][j]);
                }
                if (j > 0) {
                    pre[k][i][j] = add(pre[k][i][j], pre[k][i][j-1]);
                }
                if (i > 0 && j > 0) {
                    pre[k][i][j] = sub(pre[k][i][j], pre[k][i-1][j-1]);
                }
            }
        }
    }
    cout << pre[K][M-1][N-1] << endl;
}